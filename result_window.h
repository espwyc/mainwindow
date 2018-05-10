#pragma once
#ifndef RESULT_W_H
#define RESULT_W_H

#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QTableView>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QStringList>
#include <QPushButton>
#include <QSignalMapper>
#include "mysql_con.h"
//#include "includes.h"

class result_window : public QWidget
{
	Q_OBJECT

public:
	result_window(QWidget *parent = 0);
	~result_window();
	bool DB_pass_pter(MySql_DB *DB);
	void load_querry(const QString &ts);
	QMessageBox msg;
	void reload_querry(const QString &ts);
private:
	MySql_DB *base;
	QTableWidget *table;
	QTableView *tab_view;
	QGridLayout *mainlayout;
	QPushButton *pb1;
	QSignalMapper *signalMapper;
	QLabel *imglab;
	QPixmap *pimg;
	QPushButton *fresh_btn;
	int r_count;
	private slots:
	void button_clicked(int i);
	void ClickedButton(const QString &text);
	void fresh_btn_clicked();
	//void ClickedButton(const QString &text);
signals:
	void show_result_byid(const QString &picid);

};

#endif // WIDGET_H
