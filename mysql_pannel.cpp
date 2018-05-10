#include "mysql_pannel.h"

#define B3C 1

mysql_pannel::mysql_pannel(QWidget *parent)
	: QWidget(parent)
{
	mydb = new MySql_DB();
	mainlayout = new QGridLayout();
	txtbr = new QTextBrowser();

	txtbr->setMinimumWidth(400);
	txtbr->setMinimumHeight(247);
	b1 = new QPushButton();
	b1->setText("����id��ѯ");
	b1->setFixedWidth(160);
	b2 = new QPushButton();
	b2->setText("�������ڲ�ѯ");
	b2->setFixedWidth(160);
	b3 = new QPushButton();
	b3->setText("�鿴��������");
	b3->setFixedWidth(160);
	b_cmd = new QPushButton();
	l_e = new QLineEdit();
	b_cmd->setText("����ִ��sql���");
	l_e->setText("insert into user (aname, rname, position,priority)values('uestc', '���ӿƼ���', 'ceo',1);");

	QFont font;
	font.setPointSize(16); //ʵ������16���ֺţ������16ȴ����   
	font.setFamily(("Microsoft YaHei"));
	font.setBold(false);
	txtbr->setFont(font);
	mainlayout->addWidget(txtbr, 0, 0, 3, 1);
	mainlayout->addWidget(b1, 0, 1, 1, 1);
	mainlayout->addWidget(b2, 1, 1, 1, 1);
	mainlayout->addWidget(b3, 2, 1, 1, 1);
	mainlayout->addWidget(l_e, 3, 0, 1, 1);
	mainlayout->addWidget(b_cmd, 3, 1, 1, 1);
	//mainlayout->addstren
	this->setLayout(mainlayout);
/**************************************************************************************/
/**************************************************************************************/
/*--------------------------��--------------------------------------------------------*/
/**************************************************************************************/
	connect(b3, SIGNAL(clicked()), this, SLOT(b3_clicked()));
	connect(b2, SIGNAL(clicked()), this, SLOT(b2_clicked()));
	connect(mydb, SIGNAL(send_row(const QString &)), this, SLOT(show_row(const QString &)));
	connect(b_cmd, SIGNAL(clicked()), this, SLOT(b_cmd_clicked()));
/**************************************************************************************/
/**************************************************************************************/
/*--------------------------��----end------------------------------------------------*/
/**************************************************************************************/

}

mysql_pannel::~mysql_pannel()
{

}
void mysql_pannel::b3_clicked()
{
#if (B3C==1)
	mydb->mysql_test();
#elif (B3C ==2)
	mydb->mysql_test2();
#elif (B3C==3)
	MYSQL_RES *res = mydb->mysql_test3();
	MYSQL_ROW sqrow;
	while (sqrow = mysql_fetch_row(res))//��ȡ���������
	{
		txtbr->append((QString)"name:" + (QString)sqrow[1] + (QString)" location:" + (QString)sqrow[2]);
	}
#endif
}
void mysql_pannel::show_row(const QString &text)
{
	txtbr->append(text);
}
void mysql_pannel::b2_clicked()
{

}
void mysql_pannel::b_cmd_clicked()
{
	std::vector<QString> vec;
	vec = mydb->read_resultLOCATION_bypicid(QString::number(1182,10));
	for (auto i : vec)
	{
		txtbr->append(i);
	}
	vec = mydb->read_resultAPTIME_bypicid(QString::number(1182, 10));
	for (auto i : vec)
	{
		txtbr->append(i);
	}
	vec = mydb->read_resultPICPATH_bypicid(QString::number(1182, 10));
	for (auto i : vec)
	{
		txtbr->append(i);
	}
}