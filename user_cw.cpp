#include "user_cw.h"

user_cw::user_cw(MySql_DB *DB, QWidget *parent)
	:QWidget(parent), base(DB)
{
	this->resize(339, 276);
	UserNameL = new QLabel();
	UserNameL->setText("�û���");
	UserNameL->setAlignment(Qt::AlignRight);
	UserNameL->setFixedWidth(100);
	PassWordL = new QLabel("����");
	PassWordL->setAlignment(Qt::AlignRight);
	PassWordL->setFixedWidth(100);
	UserNameE = new QLineEdit();
	UserNameE->setFixedWidth(150);
	//UserNameE->setText("admin");
	PassWordE = new QLineEdit();
	PassWordE->setFixedWidth(150);
	PassWordE->setEchoMode(QLineEdit::Password);
	//PassWordE->setText("admin");
	ConfirmButton = new QPushButton();
	ConfirmButton->setFixedWidth(150);
	ConfirmButton->setText("ע��");
	CancelButton = new QPushButton();
	CancelButton->setFixedWidth(150);
	CancelButton->setText("ȡ��");
	/*����*/
	mainlayout = new QGridLayout();
	mainlayout->addWidget(UserNameL, 0, 0, 1, 1);
	mainlayout->addWidget(UserNameE, 0, 1, 1, 1);
	mainlayout->addWidget(PassWordL, 1, 0, 1, 1);
	mainlayout->addWidget(PassWordE, 1, 1, 1, 1);
	mainlayout->addWidget(ConfirmButton, 2, 0, 1, 1);
	mainlayout->addWidget(CancelButton, 2, 1, 1, 1);
	this->setLayout(mainlayout);
	/*����end*/
	/*��*/
	connect(ConfirmButton, SIGNAL(clicked()), this, SLOT(ConfirmButtonClicked()));
	connect(CancelButton, SIGNAL(clicked()), this, SLOT(CancelButtonClicked()));
}
user_cw::~user_cw()
{}

void user_cw::ConfirmButtonClicked()
{
	QString cmd = "insert into user (aname,pwd) values ('" + UserNameE->text() + "','" + PassWordE->text() + "');";
	if (base->mysql_cmd(cmd.toStdString()))
	{
		QMessageBox msg1;
		msg1.setText("ע��ɹ�");
		msg1.exec();
		this->close();
	}
	else
	{
		QMessageBox msg1;
		msg1.setText("ע��ʧ��");
		msg1.exec();
		this->close();
	}
}
void user_cw::CancelButtonClicked()
{
	this->close();
	return;
}