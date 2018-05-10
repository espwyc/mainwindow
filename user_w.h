#pragma once
#ifndef USER_W_H
#define USER_W_H

#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
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



class user_w : public QWidget
{
	Q_OBJECT

public:
	user_w(MySql_DB *DB,QWidget *parent = 0);
	~user_w();
	
private:
	QLabel *UserNameL, *PassWordL;
	QLineEdit *UserNameE, *PassWordE;
	QPushButton *ConfirmButton, *CancelButton;
	MySql_DB *base;
	QGridLayout *mainlayout;
signals:
	
private slots :
	void	ConfirmButtonClicked();
	void CancelButtonClicked();

public slots :

};

#endif
