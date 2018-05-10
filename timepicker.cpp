#include "timepicker.h"

timepicker::timepicker(QWidget *parent)
	:QWidget(parent)
{
	this->resize(400, 300);
	this->setWindowTitle("选择时间范围");
	mainlayout = new QGridLayout();
	l1 = new QLabel("选择开始时间");
	l2 = new QLabel("选择结束时间");
	b_datetime = new QDateTimeEdit(QDateTime::currentDateTime());
	b_datetime->setMinimumDate(QDate::fromString("1970-01-01", "yyyy-MM-dd"));
	b_datetime->setCalendarPopup(true);
	e_datetime = new QDateTimeEdit(QDateTime::currentDateTime());
	e_datetime->setMinimumDate(QDate::fromString("1970-01-01", "yyyy-MM-dd"));
	e_datetime->setCalendarPopup(true);
	confirmbutton = new QPushButton("确定");
	confirmbutton->setFixedWidth(100);
	cancelbutton = new QPushButton("取消");
	cancelbutton->setFixedWidth(100);
/*布局*/
	mainlayout->addWidget(l1, 0, 0, 1, 1);
	mainlayout->addWidget(b_datetime, 0, 1, 1, 1);
	mainlayout->addWidget(l2, 1, 0, 1, 1);
	mainlayout->addWidget(e_datetime, 1, 1, 1, 1);
	mainlayout->addWidget(confirmbutton, 2, 0, 1, 1);
	mainlayout->addWidget(cancelbutton, 2, 1, 1, 1);
	this->setLayout(mainlayout);
/*布局end*/
/*槽*/
	connect(confirmbutton, SIGNAL(clicked()), this, SLOT(confirmbutton_clicked()));
	connect(cancelbutton, SIGNAL(clicked()), this, SLOT(cancelbutton_clicked()));
/*槽end*/
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