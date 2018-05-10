#pragma once
#ifndef SEARCH_W_H
#define SEARCH_W_H


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
#include <QFileDialog>
//#include <QSizePolicy>
#include <QFile>
#include <QDateTime>
#include <QDate>
#include "mysql_con.h"
#include "struct_class_file.h"
//#include "includes.h"

class search_w : public QWidget
{
	Q_OBJECT

public:
	search_w(QWidget *parent = 0);
	~search_w();
	QMessageBox msg;
private:
	QPushButton *sel_pic_btn;
	QPushButton *confirm_btn;
	QDateEdit *b_date;
	QDateEdit *e_date;
	QTimeEdit *b_time;
	QTimeEdit *e_time;
	QLabel *imglab_sw;
	QPixmap *pimg;
	QGroupBox *b_group;
	QGroupBox *e_group;
	//QGroupBox *btm_group;
	QVBoxLayout *rightlayout;
	QVBoxLayout *leftlayout;
	QVBoxLayout *b_layout;
	QVBoxLayout *e_layout;
	QHBoxLayout *bottom_layout;
	QGridLayout *mainlayout;
	QLabel *bl1;
	QLabel *bl2;
	QLabel *el1;
	QLabel *el2;
	QLabel *fi_l;
	QPushButton *cancel_btn;
	QString *imgname;
	QString *pic_name;
	//bool b_date_flag = false;
	//QDate bcdate=QDate::fromString("1970-01-01","yyyy-MM-dd");
	QDate bcdate = QDate::currentDate();//qtbug²¹¾È
private slots:
	void cancel_btn_clicked();
	void confirm_btn_clicked();
	void sel_pic_clicked();
	void b_date_check(const QDate &date);
signals:
	void SubmitQuerry(struct QuerryStruct &QS);
};

#endif 

