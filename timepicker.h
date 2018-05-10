#pragma once
#ifndef TIMEPICKER_H
#define TIMEPICKER_H

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


class timepicker : public QWidget
{
	Q_OBJECT
public:
	timepicker(QWidget *parent = 0);
	~timepicker();
private:
	QLabel *l1, *l2;
	//QDateEdit *b_date;
	//QDateEdit *e_date;
	//QTimeEdit *b_time;
	//QTimeEdit *e_time;
	QDateTimeEdit *b_datetime, *e_datetime;
	QPushButton *confirmbutton, *cancelbutton;
	QGridLayout *mainlayout;
signals:
	void ShowResultWithTimeSpan(const QString &ts);
private slots:
	void confirmbutton_clicked();
	void cancelbutton_clicked();
};



#endif
