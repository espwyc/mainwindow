#pragma once
#ifndef NETWORK_PANNEL_H
#define NETWORK_PANNEL_H

#pragma execution_character_set("utf-8")

#include <array>
#include <fstream> 
#include <boost/asio.hpp>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QTimeEdit>
#include <QDateEdit>
#include <QGroupBox>
#include <QMessageBox>
#include <QFileDialog>
//#include <QSizePolicy>
#include <QFile>
#include <QDateTime>
#include <QDate>
#include <QCheckBox>
#include <QTextBrowser>
#include <QThread>
#include <boost/thread/thread.hpp>
#include "client.h"
#include "struct_class_file.h"
#include "mysql_con.h"
//#include "MultiClient.h"
#include "con2thread.h"
//#include "server.h"
//#include "includes.h"
void start(std::string ip, std::string path, std::string startTIme, std::string endTime, std::string pictureID, class con2thread *con, std::string errorCode);
void startSingleClient(std::vector<std::string> ipArr, std::string path, std::string startTime, std::string endTime, std::string pictureID, class con2thread *con, std::string errorCode,std::string zipCode);

class NetWork : public QWidget
{
	Q_OBJECT

public:
	NetWork(QWidget *parent = 0);
	~NetWork();
	QMessageBox msg;
	con2thread *con;
	bool DB_pass_pter(MySql_DB *DB);
	int flag = -1;
private:
	QThread *client_thread;
	MySql_DB *base;
	QCheckBox *c1, *c2, *c3, *c4;
	QTextBrowser *txtb;
	QPushButton *button;
	QGridLayout *layout;
	std::vector<std::string> ipArr;
	private slots:
	void actvi();
	void mytest(const QString &text);
	void result_rcv(const QString &text);
	
	void rcvpic_handler(const QString &res_str/*, const QString &pic_path, const int &pid, const QDateTime &b_t, const QDateTime &e_t*/);
	void rcv_ip_handler(const QString &rcvip);
	public slots:
	//void rcvpic_handler(struct QuerryResultStruct &RS);
	void SubmitQuerry(struct QuerryStruct &QS);
signals:
	void show_result_byid(const QString &picid);
	//void rcvpic_handler(struct QuerryResultStruct &RS);
};
class singleclient : public QObject
{
	Q_OBJECT
public:
	singleclient(std::string ip, std::string path_p, std::string startTime_p, std::string endTime_p, std::string pictureID_p, class con2thread *con_p, std::string errorCode_p,std::string zipcode_p);
	~singleclient();
private :
	std::vector<std::string> ipArr;
	std::string path;
	std::string startTime; 
	std::string endTime; 
	std::string pictureID;
	class con2thread *con;
	std::string errorCode;
	std::string zipcode;
public slots:
	void do_StartSingleClient() {
		//QString result;
		/* ... here is the expensive or blocking operation ... */
		//con->sendmsgback("创建客户端");
		startSingleClient(ipArr/*qtproject约定ipArr暂定只存放一个IP地址，由qt端控制客户端线程*/, path, startTime, endTime, pictureID, con, errorCode,zipcode);
		QString rcv_ip;
		for (auto &i : ipArr/*qtproject约定ipArr暂定只存放一个IP地址，由qt端控制客户端线程*/)
		{
			rcv_ip = QString::fromStdString(i);
		}/*qtproject约定ipArr暂定只存放一个IP地址，由qt端控制客户端线程循环一次*/
		emit resultReady(rcv_ip);
	}

signals:
	void resultReady(const QString &);
};
class Cthread_controller :public QObject
{
	Q_OBJECT
private:
	QThread client_thread;
public:
	Cthread_controller(std::string ip, std::string path_p, std::string startTime_p, std::string endTime_p, std::string pictureID_p, class con2thread *con_p, std::string errorCode_p="0",std::string zipcode_p="0")
	{
		singleclient *s_client = new singleclient(ip, path_p, startTime_p, endTime_p, pictureID_p, con_p, errorCode_p,zipcode_p);
		s_client->moveToThread(&client_thread);
		connect(&client_thread, &QThread::finished, s_client, &QObject::deleteLater);
		connect(s_client, SIGNAL(resultReady(const QString &)), this, SLOT(handleResults(const QString &)));
		connect(s_client, SIGNAL(resultReady(const QString &)), this, SIGNAL(rcv_ip(const QString &)));
		connect(this, SIGNAL(operate()), s_client,SLOT(do_StartSingleClient()));
		client_thread.start();
		emit operate();
	}
	~Cthread_controller()
	{
		client_thread.quit();
		client_thread.wait();
	}
public slots:
	void handleResults(const QString &rcv_ip);
signals:
	void operate(/*const QString &*/);//通知子线程开client
	void rcv_ip(const QString &);
};

/////////
#endif
