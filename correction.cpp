#include "correction.h"

extern int MAP;
//#include "mainwindow.h"
#if (CW==1)
correction::correction(QWidget *parent): QWidget(parent)
#elif (CW==0)
correction::correction(MySql_DB * DB,QWidget *parent) : QDialog(parent),base(DB)
#endif
{
	//MainWindow *ptr = (MainWindow*)parentWidget();
	//ptr->btelb_text("from correction dialog!");
	//centralwidget = new QWidget();
	QString s = QString::number((MAP-1), 10);
	

	l_e = new QLineEdit();
	b_cmd = new QPushButton();
	imglab = new QLabel();
	pimg = new QPixmap();
	mainlayout = new QGridLayout();
	leftlayout = new QVBoxLayout();
	rightlayout = new QGridLayout();
	but1 = new QPushButton();
	lab1 = new QLabel();
	lab2 = new QLabel();
	lab3 = new QLabel();
	line1 = new QLineEdit();
	line2 = new QLineEdit();
	line3 = new QLineEdit();
	b1 = new QPushButton();
	b2 = new QPushButton();
	fbutton = new QPushButton();
	b_date = new QDateEdit(QDate::currentDate());
	//b_date->setMaximumDate(QDate::currentDate());
	b_date->setMinimumDate(QDate::fromString("1970-01-01", "yyyy-MM-dd"));
	e_date = new QDateEdit(QDate::currentDate());
	e_date->setMinimumDate(QDate::fromString("1970-01-01", "yyyy-MM-dd"));
	b_time = new QTimeEdit(QTime::currentTime());
	e_time = new QTimeEdit(QTime::currentTime());
	e_date->setCalendarPopup(true);
	b_date->setCalendarPopup(true);
	imglab->setFixedHeight(300);
	imglab->setFixedWidth(185);
	imglab->setScaledContents(true);
	pimg->load("img/img1.jpg");
	/*pimg->load("img/img"+s+".jpg");*/
	/*QMessageBox msg;
	msg.setText("img/img" + s + ".jpg");
	msg.exec();*/
	imglab->setPixmap(*pimg);
	imglab->installEventFilter(this);
	//b_time->setFixedWidth(180);
	b_date->setFixedWidth(180);
	//e_time->setFixedWidth(180);
	e_date->setFixedWidth(180);
	//b1->setFixedWidth(180);
	//b2->setFixedWidth(180);
	//b1->setFixedWidth(120);
	//b2->setFixedWidth(120);
	//lab1->setFixedWidth(180);
	//lab2->setFixedWidth(180);
	//lab3->setFixedWidth(180);
	//line1->setFixedWidth(180);
	//line2->setFixedWidth(180);
	//line3->setFixedWidth(180);
	//fbutton->setFixedWidth(180);
	lab1->setText("纠错地点及ip/映射端口");
	lab2->setText("选择开始时间日期");
	lab3->setText("选择结束时间日期");
	b1->setText("开始重新检索");
	b2->setText("取消");
	fbutton->setText("选择文件:");
	//l_e->setText("insert into user (UID,)")


	leftlayout->addWidget(imglab);
	//leftlayout->addStretch();

	rightlayout->addWidget(lab1, 0, 0, 1, 1);

	//rightlayout->addWidget(lab2, 1, 0, 1, 1);
	//rightlayout->addWidget(b_time, 2, 0, 1, 1);
	//rightlayout->addWidget(b_date, 2, 1, 1, 1);
	//rightlayout->addWidget(lab3, 3, 0, 1, 1);
	//rightlayout->addWidget(e_time, 4, 0, 1, 1);
	//rightlayout->addWidget(e_date, 4, 1, 1, 1);

	rightlayout->addWidget(b1, 5, 0, 1, 1);
	rightlayout->addWidget(b2, 5, 1, 1, 1);

	//mainlayout->addWidget(b1, 3, 1, 1, 1);
	//mainlayout->addWidget(b2, 3, 2, 1, 1);

	//mainlayout->addWidget(imglab, 0, 0, 4, 1);
	//mainlayout->addWidget(lab1, 0, 1, 1, 3);

	//mainlayout->addWidget(lab2, 1, 1, 1, 1);
	//mainlayout->addWidget(b_time, 1, 2, 1, 1);
	//mainlayout->addWidget(b_date, 1, 3, 1, 1);
	//mainlayout->addWidget(lab3, 2, 1, 1, 1);
	//mainlayout->addWidget(e_time, 2, 2, 1, 1);
	//mainlayout->addWidget(e_date, 2, 3, 1, 1);
	////mainlayout->addWidget(fbutton, 2, 2, 1, 1);
	////mainlayout->addWidget(line3, 2, 2, 1, 1);
	//mainlayout->addWidget(b1, 3, 1, 1, 1);
	//mainlayout->addWidget(b2, 3, 2, 1, 1);


	//QWidget *spacer = new QWidget(this);
	//spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	//mainlayout->addWidget(spacer, 4, 1, 1, 1);
	//QVBoxLayout bbox;
	//mainlayout->addWidget(l_e, 4, 0, 1, 1);
	//mainlayout->addWidget(b_cmd, 4, 1, 1, 1);
	//mainlayout->addWidget(but1, 0, 0);
	mainlayout->addLayout(leftlayout, 0, 0, 1, 1);

	mainlayout->addLayout(rightlayout, 0, 1, 1, 1);

	//centralwidget->setLayout(mainlayout);


	this->setLayout(mainlayout);
	this->setWindowTitle("纠错");
	/**************************************************************************************/
	/**************************************************************************************/
	/*--------------------------槽----------------------------------------------------*/
	/**************************************************************************************/
	connect(but1, SIGNAL(clicked()), this, SLOT(but1_clicked()));
	connect(fbutton,SIGNAL(clicked()),this,SLOT(fbutton_clicked()));
	connect(b1, SIGNAL(clicked()), this, SLOT(bt1_clicked()));
	connect(b2, SIGNAL(clicked()), this, SLOT(bt2_clicked()));
	/**************************************************************************************/
	/**************************************************************************************/
	/*--------------------------槽----------end------------------------------------------*/
	/**************************************************************************************/
}

correction::~correction()
{

}
void correction::but1_clicked()
{
	/*emit cw_but1("testbutfrmcw");
	QMessageBox msg;
	msg.setText("cw_but1click");
	msg.exec();*/
}
void correction::pimg_load(const QString &text)
{
	pimg->load(text);
	imglab->setPixmap(*pimg);
	/*QMessageBox msg;
	msg.setText(text);
	msg.exec();*/
}
bool correction::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == imglab)
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			/*QMessageBox::information(NULL, "点击", "点击了我",
			QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			*/
			//picw->show();
			emit picw_show();
			return true;
		}
		else return false;
	}
	else
	{
		return QObject::eventFilter(obj, event);
	}
	//return false;
}
void correction::fbutton_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Spreadsheet"), ".",
		tr("Spreadsheet files (*.jpg)"));
	//pimg->load(fileName);
	pimg->load(fileName);
	imglab->setPixmap(*pimg);
	/*QMessageBox msg;
	msg.setText(fileName);
	msg.exec();*/
	//下一步处理
}
void correction::bt1_clicked()
{
	static vector <QString> zipcodes;
	static int Ecodes[MAX_PNTCOUNT];
	int f = 0, num = 0;
	for (auto a : zipcodes)
	{
		if (a == cface.zipcode)//不是第一次
		{
			f = 1;
			Ecodes[num]++;
			break;
		}
		num++;
	}
	if (f == 0)//首次纠错
	{
		zipcodes.push_back(cface.zipcode);
		Ecodes[num] = 1;
	}
	QuerryStruct tmp;
	tmp.errorcode = QString::number(Ecodes[num], 10);
	tmp.pic_path = cface.path;
	tmp.pic_id = cface.pic_id.toInt();
	tmp.ipArr.push_back(cface.zipcode.toStdString());
	QDate edt = e_date->date();
	QDate bdt = b_date->date();
	QTime et = e_time->time();
	QTime bt = b_time->time();

	QString cmd = "select  begin_time,end_time from querrytable where  pic_id = '" + cface.pic_id + "';";
	MYSQL_RES res = base->sql_cmd_rresult(cmd.toStdString());
	MYSQL_ROW sql_row;
	sql_row = mysql_fetch_row(&res);
	QDateTime b = QDateTime::fromString(sql_row[0], "yyyy-MM-dd hh:mm:ss");
	QDateTime e= QDateTime::fromString(sql_row[1], "yyyy-MM-dd hh:mm:ss");
	tmp.e_t = e;
	tmp.b_t = b;
	emit SubmitQuerry(tmp);
	//QMessageBox msg1;
	cmd = "delete from querryresult where rpic_path='" + cface.path + "'";
	base->mysql_cmd(cmd.toStdString());
	QMessageBox msg1;
	msg1.setText("已提交纠错指令");
	msg1.exec();
	this->close();
}
void correction::bt2_clicked()
{
	this->close();
}