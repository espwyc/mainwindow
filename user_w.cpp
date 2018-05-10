#include "user_w.h"

int userstatus = 0;

user_w::user_w(MySql_DB *DB,QWidget *parent)
	:QWidget(parent),base(DB)
{
	this->resize(339, 276);
	this->setWindowTitle("�û���½");
	UserNameL = new QLabel();
	UserNameL->setText("�û���");
	UserNameL->setAlignment(Qt::AlignRight);
	UserNameL->setFixedWidth(100);
	PassWordL=new QLabel("����");
	PassWordL->setAlignment(Qt::AlignRight);
	PassWordL->setFixedWidth(100);
	UserNameE = new QLineEdit();
	UserNameE->setFixedWidth(150);
	UserNameE->setText("admin");
	PassWordE=new QLineEdit();
	PassWordE->setFixedWidth(150);
	PassWordE->setEchoMode(QLineEdit::Password);
	PassWordE->setText("admin");
	ConfirmButton = new QPushButton();
	ConfirmButton->setFixedWidth(150);
	ConfirmButton->setText("��½");
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
/*��end*/
}
user_w::~user_w()
{

}
void user_w::ConfirmButtonClicked()
{
	QMessageBox msg;
	int rs = (base->CheckUserPWD(UserNameE->text(), PassWordE->text()));
	if (rs == 1)
	{
		msg.setText("��½�ɹ�");
		msg.setWindowTitle("�ɹ�");
		msg.exec();
		userstatus = 1;
		/**/
	}
	else if (rs == 0)
	{
		msg.setText("�û������������");
		msg.setWindowTitle("����");
		msg.exec();
		userstatus = 0;
	}
	else if (rs == -1)
	{
		msg.setText("���ݿ�δ����");
		msg.setWindowTitle("����");
		msg.exec();
		userstatus = 0;
	}
	else if (rs == -2)
	{
		msg.setText("���ݿ����");
		msg.setWindowTitle("����");
		msg.exec();
		userstatus = 0;
	}
	this->close();
}
void user_w::CancelButtonClicked()
{
	this->close();
	/*userstatus = 0;
	QMessageBox msg;
	msg.setWindowTitle("ע���ɹ�");
	msg.setText("ע���ɹ�");
	msg.exec();*/
}

int CheckUserStatus()
{
	if (userstatus != 1)
	{
		QMessageBox msg;
		msg.setWindowTitle("δ��¼");
		msg.setText("δ��½�����½��");
		msg.exec();
	}
	return userstatus;
}