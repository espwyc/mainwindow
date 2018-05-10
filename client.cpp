#include <string>
#include <iostream>
#include <boost/bind/bind.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/thread/thread.hpp>
#include "client.h"

#pragma execution_character_set("utf-8")

void start() {}

Client::Client(IoService& t_ioService, TcpResolverIterator t_endpointIterator, 
    std::string const& t_path, std::string startTime, std::string endTime, std::string pictureID, class con2thread *con, std::string errorCode, std::string zipCode)
    : m_ioService(t_ioService), m_socket(t_ioService), 
    m_endpointIterator(t_endpointIterator), m_path(t_path)
{
	this->startTime = startTime;
	this->endTime = endTime;
	this->pictureID = pictureID;
	this->con_class = con;
	this->errorCode = errorCode;
	this->zipCode = zipCode;
    openFile(m_path);
	doConnect();
	boost::thread thrd(start);
}


void Client::openFile(std::string const& t_path)
{
	//打开文件
    m_sourceFile.open(t_path, std::ios_base::binary | std::ios_base::ate);
	if (m_sourceFile.fail()) {
		//std::cout << "Failed while opening file " + t_path << std::endl;
		//-emit sendmsgf(QString::fromStdString("Failed while opening file " + t_path));
		bactxt = QString::fromStdString("Failed while opening file " + t_path);
		con_class->sendmsgback(bactxt);
	}
        
    //文件指针移至末尾确定文件大小
    m_sourceFile.seekg(0, m_sourceFile.end);
    auto fileSize = m_sourceFile.tellg();
    m_sourceFile.seekg(0, m_sourceFile.beg);

	//使用输出流将数据写入streambuf
    std::ostream requestStream(&m_request);
    boost::filesystem::path p(t_path);
	//-std::cout << "p.filename: " << p.filename().string() << p.string() << std::endl;
	//-emit sendmsgf(QString::fromStdString("p.filename: " + p.filename().string()+ p.string()));
	bactxt = QString::fromStdString("p.filename: " + p.filename().string() + p.string());
	con_class->sendmsgback(bactxt);
	requestStream << p.filename().string() << "\n" << fileSize << "\n" << startTime << 
		"\n" << endTime << "\n" << pictureID << "\n" << errorCode << "\n" << zipCode << "\n\n";
    //-std::cout << "Request size: " << m_request.size() << std::endl;
	//-emit sendmsgf(QString::fromStdString("Request size: " + m_request.size()));
	bactxt = QString::fromStdString("Request size: " + m_request.size());
	con_class->sendmsgback(bactxt);
}


void Client::doConnect()
{
    boost::asio::async_connect(m_socket, m_endpointIterator, 
        [this](boost::system::error_code ec, TcpResolverIterator)
        {
            if (!ec) {
                writeBuffer(m_request);	//发送m_request中的内容
            } else {
               //- std::cout << "Coudn't connect to host. Please run server "
                    //"or check network connection.\n";
				//-std::cout << "Error: " << ec.message() << std::endl;
					emit sendmsgf(QString::fromStdString("Coudn't connect to host. Please run server or check network connection.\nError: " + ec.message()));
					bactxt = QString::fromStdString("Coudn't connect to host. Please run server or check network connection.\nError: " + ec.message());
					con_class->sendmsgback(bactxt);
			}
        });
}


void Client::doWriteFile(const boost::system::error_code& t_ec)
{
    if (!t_ec) {
        if (m_sourceFile) {
            m_sourceFile.read(m_buf.data(), m_buf.size());	//读取文件内容 
            if (m_sourceFile.fail() && !m_sourceFile.eof()) {
                auto msg = "Failed while reading file";
                //-std::cout << msg << std::endl;
                //-throw std::fstream::failure(msg);
				//-emit sendmsgf(QString::fromStdString(msg));
				bactxt = QString::fromStdString(msg);
				con_class->sendmsgback(bactxt);
            }
            std::stringstream ss;
            ss << "Send " << m_sourceFile.gcount() << " bytes, total: "
                << m_sourceFile.tellg() << " bytes" ;
            //-std::cout << ss.str() << std::endl;
			//-emit sendmsgf(QString::fromStdString(ss.str()));
            
			con_class->sendmsgback(QString::fromStdString(ss.str()));
			auto buf = boost::asio::buffer(m_buf.data(), static_cast<size_t>(m_sourceFile.gcount()));
            writeBuffer(buf);	//发送buf中的内容
		}
		else {
			//发送完成位置
			m_sourceFile.close();
			//-std::cout << "send file completed." << std::endl;
			//emit sendmsgf(QString::fromStdString("send file completed."));
			con_class->sendmsgback(QString::fromStdString("send file completed."));
			//开始接收服务器的返回信息
			doRead();
		}
    } else {
       //- std::cout << "Error: " << t_ec.message() << std::endl;
		//-emit sendmsgf(QString::fromStdString("Error: "+ t_ec.message()));
		con_class->sendmsgback(QString::fromStdString("Error: " + t_ec.message()));
    }
}

void Client::doRead()
{
	//此处设置当前工作目录
	//auto currentPath = boost::filesystem::path("C:/hereisproblem");/*---!!!--*/
	/*QMessageBox msg;
	msg.setText(QString::fromStdString(CSPATH + RCVPICLIBPATH));
	msg.exec();*/
	//auto currentPath = boost::filesystem::path((CQPATH+ RCVPICLIBPATH).toStdString());//存图片路径
	//auto currentPath = boost::filesystem::path("C:/test/mainwindown/mainwindow/mainwindow/rcvpicture_lib");
	//-current_path(currentPath);/*---!!!--*/
	//读取直到'\n\n'的字符串信息
	async_read_until(m_socket, m_requestBuf_, "\n\n",
		[this](boost::system::error_code ec, size_t bytes)
	{
		if (!ec)
			processRead(bytes);
		else
			handleError(__FUNCTION__, ec);
	});
}

void Client::processRead(size_t t_bytesTransferred)
{
	/*std::cout << __FUNCTION__ << "(" << t_bytesTransferred << ")"
	<< ", in_avail = " << m_requestBuf_.in_avail() << ", size = "
	<< m_requestBuf_.size() << ", max_size = " << m_requestBuf_.max_size() << "." << std::endl;*/
	//---emit sendmsgf(QString::fromStdString(__FUNCTION__ +"(" + t_bytesTransferred+ ", in_avail = "+ m_requestBuf_.in_avail()+ ", size = "+ m_requestBuf_.size()+ ", max_size = "+ m_requestBuf_.max_size()+ "."));
	bactxt = QString::fromStdString("(") + QString::number(t_bytesTransferred, 10) + QString::fromStdString(")") + QString::fromStdString(", in_avail = ") + m_requestBuf_.in_avail() + QString::fromStdString(", size = ");
	bactxt+= QString::number(m_requestBuf_.size()) + QString::fromStdString(", max_size = ") + m_requestBuf_.max_size() + QString::fromStdString("." );
	con_class->sendmsgback(bactxt);
	//将m_requestBuf_中的内容写入输入流中
	std::istream requestStream(&m_requestBuf_);
	readData(requestStream);

	auto pos = m_fileName.find_last_of('\\');
	if (pos != std::string::npos)
		m_fileName = m_fileName.substr(pos + 1);

	createFile();

	// write extra bytes to file
	do {
		requestStream.read(m_bufforRecv.data(), m_bufforRecv.size());
		//-std::cout << __FUNCTION__ << " write " << requestStream.gcount() << " bytes." << std::endl;
		bactxt = QString::fromStdString(__FUNCTION__) + " write " + requestStream.gcount() + " bytes.";
		//std::string s = __FUNCTION__ + " write " + requestStream.gcount() + " bytes.";
		con_class->sendmsgback(bactxt);
		m_outputFile.write(m_bufforRecv.data(), requestStream.gcount());
		//-std::cout << "extra data: " << m_bufforRecv.data() << " count: " << requestStream.gcount() << std::endl;
		bactxt = "extra data: " + QString::fromStdString(m_bufforRecv.data()) + " count: " + requestStream.gcount();
		con_class->sendmsgback(bactxt);
	} while (requestStream.gcount() > 0);

	//同步接收文件
	while (true) {
		//文件指针超过文件大小则接收完毕/*-----receive---*/
		if (m_outputFile.tellp() >= static_cast<std::streamsize>(m_fileSize)) {
			m_outputFile.close();
			//-std::cout << "接收完成" << std::endl;
			bactxt = "接收完成";
			con_class->sendmsgback(bactxt);	
			struct QuerryResultStruct rs;
			rs.pic_path = QString::fromStdString(m_fileName);
			rs.addr = QString::fromStdString(resultPos);
			rs.pic_id = QString::fromStdString(resultID).toInt();
			rs.b_t = QDateTime::fromString(QString::fromStdString(appearTime), "yyyy-MM-dd-hh:mm:ss");
			rs.e_t = QDateTime::fromString(QString::fromStdString(disappearTime), "yyyy-MM-dd-hh:mm:ss");
			rs.errorCode = QString::fromStdString(errorCode);
			rs.zipcode = QString::fromStdString(recvZipCode);
			rs.picsimilarity = QString::fromStdString(picSimilarity);
			con_class->recvpic_fin(rs);
			//con_class->recvpic_fin();
			/*-std::cout << "\nfilename: " << m_fileName << " fileSize: " << m_fileSize <<
				"\nresultPos: " << resultPos << "\nresultTime: " << appearTime << "\nresultID: " << resultID << std::endl;*/
			bactxt = "\nfilename: "+ QString::fromStdString(m_fileName)+ " fileSize: "+QString::number(m_fileSize,10);
			bactxt += "\nresultPos: " + QString::fromStdString(resultPos) + "\nresultTime: " + QString::fromStdString(appearTime) + "\nresultID: " + QString::fromStdString(resultID);
			con_class->sendmsgback(bactxt);
			//con_class->recvpic_fin(bactxt);
			break;
		}
		/***************************************************/
		boost::system::error_code ec;
		size_t len = m_socket.read_some(boost::asio::buffer(m_bufforRecv.data(), m_bufforRecv.size()), ec);
		if (ec) {
			//std::cout << boost::system::system_error(ec).what() << std::endl;
			bactxt = QString::fromStdString(boost::system::system_error(ec).what());
			con_class->sendmsgback(bactxt);
			break;
		}
		//写入文件
		m_outputFile.write(m_bufforRecv.data(), static_cast<std::streamsize>(len));

	}


	//异步接收文件
	/*m_socket.async_read_some(boost::asio::buffer(m_bufforRecv.data(), m_bufforRecv.size()),
		[this](boost::system::error_code ec, size_t bytes)
	{
		if (!ec) {
			std::cout << "start recving " << bytes <<std::endl;
			doReadFileContent(bytes);
		}
			
		else
			handleError(__FUNCTION__, ec);
	});*/
}

void Client::readData(std::istream &stream)
{
	//以'\n'为间隔读取字符串
	stream >> m_fileName;
	stream >> m_fileSize;
	stream >> resultPos;
	stream >> appearTime;
	stream >> disappearTime;
	stream >> resultID;
	stream >> errorCode;
	stream >> recvZipCode;
	stream >> picSimilarity;
	stream.read(m_bufforRecv.data(), 2);	//将最后的'\n\n'写入buf
	/*std::cout << m_fileName << " size is " << m_fileSize
	<< ", tellg = " << stream.tellg() << std::endl ;*/
	bactxt = QString::fromStdString(m_fileName) + " size is " + QString::number(m_fileSize,10);
	bactxt += ", tellg = " + stream.tellg();
	con_class->sendmsgback(bactxt);
}

void Client::createFile()
{/*--!!!!图片路径---*/
	std::string s =RCVPICLIBPATH+ m_fileName;
	m_outputFile.open(s, std::ios_base::binary);
	if (!m_outputFile) {
		//std::cout << __LINE__ << ": Failed to create: " << m_fileName << std::endl;
		bactxt = QString::number(__LINE__, 10) + ": Failed to create: " + QString::fromStdString(m_fileName);
		con_class->sendmsgback(bactxt);
		return;
	}
}

//异步接收的循环回调函数
void Client::doReadFileContent(size_t t_bytesTransferred)
{
	if (t_bytesTransferred > 0) {
		m_outputFile.write(m_bufforRecv.data(), static_cast<std::streamsize>(t_bytesTransferred));

		//-std::cout << __FUNCTION__ << " recv " << m_outputFile.tellp() << " bytes" << std::endl;
		bactxt = " recv " + m_outputFile.tellp();
		bactxt +=" bytes";
		con_class->sendmsgback(bactxt);
		if (m_outputFile.tellp() >= static_cast<std::streamsize>(m_fileSize)) {
			//接收完成位置
			m_outputFile.close();
			//std::cout << "Received file: " << m_fileName << " size: " << m_fileSize << m_data << std::endl;
			bactxt = "Received file: " + QString::fromStdString(m_fileName )+ " size: " +QString::number(m_fileSize, 10) + QString::fromStdString(m_data);
			con_class->sendmsgback(bactxt);
			return;
		}
	}
	
	m_socket.async_read_some(boost::asio::buffer(m_bufforRecv.data(), m_bufforRecv.size()),
		[this](boost::system::error_code ec, size_t bytes)
	{
		doReadFileContent(bytes);
	});
}

void Client::handleError(std::string const& t_functionName, boost::system::error_code const& t_ec)
{
	/*std::cout << __FUNCTION__ << " in " << t_functionName << " due to "
	<< t_ec << " " << t_ec.message() << std::endl*/
	
	bactxt=" in " + QString::fromStdString(t_functionName) + " due to 不好转换的原因反正窗体不用看到";
	con_class->sendmsgback(bactxt);

}
