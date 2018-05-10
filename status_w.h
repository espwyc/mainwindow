#pragma once
#ifndef STATUS_W_H
#define STATUS_W_H

#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QTimeEdit>
#include <QDateEdit>
#include <QGroupBox>
#include <QMessageBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTextBrowser>
#include <QTimer>
#include "struct_class_file.h"
#include "mysql_con.h"

class status_w : public QWidget
{
	Q_OBJECT

public:
	status_w(MySql_DB *DB,QWidget *parent = 0);
	~status_w();
	QMessageBox msg;
	void update_status(std::vector <std::string> &iparr);
private:
	QTreeWidgetItem *item;
	QTimer *t1;
	MySql_DB *base;
	QTextBrowser *txtb;
	//QLabel *label;
	QVBoxLayout *layout;
	QTreeWidget *tree;
signals:
private slots :
	
public slots :

};

#endif
