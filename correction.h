#pragma once
#ifndef CORRECTION_H
#define CORRECTION_H

#define CW 0 // 将纠错窗口设定为对话框形式0或窗口形式1

#pragma execution_character_set("utf-8")


#include <QDialog>
#include <QWidget>
//#include <QMainWindow>
#include <QTimeEdit>
#include <QDateEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QTextBrowser>
#include <QImage>
#include <QPixmap>
#include <QCheckBox>
#include <QMouseEvent>
#include <QFileDialog>
#include "struct_class_file.h"
#include "mysql_con.h"
//#include "includes.h"

//#include "mainwindow.h"
class MainWindow;

#if (CW==1)
class correction : public QWidget
#elif (CW==0)
class correction : public QDialog
#endif
{
	Q_OBJECT

public:
	correction(MySql_DB *DB,QWidget *parent = 0) ;
	//correction(QString loca, QString picid, QWidget *parent = 0);
	~correction();
	//QPixmap *pimg;
	QLabel *imglab;
	void pimg_load(const QString &text);
	void correction_info(const QString &pid, const QString &loca) 
	{ 
		pic_id = pid;
		location = loca;
	/*	lab1->setText("纠错地点及ip" + location);
		lab2->setText("picid：" + pic_id);*/
	};
	void pass_faceinfo(const FaceInfo &face)
	{
		cface = face;
		lab1->setText("重新检索地址:"+cface.location+" ip地址:"+cface.zipcode);
		//lab2->setText("picid&zipcode：" +cface.pic_id+" "+cface.zipcode);
	};
private:
	MySql_DB *base;
	FaceInfo cface;
	//QWidget *centralwidget;
	QString pic_id;
	QString location;
	QGridLayout *mainlayout;
	QVBoxLayout *leftlayout;
	QGridLayout *rightlayout;
	QPushButton *but1;
	//QLabel *imglab;
	QPixmap *pimg;
	QLabel *lab1;
	QLabel *lab2;
	QLabel *lab3;
	QLineEdit *line1;
	QLineEdit *line2;
	QLineEdit *line3;
	QPushButton *b1;
	QPushButton *b2;
	QPushButton *fbutton;
	QLineEdit *l_e;
	QPushButton *b_cmd;
	QDateEdit *b_date;
	QDateEdit *e_date;
	QTimeEdit *b_time;
	QTimeEdit *e_time;

signals:
	//void cw_but1();
	void cw_but1(const QString);
	void picw_show();
	void SubmitQuerry(struct QuerryStruct &QS);
private slots:
	void but1_clicked();
	void fbutton_clicked();
	void bt1_clicked();
	void bt2_clicked();
protected:
	bool eventFilter(QObject *obj, QEvent *event);

};


#endif // CORRECTION_H
