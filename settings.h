#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

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
#include <QTableWidget>
#include <QSignalMapper>
#include <QDialogButtonBox>
#include <QDialog>
#include "struct_class_file.h"
#include "mysql_con.h"


class dbsetting_w : public QWidget
{
	Q_OBJECT

public:
	dbsetting_w(MySql_DB *DB, QWidget *parent = 0);
	~dbsetting_w();

private:
	QLabel *accountL, *pwdL, *hostL, *portL, *dbnameL;
	QLineEdit *accountE, *pwdE, *hostE, *portE, *dbnameE;
	QPushButton *ConfirmButton, *CancelButton;
	MySql_DB *base;
	QGridLayout *mainlayout;
signals:

private slots :
	void	ConfirmButtonClicked();
	void CancelButtonClicked();

	public slots :

};
class netsetting_w : public QWidget
{     
	Q_OBJECT

public:
	netsetting_w(MySql_DB *DB, QWidget *parent = 0);
	~netsetting_w();

private:
	QLabel *accountL, *pwdL,*hostL,*portL,*dbnameL;
	QLineEdit *accountE, *pwdE, *hostE, *portE, *dbnameE;
	QPushButton *tmpb;
	MySql_DB *base;
	QTableWidget *table;
	QTimer *t1;
	QSignalMapper *smapper,*dmapper;
	QGridLayout *mainlayout;
	void Init_Table(QTableWidget *table);
signals:

private slots :
	void	EditButtonClicked(const QString &id);
	void DeleteButtonClicked(const QString &id);

	public slots :

};



#endif

