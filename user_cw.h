#pragma once
#ifndef USER_CW_H
#define USER_CW_H

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
class user_cw : public QWidget
{
	Q_OBJECT
public:
	user_cw(MySql_DB *DB, QWidget *parent=0);
	~user_cw();
private:
	MySql_DB *base;
	QLabel *UserNameL, *PassWordL;
	QLineEdit *UserNameE, *PassWordE;
	QPushButton *ConfirmButton, *CancelButton;
	QGridLayout *mainlayout;
signals:

private slots :
	void	ConfirmButtonClicked();
	void CancelButtonClicked();

	public slots :
};

#endif