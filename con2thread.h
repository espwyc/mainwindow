#pragma once
#ifndef CON2THREAD_H
#define CON2THREAD_H

#pragma execution_character_set("utf-8")
#include <QObject>
#include <QString>
#include "struct_class_file.h"
//#include "includes.h"

class con2thread :public QObject
{
	Q_OBJECT
public:
	con2thread();
	~con2thread();
	bool sendmsgback(const QString &text);
	bool recvpic_fin(struct QuerryResultStruct RS);
	bool rcv_fin_flag;
	struct QuerryResultStruct tmp;
	//QMessageBox msg;
private:
	signals:
		void rcv_sig(const QString);
		void mysig(const QString);
		void rcvpic_sig(const QString res_str/*, const QString pic_path,const int pid,const QDateTime b_t,const QDateTime e_t*/);
};


#endif