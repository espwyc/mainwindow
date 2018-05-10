#include "search_w.h"

//extern bool b_date_flag;

search_w::search_w(QWidget *parent)
	: QWidget(parent)
{
	this->setWindowTitle("检索信息");
	sel_pic_btn = new QPushButton();
	confirm_btn = new QPushButton();
	b_date=new QDateEdit(QDate::currentDate());
	//b_date->setMaximumDate(QDate::currentDate());
	b_date->setMinimumDate(QDate::fromString("1970-01-01","yyyy-MM-dd"));
	e_date=new QDateEdit (QDate::currentDate());
	e_date->setMinimumDate(QDate::fromString("1970-01-01", "yyyy-MM-dd"));
	b_time = new QTimeEdit(QTime::currentTime());
	e_time = new QTimeEdit(QTime::currentTime());
	imglab_sw = new QLabel();
	pimg= new QPixmap();
	b_group = new QGroupBox();
	e_group = new QGroupBox();
	//btm_group = new QGroupBox();
	e_layout = new QVBoxLayout();
	b_layout = new QVBoxLayout();
	rightlayout = new QVBoxLayout();
	leftlayout = new QVBoxLayout();
	bottom_layout = new QHBoxLayout();
	mainlayout = new QGridLayout();
	bl1 = new QLabel();
	bl2 = new QLabel();
	el1 = new QLabel();
	el2 = new QLabel();
	cancel_btn = new QPushButton();
	imgname = new QString();
	pic_name = new QString();
	fi_l = new QLabel();
/*左侧布局*/
	//imglab->setFixedHeight(300);
	//imglab->setFixedWidth(185);
	imglab_sw->setMinimumWidth(600);
	imglab_sw->setMinimumHeight(370);
	imglab_sw->setMaximumWidth(1000);
	imglab_sw->setMaximumHeight(618);
	imglab_sw->resize(400, 247);
	//imglab->setSizePolicy(GrowFlag);
	imglab_sw->setScaledContents(true);
	pimg->load("img/img1.jpg");
	
	imglab_sw->setPixmap(*pimg);
	leftlayout->addWidget(imglab_sw);
	
	//mainlayout->addWidget(imglab, 0, 0, 2, 1);
/*左侧布局end*/
/*右侧布局*/
	e_date->setCalendarPopup(true);
	//e_date->calendarPopup()
	b_date->setCalendarPopup(true);
	
	el1->setText("选择终止日期");
	el2->setText("选择终止时间");
	bl1->setText("选择起始日期");
	bl2->setText("选择起始时间");
	e_layout->addWidget(el1);
	e_layout->addWidget(e_date);
	e_layout->addWidget(el2);
	e_layout->addWidget(e_time);
	b_layout->addWidget(bl1);
	b_layout->addWidget(b_date);
	b_layout->addWidget(bl2);
	b_layout->addWidget(b_time);
	e_group->setLayout(e_layout);
	e_group->setTitle("终止日期");
	b_group->setLayout(b_layout);
	b_group->setTitle("起始日期");
	e_date->setMinimumWidth(200);
	b_date->setMinimumWidth(200);
	el1->setMinimumWidth(200);
	el2->setMinimumWidth(200);
	bl1->setMinimumWidth(200);
	bl2->setMinimumWidth(200);
	rightlayout->addWidget(b_group);
	rightlayout->addWidget(e_group);
/*右侧布局end*/
/*底部布局*/
	sel_pic_btn->setText("选择照片");
	fi_l->setText("未选择照片");
	confirm_btn->setText("确定检索");
	cancel_btn->setText("取消");
	//btm_group->setTitle("选择图片");
	bottom_layout->addWidget(sel_pic_btn);
	bottom_layout->addWidget(fi_l);
	bottom_layout->addStretch();
	bottom_layout->addWidget(confirm_btn);
	bottom_layout->addWidget(cancel_btn);

	//btm_group->setLayout(bottom_layout);
/*底部布局end*/
/*总体布局*/
	mainlayout->addLayout(leftlayout, 0, 0, 1, 1);
	mainlayout->addLayout(rightlayout, 0, 1, 1, 1);
	mainlayout->addLayout(bottom_layout, 1, 0, 1, 2);
	this->setLayout(mainlayout);
	this->setMinimumWidth(1000);
	this->setMinimumHeight(618);
	this->resize(1000, 618);
/*总体布局end*/
/*槽*/
	connect(cancel_btn, SIGNAL(clicked()), this, SLOT(cancel_btn_clicked()));
	connect(confirm_btn, SIGNAL(clicked()), this, SLOT(confirm_btn_clicked()));
	connect(sel_pic_btn, SIGNAL(clicked()), this, SLOT(sel_pic_clicked()));
	connect(b_date, SIGNAL(dateChanged(const QDate &)), this, SLOT(b_date_check(const QDate &)));
/*槽end*/
}

search_w::~search_w()
{

}
void search_w::cancel_btn_clicked()
{

}
void search_w::confirm_btn_clicked()
{
	QDate edt;
	edt = e_date->date();
	QDate bdt = b_date->date();
	QTime et= e_time->time();
	QTime bt = b_time->time();
	QMessageBox msg1;
	auto ret=msg1.information(NULL, "确定检索",
	/**/	"用户提交检索信息:\n照片："+ *imgname +"\n从"+bdt.toString()+"\n到"+edt.toString(),/**/
	/**/	QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);/**/
	//msg.setText("");
	//msg.exec();
	if (ret == QMessageBox::Yes)
	{
		/*提交检索信息*/
		/*QMessageBox msg;
		msg.setText("yes");
		msg.exec();*/
		MySql_DB m;
		int x=m.save_pic(PICLIBPATH+*pic_name);/*获取主键*/
		m.save_querry(x, PICLIBPATH + *pic_name, bdt, bt, edt, et);
/*提交给通信模块客户端*/
		struct QuerryStruct s;
		s.ipArr.push_back("127.0.0.1");
		s.pic_id = x;//pid
		//s.pic_path = CQPATH+ PICLIBPATH + *pic_name;//picpath提交绝对路径
		s.pic_path =  PICLIBPATH + *pic_name;//picpath提交相对路径
		s.e_t.setDate(edt);
		s.e_t.setTime(et);
		s.b_t.setDate(bdt);
		s.b_t.setTime(bt);//et&bt
		emit SubmitQuerry(s);
/*提交给通信模块客户端end*/
	}
	else if (ret == QMessageBox::No)
	{

	}
}
void search_w::sel_pic_clicked()
{
	*imgname = QFileDialog::getOpenFileName(this,tr("打开图片"), ".",tr("图片文件 (*.jpg)"));
	//pimg->load(fileName);
	if (imgname == NULL)
	{
		return;
	}
	else
	{
		//QFile::copy("img/img1.jpg","img/imgt.jpg");
		QDateTime t = QDateTime::currentDateTime();
		//QString ts = t.toString("yyyy-MM-dd hh:mm:ss");
		*pic_name = t.toString("yyyyMMddhhmmss");
		*pic_name += ".jpg";
		QFile::copy(*imgname, PICLIBPATH+*pic_name);
		QFile file(PICLIBPATH + *pic_name);
		file.setPermissions(QFile::ReadOther);//readonly
		/*msg.setText(ts);
		msg.exec();*/
		fi_l->setText(*imgname);
		pimg->load(*imgname);
		imglab_sw->setPixmap(*pimg);
	}
}
void search_w::b_date_check(const QDate &date)
{
	/*msg.setText(date.toString());
	msg.exec();*/
	//if (b_date->date() > QDate::currentDate())//用户更改改大于当前日期
	if((date>QDate::currentDate())&&(date !=bcdate))
	{
		QMessageBox msg1;
		auto ret = msg1.warning(NULL, "注意",
			/**/	"所选日期超过当前日期，是否继续？",/**/
			/**/	QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);/**/
		if (ret == QMessageBox::Yes)
		{
			bcdate = QDate::currentDate();
			return;
		}
		else if (ret == QMessageBox::No)
		{
			bcdate = date;
			b_date->setDate(QDate::currentDate());
			return;
		}
	}
	else if ((date > QDate::currentDate()) && (date == bcdate))//修正qtbug第二次进入
	{
		bcdate = QDate::currentDate();
		b_date->setDate(QDate::currentDate());
	}
	else if(date <= QDate::currentDate())
	{
		//bcdate = QDate::currentDate();不用管
		return;
	}
}