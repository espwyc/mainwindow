#include "user_w.h"

int userstatus = 0;

user_w::user_w(MySql_DB *DB,QWidget *parent)
	:QWidget(parent),base(DB)
{
	this->resize(339, 276);
	this->setWindowTitle("用户登陆");
	UserNameL = new QLabel();
	UserNameL->setText("用户名");
	UserNameL->setAlignment(Qt::AlignRight);
	UserNameL->setFixedWidth(100);
	PassWordL=new QLabel("密码");
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
	ConfirmButton->setText("登陆");
	CancelButton = new QPushButton();
	CancelButton->setFixedWidth(150);
	CancelButton->setText("取消");
/*布局*/
	mainlayout = new QGridLayout();
	mainlayout->addWidget(UserNameL, 0, 0, 1, 1);
	mainlayout->addWidget(UserNameE, 0, 1, 1, 1);
	mainlayout->addWidget(PassWordL, 1, 0, 1, 1);
	mainlayout->addWidget(PassWordE, 1, 1, 1, 1);
	mainlayout->addWidget(ConfirmButton, 2, 0, 1, 1);
	mainlayout->addWidget(CancelButton, 2, 1, 1, 1);
	this->setLayout(mainlayout);
/*布局end*/
/*槽*/
	connect(ConfirmButton, SIGNAL(clicked()), this, SLOT(ConfirmButtonClicked()));
	connect(CancelButton, SIGNAL(clicked()), this, SLOT(CancelButtonClicked()));
/*槽end*/
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
		msg.setText("登陆成功");
		msg.setWindowTitle("成功");
		msg.exec();
		userstatus = 1;
		/**/
	}
	else if (rs == 0)
	{
		msg.setText("用户名或密码错误");
		msg.setWindowTitle("错误");
		msg.exec();
		userstatus = 0;
	}
	else if (rs == -1)
	{
		msg.setText("数据库未连接");
		msg.setWindowTitle("错误");
		msg.exec();
		userstatus = 0;
	}
	else if (rs == -2)
	{
		msg.setText("数据库错误");
		msg.setWindowTitle("错误");
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
	msg.setWindowTitle("注销成功");
	msg.setText("注销成功");
	msg.exec();*/
}

int CheckUserStatus()
{
	if (userstatus != 1)
	{
		QMessageBox msg;
		msg.setWindowTitle("未登录");
		msg.setText("未登陆，请登陆！");
		msg.exec();
	}
	return userstatus;
}