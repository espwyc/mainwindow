#include "network_pannel.h"
#pragma execution_character_set("utf-8")

void start(std::string ip, std::string path, std::string startTIme, std::string endTime, std::string pictureID, class con2thread *con, std::string errorCode, std::string zipCode)
{

	boost::asio::io_service ioService;
	boost::asio::ip::tcp::resolver resolver(ioService);
	auto endpointIterator = resolver.resolve({ "ngrok.cloudserver.xin", ip });
	//auto endpointIterator = resolver.resolve({ ip, "11912" });
	Client client(ioService, endpointIterator, path, startTIme, endTime, pictureID, con,errorCode, zipCode);
	//connect(client,SIGNAL(r),,SLOT(s));
	//con->sendmsgback("test-finish");
	ioService.run();

}

void startSingleClient(std::vector<std::string> ipArr, std::string path, std::string startTime, std::string endTime, std::string pictureID, class con2thread *con, std::string errorCode, std::string zipCode)
{
	std::vector<boost::thread> threads;
	for (auto ip : ipArr) {
		threads.push_back(boost::thread(boost::bind(&start, ip, path, startTime.replace(10, 1, "-"), endTime.replace(10, 1, "-"), pictureID, con,errorCode, zipCode)));
	}
	for (auto& thread : threads) {
		thread.join();
	}
	con->sendmsgback("thread exit");
}
NetWork::NetWork(QWidget *parent)
	: QWidget(parent)
{
	//base = DB;
	c1 = new QCheckBox("boost客户端");
	c2 = new QCheckBox("boost服务器");
	c3 = new QCheckBox("ccccc");
	c4 = new QCheckBox("sssss");
	layout = new QGridLayout();
	txtb = new QTextBrowser();
	button = new QPushButton("启动");
	layout->addWidget(c1, 0, 0, 1, 1);
	layout->addWidget(c2, 0, 1, 1, 1);
	layout->addWidget(c3, 0, 2, 1, 1); 
	layout->addWidget(c4, 0, 3, 1, 1);
	layout->addWidget(txtb, 1, 0, 1, 4);
	layout->addWidget(button, 2, 0, 1, 4);
	this->setLayout(layout);
	this->resize(500, 500);
	con = new con2thread();
	//std::vector<std::string> ipArr;
	//ipArr.push_back("127.0.0.1");
	//-ipArr.push_back("192.168.31.131");
	//-ipArr.push_back("192.168.31.62");
/*槽*/
	connect(con, SIGNAL(mysig(const QString &)), this, SLOT(mytest(const QString &)));
	connect(con, SIGNAL(rcv_sig(const QString &)), this, SLOT(result_rcv(const QString &)));
	//-connect(con, SIGNAL(rcvpic_sig(struct QuerryResultStruct &)), this, SLOT(rcvpic_handler(struct QuerryResultStruct &)));
	//connect(con, SIGNAL(rcvpic_sig(struct QuerryResultStruct &)), this, SLOT(rcvpic_handler(struct QuerryResultStruct &)));
	connect(con, SIGNAL(rcvpic_sig(const QString &/*, const QString &, const int &, const QDateTime &, const QDateTime &*/)), this, SLOT(rcvpic_handler(const QString &/*, const QString &h, const int &, const QDateTime &, const QDateTime &*/)));
	connect(button, SIGNAL(clicked()), this, SLOT(actvi()));
/*槽end*/
}

NetWork::~NetWork()
{

}
void NetWork::actvi()/*弃用*/
{
	if (c1->isChecked())
	{
		c3->setChecked(false);
		c2->setChecked(false);
		c4->setChecked(false);
		/*std::vector<std::string> ipArr;
		ipArr.push_back("127.0.0.1");*/
		//-MultiClient multiClient(ipArr, "I:/test/test.txt", "2017-11-11 11:11:11", "2017-12-12 12:12:12", "233");
		//-startSingleClient(ipArr, "C:/test/test.txt", "2017-11-11 11:11:11", "2017-12-12 12:12:12", "233", con);
		QDateTime tmp = QDateTime::currentDateTime();
		QString tmp1 = tmp.toString("yyyy-MM-dd hh:mm:ss");
		/*弃用*/
		//startSingleClient(ipArr, "C:/test/mainwindown/mainwindow/mainwindow/picture_lib/20171222194104.jpg", tmp1.toStdString(), "2017-12-12 12:12:12", "233", con,"0");
		//system("pause");
/*弃用*/
/*弃用*/
	/**/
		flag = 0;
	}
	if (c2->isChecked())
	{
#ifdef SSMSG
		msg.setText("启动服务器");
		msg.exec();
#endif
		c3->setChecked(false);
		c1->setChecked(false);
		c4->setChecked(false);

	}
	if (c3->isChecked())
	{
		//client发
#ifdef SSMSG
		msg.setText("c3check未开发");
		msg.exec();
#endif
		c1->setChecked(false);
		c2->setChecked(false);
		c4->setChecked(false);
	}
	if (c4->isChecked())
	{
		//server收
#ifdef SSMSG
		msg.setText("c4check未开发");
		msg.exec();
#endif
		c1->setChecked(false);
		c2->setChecked(false);
		c3->setChecked(false);
	}
}
void NetWork::mytest(const QString &text)
{
	txtb->append(text);
}
void NetWork::result_rcv(const QString &text)//弃用
{///////弃用
	//弃用
//	flag = 1;
//	msg.setText("rcv:addr"+con->tmp.addr+"pic_id"+QString::number(con->tmp.pic_id,10)+"pic_path"+con->tmp.pic_path+"bt"+con->tmp.b_t.toString()+"et"+con->tmp.e_t.toString());
//	msg.exec();
//	QDateTime t = QDateTime::currentDateTime();
//	QString pic_name = t.toString("yyyyMMddhhmmss");
//	pic_name += ".jpg";
//	QFile::copy(RCVPICLIBPATH + text, RESULTPICLIBPATH + pic_name);//结果图片入库
// /*MySql_DB *db;
//																   db = new MySql_DB();
//																   db->save_querry_result(con->tmp, RESULTPICLIBPATH + pic_name);*/
//	if (base->connection_flag == true)
//	{
//		base->save_querry_result(con->tmp, RESULTPICLIBPATH + pic_name);
//	}
//	emit show_result_byid(QString::number(con->tmp.pic_id, 10));
}
void NetWork::SubmitQuerry(struct QuerryStruct &QS)
{
	std::vector<std::string> iparr = QS.ipArr;/*qtproject约定ipArr暂定只存放一个IP地址，由qt端控制客户端线程*/
	QDateTime bt = QS.b_t;
	QDateTime et = QS.e_t;
	QString bs = bt.toString("yyyy-MM-dd hh:mm:ss");
	QString es = et.toString("yyyy-MM-dd hh:mm:ss");
#ifdef SSMSG
	msg.setText("path:" + QS.pic_path);
	msg.exec();
#endif
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
///////////*client_thread = new QThread();
////////	singleclient *s_client = new singleclient(iparr, QS.pic_path.toStdString(), bs.toStdString(), es.toStdString(), (QString::number(QS.pic_id, 10)).toStdString(), con, "0");
////////	s_client->moveToThread(client_thread);*/
////////	//connect(&client_thread, SIGNAL(finished()), s_client, SLOT(deleteLater()));
////////	//QMetaObject::connect(&client_thread, &QThread::finished, s_client, &QObject::deleteLater);
////////	//connect(this, &Controller::operate, worker, &Worker::doWork);
////////	//connect(worker, &Worker::resultReady, this, &Controller::handleResults);
////////
////////	/*启用qt线程开启一次链接*/
////////	/*qtproject约定ipArr暂定只存放一个IP地址，由qt端控制客户端线程*/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
	Cthread_controller *ClientThreadContorler;
	for (auto &i : iparr)
	{
		ClientThreadContorler = new Cthread_controller(i, QS.pic_path.toStdString(), bs.toStdString(), es.toStdString(), (QString::number(QS.pic_id, 10)).toStdString(), con, QS.errorcode.toStdString(),i);
		connect(ClientThreadContorler,SIGNAL(rcv_ip(const QString &)),this,SLOT(rcv_ip_handler(const QString &)));
	}
	for (auto i : iparr)
	{
		QString tp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
		QString cmd = "update iptable set flag = 1, last_comit_time = str_to_date('"+tp+"', '%Y-%m-%d %H:%i:%s') where ip = '"+ QString::fromStdString(i) +"'; ";
		base->mysql_cmd(cmd.toStdString());
	}

}

void NetWork::rcvpic_handler(const QString &res_str/*, const QString &pic_path, const int &pid, const QDateTime &b_t, const QDateTime &e_t*/)/*┑(￣Д ￣)┍结构体莫名其妙发不过来，传递字符串切分*/
{
	struct QuerryResultStruct tmp_st;
	tmp_st.addr = res_str.section("|", 0, 0);
	tmp_st.pic_path = res_str.section("|", 1, 1);
	tmp_st.pic_id = res_str.section("|", 2, 2).toInt();
	tmp_st.b_t = QDateTime::fromString(res_str.section("|", 3, 3), "yyyy-MM-dd hh:mm:ss");
	tmp_st.e_t = QDateTime::fromString(res_str.section("|", 4, 4), "yyyy-MM-dd hh:mm:ss");
	tmp_st.errorCode = res_str.section("|", 5, 5);
	tmp_st.zipcode = res_str.section("|", 6, 6);
	tmp_st.picsimilarity= res_str.section("|", 7, 7);
	if (tmp_st.errorCode.toInt() == 0)
	{
#ifdef SSMSG
		msg.setText("loca" + tmp_st.addr + "path" + tmp_st.pic_path + "bt" + tmp_st.b_t.toString() + "et" + tmp_st.e_t.toString() + "erc" + tmp_st.errorCode+"zip"+tmp_st.zipcode);
		msg.exec();
#endif
		flag = 1;
		QDateTime t = QDateTime::currentDateTime();
		QString pic_name = t.toString("yyyyMMddhhmmss");
		pic_name += ".jpg";
		QFile::copy(RCVPICLIBPATH + tmp_st.pic_path, RESULTPICLIBPATH + pic_name);//结果图片入库
		if (base->connection_flag == true)
		{
			base->save_querry_result(tmp_st, RESULTPICLIBPATH + pic_name);
			QString tp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
			QString cmd = "update iptable set address = '" + tmp_st.addr + "' , last_result_time = str_to_date('" + tp + "', '%Y-%m-%d %H:%i:%s')  where ip='" + tmp_st.zipcode + "';";
			
			base->mysql_cmd(cmd.toStdString());
		}
		emit show_result_byid(QString::number(tmp_st.pic_id, 10));
	}
	else
	{
		/*纠错*/
#ifdef SSMSG
		msg.setText("loca" + tmp_st.addr + "path" + tmp_st.pic_path + "bt" + tmp_st.b_t.toString() + "et" + tmp_st.e_t.toString() + "erc" + tmp_st.errorCode);
		msg.exec();
#endif
		flag = 1;
		QDateTime t = QDateTime::currentDateTime();
		QString pic_name = t.toString("yyyyMMddhhmmss");
		pic_name += ".jpg";
		QFile::copy(RCVPICLIBPATH + tmp_st.pic_path, RESULTPICLIBPATH + pic_name);//结果图片入库
		if (base->connection_flag == true)
		{
			base->save_querry_result(tmp_st, RESULTPICLIBPATH + pic_name);
		}
		emit show_result_byid(QString::number(tmp_st.pic_id, 10));
	}
}
void NetWork::rcv_ip_handler(const QString &rcvip)
{
	QString cmd = "update iptable set flag = 0 where ip = '" + rcvip + "';";
	base->mysql_cmd(cmd.toStdString());
}
bool NetWork::DB_pass_pter(MySql_DB *DB)
{
	base = DB;
	return true;
} ;
singleclient::singleclient(std::string ip/*qtproject约定ipArr暂定只存放一个IP地址，由qt端控制客户端线程*/, std::string path_p, std::string startTime_p, std::string endTime_p, std::string pictureID_p, class con2thread *con_p, std::string errorCode_p,std::string zipcode_p)
{
	
	ipArr.push_back(ip);/*qtproject约定ipArr暂定只存放一个IP地址，由qt端控制客户端线程*/;
	path = path_p;
	startTime = startTime_p;
	endTime = endTime_p;
	pictureID = pictureID_p;
	con = con_p;
	errorCode = errorCode_p;
	zipcode = zipcode_p;
}
singleclient::~singleclient()
{
	/**/
}
void Cthread_controller::handleResults(const QString &rcv_ip)
{
	/**/
} 