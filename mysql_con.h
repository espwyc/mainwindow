/*
Qstring ->std::string toStdString()
std::string->Qstring  QString::fromStdString()
int ->std::string  to_string 重载
std::string->char* .c_str();
char *->string  如char c_str = "abcdefghijklmn";
    string str = c_str;
*/
#pragma once
#ifndef MYSQL_CON_H
#define MYSQL_CON_H

#pragma execution_character_set("utf-8")


#define WIN32_LEAN_AND_MEAN    

#include <QWidget>
#include <Windows.h>
#include <mysql.h>
#include <string>
#include <iostream>
#include <QString>
#include <QObject>
#include <QMessageBox>
#include <QDateTime>
#include "struct_class_file.h"
//#include "includes.h"

//#include <stdio.h>

using namespace std;


class MySql_DB:public QObject
{
	Q_OBJECT


public:
	//MySql_DB(QWidget *parent = 0);
	MySql_DB();
	~MySql_DB();

	QString mysql_test();
	QString mysql_test2();
	MYSQL_RES* mysql_test3();
	QMessageBox msg;
	struct address_node * addr_graph=NULL;
	struct address_node * init_addr_graph();
	bool connection_flag = false;
	/*int test();
	int test(int a);//重载*/
	MYSQL_RES sql_cmd_rresult(const string &cmd);
	std::vector<int> read_resultPK_bypicid(/*...*/);/*按照图片id查询，并返回检索结果所有主键*/
	std::vector<QString> read_resultAPTIME_bypicid(/*...*/const QString pic_id);/*按照图片id查询，并返回检索结果出现的时间*/
	std::vector<QString> read_resultLOCATION_bypicid(/*...*/const QString pic_id);/*按照图片id查询，并返回检索结果所有地点*/
	std::vector<QString> read_resultPICPATH_bypicid(/*...*/const QString pic_id);/*按照图片id查询，并返回图片路径*/
	std::vector<QString> read_resultZIPCODE_bypicid(/*...*/const QString pic_id);/*按照图片id查询，并返回zipcode*/
	std::vector<QString> read_resultPICSIMILARITY_bypicid(/*...*/const QString pic_id);/*按照图片id查询，并返回picsim*/
	int save_querry(int pic_id, const QString &pic_path, QDate &begaindate,QTime &begaintime, QDate &enddate,  QTime &endtime);
	//int save_querry_result(/**/const string &pic_path,const string &pic_id,const string &datetime,const string &location);/*保存返回检索结果并返回在数据库中的主键一般调用者：通信模块*/
	int save_querry_result(struct QuerryResultStruct RS,const QString pic_path);
	/*int save_correction_result(struct QuerryResultStruct RS, const QString pic_path);*/
	int save_pic(const QString &text);/*保存图片路径并返回图片在数据库中的主键*/
	int save_rpic(const QString &text);/*保存检索结果图片路径并返回图片在数据库中的主键*/
	int save_correction_querry(/**/);
	int save_correction_querry_result(/**/);
	bool mysql_cmd(const string &cmd);
	int CheckUserPWD(const QString username, const QString password);
	bool setdb(const QString username, const QString pwd, const QString hostname, const QString basename, const QString portnum);
private:

	/*const*/ char user[30] = "root";
	/*const*/ char pswd[30] = "312006";
	/*const*/ char host[30] = "localhost";
	/*const*/ char dbname[30] = "control_center_base";
	unsigned int port = 3306;
	//bool connection_flag = false;
	MYSQL my_con;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	bool ConnectDB();
	bool CloseDB();
	int last_insert_PK();
signals:
	void send_row(const QString);
	void send_msg(const QString);
};



#endif