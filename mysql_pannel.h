#pragma once
#ifndef MYSQL_PANNEL_H
#define MYSQL_PANNEL_H


#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QWidget>
//#include <QtWebEngineWidgets/QWebEngineView>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <string>
#include <QString>
#include <QTextBrowser>
#include <QImage>
#include <QPixmap>
#include <QCheckBox>
#include <QMouseEvent>
#include <QFileDialog>
#include "mysql_con.h"
//#include "includes.h"

class mysql_pannel : public QWidget
{
	Q_OBJECT

public:
	mysql_pannel(QWidget *parent = 0);
	~mysql_pannel();
private:
	//QWidget *centralwidget;
	MySql_DB *mydb;
	QGridLayout *mainlayout;
	QPushButton *but1;
	QTextBrowser *txtbr;
	//QLabel *imglab;
	//QPixmap *pimg;
	QLabel *lab1;
	QLabel *lab2;
	QLabel *lab3;
	QLineEdit *line1;
	QLineEdit *line2;
	QLineEdit *line3;
	QPushButton *b1;
	QPushButton *b2;
	QPushButton *b3;
	QLineEdit *l_e;
	QPushButton *b_cmd;
	//QPushButton *fbutton;
private slots:
	void b3_clicked();
	void b2_clicked();
	void show_row(const QString &text);
	void b_cmd_clicked();
};

#endif // WIDGET_H

