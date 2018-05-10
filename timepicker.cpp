#include "timepicker.h"

timepicker::timepicker(QWidget *parent)
	:QWidget(parent)
{
	this->resize(400, 300);
	this->setWindowTitle("ѡ��ʱ�䷶Χ");
	mainlayout = new QGridLayout();
	l1 = new QLabel("ѡ��ʼʱ��");
	l2 = new QLabel("ѡ�����ʱ��");
	b_datetime = new QDateTimeEdit(QDateTime::currentDateTime());
	b_datetime->setMinimumDate(QDate::fromString("1970-01-01", "yyyy-MM-dd"));
	b_datetime->setCalendarPopup(true);
	e_datetime = new QDateTimeEdit(QDateTime::currentDateTime());
	e_datetime->setMinimumDate(QDate::fromString("1970-01-01", "yyyy-MM-dd"));
	e_datetime->setCalendarPopup(true);
	confirmbutton = new QPushButton("ȷ��");
	confirmbutton->setFixedWidth(100);
	cancelbutton = new QPushButton("ȡ��");
	cancelbutton->setFixedWidth(100);
/*����*/
	mainlayout->addWidget(l1, 0, 0, 1, 1);
	mainlayout->addWidget(b_datetime, 0, 1, 1, 1);
	mainlayout->addWidget(l2, 1, 0, 1, 1);
	mainlayout->addWidget(e_datetime, 1, 1, 1, 1);
	mainlayout->addWidget(confirmbutton, 2, 0, 1, 1);
	mainlayout->addWidget(cancelbutton, 2, 1, 1, 1);
	this->setLayout(mainlayout);
/*����end*/
/*��*/
	connect(confirmbutton, SIGNAL(clicked()), this, SLOT(confirmbutton_clicked()));
	connect(cancelbutton, SIGNAL(clicked()), this, SLOT(cancelbutton_clicked()));
/*��end*/
}
timepicker::~timepicker()
{}
void timepicker::confirmbutton_clicked()
{
	emit ShowResultWithTimeSpan("  where create_time between '"+b_datetime->dateTime().toString("yyyy-MM-dd hh:mm:ss")+"' and '"+e_datetime->dateTime().toString("yyyy-MM-dd hh:mm:ss")+"'  ");
	this->close();
}
void timepicker::cancelbutton_clicked()
{
	this->close();
}