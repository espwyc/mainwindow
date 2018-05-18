#include "mainwindow.h"
int MAP = 0;
int tp = 0;
extern int userstatus;
extern int CheckUserStatus();

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowTitle("����Ŀ��׷�ٿ�������");
	/*���ݿ�*/
	mydb = new MySql_DB();
	/*�˵������*/
	m1 = new QMenu("�ļ�");
	m2 = new QMenu("�û�");
	m3 = new QMenu("����");
	m4 = new QMenu("��ѯ");
	m5 = new QMenu("����");
	m6 = new QMenu("����");
	me = new QMenu("����");
	mbar = new QMenuBar();
	mbar->addMenu(m1);
	m1_1 = new QAction();
	m1_1->setText("�˳�");
	m1->addAction(m1_1);
	m2_1 = new QAction();
	m2_2 = new QAction();
	m2_3 = new QAction();
	m2_1->setText("�û���¼");
	m2_2->setText("�û�ע��");
	m2_3->setText("�û�ע��");
	m2->addAction(m2_1);
	m2->addAction(m2_2);
	m2->addAction(m2_3);
	mbar->addMenu(m2);
	m3_1 = new QAction();
	m3_2 = new QAction();
	m3->addAction(m3_1);
	m3_1->setText("��ʼ����");
	//m3->addAction(m3_2);
	m3_2->setText("����");
	mbar->addMenu(m3);

	m4_1 = new QAction();
	m4_2 = new QAction();
	m4->addAction(m4_1);
	m4_1->setText("��ʷ��¼���");
	m4->addAction(m4_2);
	m4_2->setText("��ʷ��¼��ѯ");
	mbar->addMenu(m4);
	m5_1 = new QAction();
	m5_2 = new QMenu("��������");
	m5_1->setText("���ݿ�����");
	//m5_2->setText(");
	m5->addAction(m5_1);
	m5->addMenu(m5_2);
	//m5->addAction(m5_2);
	m5_2_1 = new QAction("��Ƶ���������޸�");
	m5_2_2 = new QAction("������Ƶ���ĵ�");
	m5_2->addAction(m5_2_1);
	m5_2->addAction(m5_2_2);
	mbar->addMenu(m5);
	mbar->addMenu(m6);
	m6_1 = new QAction("�鿴ʹ�ð���");
	m6_2 = new QAction("�û�����");
	m6_3 = new QAction("������");
	m6->addAction(m6_1);
	m6->addAction(m6_2);
	m6->addAction(m6_3);
	mbar->addMenu(me);
	me_1 = new QAction("����");
	me->addAction(me_1);
	this->setMenuBar(mbar);
	/*�˵������end*/
	/*�û������*/
	user_bar = new QHBoxLayout();
	user_bar_layout = new QVBoxLayout();
	ul1 = new QPushButton();
	ul1->setToolTip("�ļ�");
	ul2 = new QPushButton();
	ul2->setToolTip("�û�");
	ul3 = new QPushButton();
	ul3->setToolTip("����");
	ul4 = new QPushButton();
	ul4->setToolTip("�����ѯ");
	ul5 = new QPushButton();
	ul6 = new QPushButton();
	ul6->setToolTip("����");
	ul7 = new QPushButton();
	ul7->setToolTip("����״̬");
	up1 = new QIcon("icon/file.png");
	up2 = new QIcon("icon/user.png");
	up3 = new QIcon("icon/search.png");
	up4 = new QIcon("icon/calendar.png");
	up5 = new QIcon("icon/location.png");
	up6 = new QIcon("icon/setting.png");
	up7 = new QIcon("icon/pie_chart.png");
	ul1->setFixedSize(70, 70);
	ul2->setFixedSize(70, 70);
	ul3->setFixedSize(70, 70);
	ul4->setFixedSize(70, 70);
	ul5->setFixedSize(70, 70);
	ul6->setFixedSize(70, 70);
	ul7->setFixedSize(70, 70);
	ul1->setIcon(*up1);
	ul2->setIcon(*up2);
	ul3->setIcon(*up3);
	ul4->setIcon(*up4);
	ul5->setIcon(*up5);
	ul6->setIcon(*up6);
	ul7->setIcon(*up7);
	ul1->setIconSize(QSize(70, 70));
	ul2->setIconSize(QSize(70, 70));
	ul3->setIconSize(QSize(70, 70));
	ul4->setIconSize(QSize(70, 70));
	ul5->setIconSize(QSize(70, 70));
	ul6->setIconSize(QSize(70, 70));
	ul7->setIconSize(QSize(70, 70));
	user_bar->addStretch();
	user_bar->addWidget(ul1);
	//-user_bar->addStretch();
	user_bar->addWidget(ul2);
	//-user_bar->addStretch();
	user_bar->addWidget(ul3);
	//user_bar->addStretch();
	user_bar->addWidget(ul4);
	//user_bar->addStretch();
	user_bar->addWidget(ul5);
	//user_bar->addStretch();
	user_bar->addWidget(ul6);
	//user_bar->addStretch();
	user_bar->addWidget(ul7);
	user_bar->addStretch();
	user_bar_layout->addLayout(user_bar);
	user_bar_layout->addStretch();
	/*->setFixedHeight(270);
	imglab_mw->setFixedWidth(180);
	imglab_mw->setScaledContents(true);
	imglab->setFixedSize(100, 120);
	imglab->setScaledContents(true);
	pimg->load(QString::fromStdString(sql_row[3]));
	imglab->setPixmap(*pimg);*/
	/*�û������end*/
	/*״̬�����*/
	QWidget *spacer = new QWidget(this);
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	t1 = new QTimer();
	t1->start(500);
	sbar = new QStatusBar();
	sbar_l1 = new 	QLabel();
	sbar_l1->setText("ʱ��");
	sbar_l2 = new 	QLabel(" ���ݿ�״̬���ȴ���");
	sbar_l3 = new 	QLabel(" ����״̬��δ֪");
	sbar_le = new QLabel();
	sbar_l4 = new QLabel("��ͼ״̬���ȴ���");
	sbar_l5 = new QLabel("�û���δ��¼");
	sbar_le->setText("�����汾:V0.3.2");
	sbar->addWidget(sbar_l1, 0);
	sbar->addWidget(sbar_l2, 0);
	sbar->addWidget(sbar_l3, 0);
	sbar->addWidget(sbar_l4, 0);
	sbar->addWidget(sbar_l5, 0);
	sbar->addWidget(spacer, 1);
	sbar->addWidget(sbar_le, 0);
	this->setStatusBar(sbar);
	/*״̬�����end*/
	Int_Obj = new InteractObject(this);
	//	QGridLayout *ll =new QGridLayout();
#if (CW==0)
	cw = new correction(mydb);
	//cw = new correction(this);
#elif (CW==1)
	cw = new correction();
#endif
	cw->resize(600, 400);

	ntw = new NetWork();
	ntw->DB_pass_pter(mydb);
	sw = new search_w();
	rsw = new result_window();
	rsw->DB_pass_pter(mydb);

	scww = new search_wizard(mydb);
	stw = new status_w(mydb);
	userw = new user_w(mydb);
	usercw = new user_cw(mydb);

	picw = new picshow();

	tpw = new timepicker();

	dbsw = new dbsetting_w(mydb);

	ntsw = new netsetting_w(mydb);
	centalwidget = new QWidget();
	mainlayout = new QGridLayout();
	right_weblayout = new QGridLayout();
	rightlayout = new QVBoxLayout();
	label1 = new QLabel(tr("��ǩ1_leftlayout"));
	bottomlayout_button1 = new QPushButton(tr("ת����ַ��"));
	leftlayout_button1 = new QPushButton(tr("���ظߵµ�ͼ"));
	bottomlayout_testbutton = new QPushButton("��������");
	lineedit1 = new QLineEdit();
	bottom_test = new QHBoxLayout();
	bte1 = new QPushButton(tr("�����ַ�����js"));
	bteline = new QLineEdit();
	btelb = new QLabel();
	textbrowswer = new QTextBrowser();
	bottomlayput = new QHBoxLayout();//�ײ�layout
	leftlayout = new QVBoxLayout();//���layout
	webview = new QWebEngineView();//�Ҳ�web layout
	imglab_mw = new QLabel();

	pimg = new QPixmap();
	pimg->load("cover/cover.jpg");
	chkbox1 = new QCheckBox();
	chkbox2 = new QCheckBox();
	//correct_btn = new QPushButton();
	wrong_btn = new QPushButton();
	test_mysql_btn = new QPushButton();
	imgbutton = new QPushButton();

	test_showpath_btn = new QPushButton();

	/*-------------------------web-��-webchannel----------------------------------------------------*/

	webchannel = new QWebChannel();
	webchannel->registerObject(QStringLiteral("interactObj"), Int_Obj);
	webview->page()->setWebChannel(webchannel);

	if (MAP == 0)	//����Ĭ�ϵ�ͼ
	{
		webview->setUrl(QUrl("file:///map/testgod2cpy.html"));//ʹ����Ե�ַ		
		//webview->setUrl(QUrl("file:///map/test12.html"));//ʹ����Ե�ַ		
															  //label1->setText("�����汾��v0.3.2");
	}
	else
	{
		webview->setUrl(QUrl("file:///map/map_gaode.html"));//ʹ����Ե�ַ

	}
	/*-------------------------web-��-webchannel-------------------------end---------------------------*/

	//-----------------------��಼��-----------------------------------------------------------
	//label1->setFixedWidth(180);
	leftlayout_button1->setFixedWidth(180);
	bteline->setFixedWidth(180);
	bte1->setFixedWidth(180);
	btelb->setFixedWidth(180);
	hide_btn = new QPushButton("<<����");
	hide_btn->setFixedHeight(60);
	hide_btn->setFixedWidth(60);
	//leftlayout->addWidget(label1);
	//leftlayout->addWidget(leftlayout_button1);
	//leftlayout->addStretch();
	//leftlayout->addWidget(bstteline);
	//leftlayout->addWidget(bte1);
	//leftlayout->addWidget(btelb);
	//textbrowswer->setFixedWidth(10);
	textbrowswer->setFixedWidth(180);
	textbrowswer->setFixedHeight(111);
	leftlayout->addStretch();
	leftlayout->addWidget(textbrowswer);
	leftlayout->addWidget(imglab_mw);

	//btelb->setPixmap(*pimg);
	imglab_mw->setPixmap(*pimg);
	//img = img.scaled(400, 400);
	imglab_mw->setFixedHeight(270);
	imglab_mw->setFixedWidth(180);
	imglab_mw->setScaledContents(true);
	
	//correct_btn->setText("��ȷ");
	//correct_btn->setFixedWidth(180);
	wrong_btn->setText("����");
	wrong_btn->setFixedWidth(180);
	//leftlayout->addWidget(correct_btn);
	leftlayout->addWidget(wrong_btn);
	leftlayout->addWidget(hide_btn);
	//imglab->setPixmap();
	/*test_mysql_btn->setText("ͨ��ģ����Ե������");
	test_mysql_btn->setFixedWidth(180);
	leftlayout->addWidget(test_mysql_btn);*/
	//test_showpath_btn->setText("����·����ʾ");
	//test_showpath_btn->setFixedWidth(180);
	//leftlayout->addWidget(test_showpath_btn);
	leftlayout->addStretch();
	imglab_mw->installEventFilter(this);
	hide_btn_clicked(0);
	//-----------------------��಼��-------------------end----------------------------------------


	//----------------------------������ҳ��ʾ�ĵĲ���----------------------------------
	right_weblayout->addWidget(webview, 0, 0);
	//----------------------------������ҳ��ʾ�ĵĲ���------------end----------------------

	//-----------------------�ײ�����-----------------------------------------------------------
	/*bottomlayput->addWidget(bottomlayout_button1);
	bottomlayput->addWidget(lineedit1);
	bottomlayput->addStretch();
	bottomlayput->addWidget(bottomlayout_testbutton);*/
	//-----------------------�ײ�����----------end-------------------------------------------------

	//-----------------------�ײ����Բ���-----------------------------------------------------------
	/*bottom_test = new QHBoxLayout();
	bte1 = new QPushButton(tr("�����ַ�����js"));
	bteline = new QLineEdit();
	btelb = new QLabel();*/
	/*bottom_test->addWidget(bteline);
	bottom_test->addWidget(bte1);
	bottom_test->addWidget(btelb);*/
	//-----------------------�ײ����Բ���----------end-------------------------------------------------

/*�Ҳ಼��*/
	rightlayout->addWidget(ul1);
	rightlayout->addWidget(ul2);
	rightlayout->addWidget(ul3);
	rightlayout->addWidget(ul4);
	rightlayout->addWidget(ul5);
	rightlayout->addWidget(ul6);
	rightlayout->addWidget(ul7);
	rightlayout->addStretch();
/*�Ҳ಼��end*/
	//-----------------------���岼��-----------------------------------------------------------




	mainlayout->addLayout(right_weblayout, 0, 0, 1, 1);
	//mainlayout->addLayout(user_bar_layout, 0, 0, 1, 1);
	mainlayout->addLayout(leftlayout, 0, 0, 1, 1);

	//mainlayout->addLayout(bottomlayput, 2, 0, 1, 1);
	mainlayout->addLayout(rightlayout, 0, 1, 1,1 );
	//mainlayout->addLayout(bottom_test, 2, 0, 1, 2);
	centalwidget->setLayout(mainlayout);
	this->setCentralWidget(centalwidget);
	this->resize(1184, 666);
	//QGridLayout *mainLayout = new QGridLayout(this);
	//ʵ�������֣�ָ��������this,Ҳ�ɵ���this->setLayout(mainLayout)ʵ��
	//-----------------------���岼��-----------end------------------------------------------------


	//this->setLayout(g1);
	//setCentralWidget();
	//mainLayout->setMargin(15);//�趨�Ի���ı߾�Ϊ15
	//mainLayout->setSpacing(10);
	//mainLayout->addLayout(g1, 0, 0);

	/**************************************************************************************/
	/**************************************************************************************/
	/*--------------------------��----------------------------------------------------*/
	/**************************************************************************************/

	connect(bottomlayout_button1, SIGNAL(clicked()), this, SLOT(bb1_clicked()));
	//connect(webview, SIGNAL(urlchanged(QUrl)), this, SLOT(web_url_changed(QUrl)));
	connect(leftlayout_button1, SIGNAL(clicked()), this, SLOT(lb1_clicked()));
	connect(webview, SIGNAL(urlChanged(QUrl)), this, SLOT(Web_Jump(QUrl)));
	//connect(bottomlayout_testbutton, SIGNAL(clicked()), this, SLOT(bbt_clicked()));
	connect(bte1, SIGNAL(clicked()), this, SLOT(bte_clicked()));
	//connect(correct_btn, SIGNAL(clicked()), this, SLOT(correct_btn_clicked()));
	connect(wrong_btn, SIGNAL(clicked()), this, SLOT(wrong_btn_clicked()));
	connect(hide_btn, SIGNAL(clicked()), this, SLOT(hide_btn_clicked()));
	connect(cw, SIGNAL(cw_but1(const QString &)), this, SLOT(test_wd(const QString &)));
	//connect(this, SIGNAL(testemit()), this, SLOT(test_wd()));
	//cw->show();
	//connect(imglab, SIGNAL(Clicked()), this, SLOT(pic_show()));
	//connect(cw->imglab, SIGNAL(clicked()), this, SLOT(pic_show()));
	connect(cw, SIGNAL(picw_show()), this, SLOT(pic_show()));
	connect(test_mysql_btn, SIGNAL(clicked()), this, SLOT(test_mysql_btn_clicked()));
	connect(test_showpath_btn, SIGNAL(clicked()), this, SLOT(test_showpath_btn_clicked()));
	connect(t1, SIGNAL(timeout()), this, SLOT(sta_tl_update()));
	connect(m1_1, SIGNAL(triggered()), this, SLOT(m1_1_triggered()));
	connect(m2_1, SIGNAL(triggered()), this, SLOT(m2_1_triggered()));
	connect(m2_2, SIGNAL(triggered()), this, SLOT(m2_2_triggered()));
	connect(m2_3, SIGNAL(triggered()), this, SLOT(m2_3_triggered()));
	connect(m3_1, SIGNAL(triggered()), this, SLOT(m3_1_triggered()));
	connect(m3_2, SIGNAL(triggered()), this, SLOT(m3_2_triggered()));
	connect(m4_1, SIGNAL(triggered()), this, SLOT(m4_1_triggered()));
	connect(m4_2, SIGNAL(triggered()), this, SLOT(m4_2_triggered()));
	connect(m5_1, SIGNAL(triggered()), this, SLOT(m5_1_triggered()));
	connect(m5_2_1, SIGNAL(triggered()), this, SLOT(m5_2_triggered()));
	connect(m5_2_2, SIGNAL(triggered()), this, SLOT(addvideocenterw()));
	connect(m6_1, SIGNAL(triggered()), this, SLOT(m6_1_triggered()));
	connect(me_1, SIGNAL(triggered()), this, SLOT(AboutDialog()));
	connect(ul1, SIGNAL(clicked()), this, SLOT(ul1_clicked()));
	connect(ul2, SIGNAL(clicked()), this, SLOT(ul2_clicked()));
	connect(ul3, SIGNAL(clicked()), this, SLOT(ul3_clicked()));
	connect(ul4, SIGNAL(clicked()), this, SLOT(ul4_clicked()));
	connect(ul5, SIGNAL(clicked()), this, SLOT(ul5_clicked()));
	connect(ul6, SIGNAL(clicked()), this, SLOT(ul6_clicked()));
	connect(ul7, SIGNAL(clicked()), this, SLOT(ul7_clicked()));
	connect(sw, SIGNAL(SubmitQuerry(struct QuerryStruct &)), ntw, SLOT(SubmitQuerry(struct QuerryStruct &)));
	connect(ntw, SIGNAL(show_result_byid(const QString &)), this, SLOT(ShowSearchResult(const QString &)));
	connect(rsw, SIGNAL(show_result_byid(const QString &)), this, SLOT(ShowResultByPicId(const QString &)));
	connect(scww,SIGNAL(SubmitQuerry(struct QuerryStruct &)), ntw, SLOT(SubmitQuerry(struct QuerryStruct &)));
	connect(scww, SIGNAL(SubmitQuerry(struct QuerryStruct &)), this, SLOT(SubmitQuerry(struct QuerryStruct &)));
	connect(cw, SIGNAL(SubmitQuerry(struct QuerryStruct &)), ntw, SLOT(SubmitQuerry(struct QuerryStruct &)));
	connect(tpw, SIGNAL(ShowResultWithTimeSpan(const QString &)), this, SLOT(result_withspan(const QString &)));
	/*--------------------------��------------end----------------------------------------*/
	/**************************************************************************************/

}

MainWindow::~MainWindow()
{
}
void MainWindow::bte_clicked()
{
	QString text = bteline->text();
	Int_Obj->sendStringToHtml(text);
}

void MainWindow::bb1_clicked()
{
	//std::cout << "hello world" << std::endl;
	/*QMessageBox msg;
	msg.setText();
	msg.exec();*/
	//webview->setUrl(lineedit1->text());
	//webview->urlChanged(lineedit1->text());
	//webview->load(QUrl(lineedit1->text()));
	right_weblayout->removeWidget(webview);
	webview->deleteLater();
	webview = new QWebEngineView();
	right_weblayout->addWidget(webview);
	webview->setUrl(lineedit1->text());
	webview->show();
	//webview->reload();
	//var map = new AMap.Map('container', { pitch:75, viewMode : '3D', zoom : 17, expandZoomRange : true, zooms : [3,20], center : [116.333926,39.997245] });
}
void MainWindow::lb1_clicked()
{
	QString url;
	if (MAP == 0)
	{
		url = "file:///map/map_gaode.html";
		label1->setText("��ǰʹ�øߵµ�ͼ");
		leftlayout_button1->setText("���ذٶȵ�ͼ");
		MAP = 1;

	}
	else
	{
		url = "file:///map/map_baidu.html";
		leftlayout_button1->setText("���ظߵµ�ͼ");
		label1->setText("��ǰʹ�ðٶȵ�ͼ");
		MAP = 0;
	}

	right_weblayout->removeWidget(webview);
	webview->deleteLater();
	webview = new QWebEngineView();
	right_weblayout->addWidget(webview);
	webview->setUrl(QUrl(url));
	label1->setText(url);
	webview->show();
}
void MainWindow::Web_Jump(const QUrl &url)
{
	/*QMessageBox msg;
	msg.setText(url.toString());
	msg.exec();*/
}
void MainWindow::bbt_clicked()
{
	emit testemit();
	/*QMessageBox msg;
	msg.setText("emit");
	msg.exec();*/

	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Spreadsheet"), ".",
		tr("Spreadsheet files (*.sp)"));

	//webview->page()->runJavaScript("showAlert()");
	//var map = new AMap.Map('container', { pitch:75, viewMode : '3D', zoom : 17, expandZoomRange : true, zooms : [3,20], center : [116.333926,39.997245] });
	//QWebFrame *webFrame = ui->webView->page()->mainFrame();
	//QString cmd = QString("showAddress(\"%1\",\"%2\")").arg(lon).arg(lat);
	//webFrame->evaluateJavaScript(cmd);
	/*QString url;
	url = "file:///map/test.html";
	label1->setText("��ǰʹ�ò���ҳ��");
	leftlayout_button1->setText("���ذٶȵ�ͼ");
	MAP = 1;

	right_weblayout->removeWidget(webview);
	webview->deleteLater();
	webview = new QWebEngineView();
	webchannel = new QWebChannel();
	webchannel->registerObject(QStringLiteral("interactObj"), Int_Obj);
	webview->page()->setWebChannel(webchannel);

	right_weblayout->addWidget(webview);
	webview->setUrl(QUrl(url));
	label1->setText(url);
	webview->show();
	*/
}
/*��ʱ�����������js�˵ĺ���*/
void MainWindow::RcvFromWeb(const QString &text)
{
	/*˵���������ͼˮ�ε�mousemoveon�¼��Ĳۺ���*/
	js_flag = 1;
	sbar_l4->setText("��ͼ״̬��������");
	//btelb->setText(text);
	//textbrowswer->setText(text);
#ifdef SSMSG
	msg.setText(text);
	msg.exec();
#endif
	int i = 0;
	for (auto a : loca)
	{
		if (0 == QString::compare(a, text))//�ַ�����ͬ
		{
			pimg->load(picpath[i]); cw->pimg_load(picpath[i]); picw->picw_load(picpath[i]);
			CurrentFace.path = picpath[i];
			CurrentFace.location = loca[i];
			CurrentFace.zipcode = zipcodes[i];
			textbrowswer->setText("����ʱ�� " + aptime[i] + "\n���ֵص� " + loca[i]);
			hide_btn_clicked(1);
			break;
		}
		cw->pass_faceinfo(CurrentFace);
		i++;
	}
	imglab_mw->setPixmap(*pimg);
}
//void MainWindow::correct_btn_clicked()
//{
//	/*QMessageBox msg;
//	msg.setText(mysql);
//	msg.exec();
//	//mysql_test();*/
//}
void MainWindow::hide_btn_clicked(int sig)
{
	//leftlayout->addWidget(textbrowswer);
	//leftlayout->addWidget(imglab_mw);
	//leftlayout->addWidget(correct_btn);
	//leftlayout->addWidget(wrong_btn);
	//leftlayout->addWidget(hide_btn);
	static bool flag = true;// true show false hide
	if (sig == 1)
	{
		flag = false;
	}
	if (flag)
	{
		textbrowswer->hide();
		imglab_mw->hide();
		//correct_btn->hide();
		wrong_btn->hide();
		hide_btn->setText("��ʾ>>");
		flag = false;
	}
	else
	{
		textbrowswer->show();
		imglab_mw->show();
		//correct_btn->show();
		wrong_btn->show();
		hide_btn->setText("<<����");
		flag = true;
	}
}
void MainWindow::wrong_btn_clicked()
{
	/*QMessageBox msg;
	msg.setText("����");
	msg.exec();*/
	//correction *w1 = new correction(this);
	//w1->show();
	//cw = new correction(this);
	//cw->pimg->load("img/img3.jpg");
 #ifdef SSMSG
	QMessageBox msg;
	msg.setText("picid"+CurrentFace.pic_id+"loca"+CurrentFace.location);
	msg.exec();
#endif
	//cw->correction_info(CurrentFace.pic_id, CurrentFace.location);
	cw->pass_faceinfo(CurrentFace);
	cw->show();
	
	//????
			   //w1.show();
			   /*QWidget *window = new QWidget(this);
			   window->resize(300, 200);
			   //window->show();
			   window->show();*/
			   //msg.exec();
			   //w1->exec();
	//for (auto a : loca)
	//{
	//	if (0 == QString::compare(a, text))//�ַ�����ͬ
	//	{
	//		pimg->load(picpath[i]); cw->pimg_load(picpath[i]); picw->picw_load(picpath[i]);
	//		textbrowswer->append(aptime[i]);
	//		break;
	//	}
	//	i++;
	//}
}
void MainWindow::test_wd(const QString &text)
{
#ifdef SSMSG
	textbrowswer->setText(text);
	QMessageBox msg;
	msg.setText("testbutton_emit_work");
	msg.exec();
#endif
}
void MainWindow::pic_show()
{
	picw->show();
	//sw->show();
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == imglab_mw)
	{

		if (event->type() == QEvent::MouseButtonPress)
		{
			/*QMessageBox::information(NULL, "���", "�������",
			QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			*/
			pic_show();
			return true;
		}
		else return false;
	}
	else
	{
		//return QObject::eventFilter(obj, event);
		return QMainWindow::eventFilter(obj, event);
	}
	return false;
}
void MainWindow::test_mysql_btn_clicked()
{
	//-sqpannel->show();
	ntw->show();
	sw->show();
	rsw->show();
}
void MainWindow::test_showpath_btn_clicked()
{
	picpath = mydb->read_resultPICPATH_bypicid(QString::number(1182, 10));
	loca = mydb->read_resultLOCATION_bypicid(QString::number(1182, 10));
	aptime = mydb->read_resultAPTIME_bypicid(QString::number(1182, 10));
	for (int i = 0; i < loca.size(); i++)
	{
		Int_Obj->sendStringToHtml(loca[i]);
		textbrowswer->append("loc:" + loca[i] + " aptime:" + aptime[i] + "picpath:" + picpath[i]+"zipcode"+zipcodes[i]);
	}
	//Int_Obj->sendStringToHtml("cmd:showpath");
}
void MainWindow::sta_tl_update()
{
	stw->update_status(ipaddr);
	QDateTime tmp = QDateTime::currentDateTime();
	QString tmp1 = tmp.toString("yyyy��M��d�� ddd hh:mm:ss");
	sbar_l1->setText(tmp1);
	if (mydb != NULL&&mydb->connection_flag == true)
	{
		sbar_l2->setText("���ݿ�״̬��������");
	}
	else if (mydb != NULL&&mydb->connection_flag == false)
	{
		sbar_l2->setText("���ݿ�״̬��δ����");
	}
	if (ntw->flag == 0)
	{
		sbar_l3->setText("����״̬���ѽ����ͻ���");
	}
	else if (ntw->flag == 1)
	{
		sbar_l3->setText("����״̬��������");
	}
	else if (ntw->flag == -1)
	{
		sbar_l3->setText("����״̬���ȴ���");
	}
	if (userstatus == 1)
	{
		sbar_l5->setText("�û����ѵ�½");
	}
	else
	{
		sbar_l5->setText("�û���δ��½");
	}

}
void MainWindow::m1_1_triggered()
{
#ifdef SSMSG
	msg.setText("�˳�����");
	msg.exec();
#endif
	this->close();
}
void MainWindow::m2_1_triggered()
{
#ifdef SSMSG
	msg.setText("��¼����");
	msg.exec();
#endif
	if (userstatus==0)
	{
		userw->show();
	}
	else if (userstatus == 1)
	{
		QMessageBox msg1;
		msg1.setWindowTitle("����");
		msg1.setText("�ѵ�½�������ظ���½��");
		msg1.exec();
	}
}
void MainWindow::m2_2_triggered()
{
	if (CheckUserStatus() == 1)
	{
		QMessageBox msg1;
		//msg1.set
		auto ret = msg1.warning(NULL, "ע��",
			/**/	"��ǰ�û��ѵ�½���Ƿ�ע����",/**/
			/**/	QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);/**/
		if (ret == QMessageBox::Yes)
		{
			userstatus = 0;
			return;
		}
		else if (ret == QMessageBox::No)
		{
			return;
		}
	}
	else
	{
		QMessageBox msg1;
		msg1.setText("��ע���������ظ�ע����");
	}
}
void MainWindow::m2_3_triggered()
{
		usercw->show();
}
void MainWindow::m3_1_triggered()
{
	//sw->show();
	if (CheckUserStatus() != 1) return;
	else
	{
		scww->~search_wizard();
		scww = new search_wizard(mydb);
		connect(scww, SIGNAL(SubmitQuerry(struct QuerryStruct &)), ntw, SLOT(SubmitQuerry(struct QuerryStruct &)));
		connect(scww, SIGNAL(SubmitQuerry(struct QuerryStruct &)), this, SLOT(SubmitQuerry(struct QuerryStruct &)));
		scww->show();
	}
}
void MainWindow::m3_2_triggered()
{
	if (CheckUserStatus() != 1) return;
	else cw->show();
}
void MainWindow::m4_1_triggered()
{
	if (CheckUserStatus() != 1) return;
	else rsw->show();
}
void MainWindow::m4_2_triggered()
{
	if (CheckUserStatus() != 1) return;
	else tpw->show();
}
void MainWindow::m5_1_triggered()
{
#ifdef SSMSG
	msg.setText("���ݿ�����");
	msg.exec();
#endif
	dbsw->show();
}
void MainWindow::m5_2_triggered()
{
#ifdef SSMSG
	msg.setText("��������");
	msg.exec();
#endif
	if (CheckUserStatus() != 1) return;
	ntsw->show();
}
void MainWindow::m6_1_triggered()
{
	QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}
void MainWindow::ShowSearchResult(const QString &picid)
{
	//QMessageBox msg1;
	//auto ret = msg1.warning(NULL, "ע��",
	//	/**/	"�յ����¼���������Ƿ�չʾ��",/**/
	//	/**/	QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);/**/
	//if (ret == QMessageBox::Yes)
	{
		ShowResultByPicId(picid);
		return;
	}
	/*else if (ret == QMessageBox::No)
	{
		return;
	}*/
}

void MainWindow::ShowResultByPicId(const QString  &picid)
{
	/*msg.setText("111");
	msg.exec();*/
	
	CurrentFace.pic_id = picid;
	Int_Obj->sendStringToHtml("cmd:clearmarker");
	picpath = mydb->read_resultPICPATH_bypicid(picid);
	//msg.setText(picpath[0]);
	//msg.exec();
	loca = mydb->read_resultLOCATION_bypicid(picid);

	aptime = mydb->read_resultAPTIME_bypicid(picid);

	zipcodes = mydb->read_resultZIPCODE_bypicid(picid);

	similarity = mydb->read_resultPICSIMILARITY_bypicid(picid);
	////CurrentFace.path = picpath;
	for (int i = 0; i < loca.size(); i++)
	{
		//msg.setText(loca[i]);
		//msg.exec();
#ifdef SSMSG
		msg.setText(QString::number(similarity[i].toInt(),10));
		msg.exec();
#endif
		if (similarity[i].toInt()>1500)//��ֵ
		{
			continue;
		}
		Sleep(200);
		Int_Obj->sendStringToHtml(loca[i]);
		//textbrowswer->append("loc:" + loca[i] + " aptime:" + aptime[i] + "picpath:" + picpath[i]+"zipcode"+zipcodes[i]);
	}
	Sleep(1500);
	Int_Obj->sendStringToHtml("cmd:showpath");
}
void MainWindow::ul1_clicked()
{

}
void MainWindow::ul2_clicked()
{
	if (userstatus!= 1) 
	{
		userw->show();
	}
	else
	{
		QMessageBox msg1;
		auto ret = msg1.warning(NULL, "ע��",
			/**/	"��ǰ�û��ѵ�½���Ƿ�ע����",/**/
			/**/	QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);/**/
		if (ret == QMessageBox::Yes)
		{
			userstatus = 0;
			return;
		}
		else if (ret == QMessageBox::No)
		{
			return;
		}
	}
}
void MainWindow::ul3_clicked()
{
	if (CheckUserStatus() != 1) return;
	//sw->show();
	scww->show();
}
void MainWindow::ul4_clicked()
{
	if (CheckUserStatus() != 1) return;
	rsw->show();
}
void MainWindow::ul5_clicked()
{
	if (CheckUserStatus() != 1) return;
	//ntw->show();
}
void MainWindow::ul6_clicked()
{
	if (CheckUserStatus() != 1) return;
	ntsw->show();
	//cw->show();
}
void MainWindow::ul7_clicked()
{
	if (CheckUserStatus() != 1) return;
	stw->show();
	//scww->show();

}
void MainWindow::result_withspan(const QString &ts)
{
#ifdef SSMSG
	QMessageBox msg1;
	msg1.setText(ts);
	msg1.exec();
#endif
	rsw->reload_querry(ts);
	rsw->show();
}
void MainWindow::addvideocenterw()
{
	if (CheckUserStatus() != 1) return;
	QDialog dg;
	dg.resize(400, 300);
	dg.setWindowTitle("������Ƶ��");
	QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	QGridLayout mainl;
	QLabel l1("����ip��ַ/ӳ��˿�");
	QLabel l2("����������������");
	QLineEdit le1("10000");
	QLineEdit le2("-1");
	mainl.addWidget(&l1, 0, 0, 1, 1);
	mainl.addWidget(&le1, 0, 1, 1, 1);
	mainl.addWidget(&l2, 1, 0, 1, 1);
	mainl.addWidget(&le2, 1, 1, 1, 1);
	mainl.addWidget(&buttonBox, 3, 1, 1, 1);
	connect(&buttonBox, SIGNAL(accepted()), &dg, SLOT(accept()));
	connect(&buttonBox, SIGNAL(rejected()), &dg, SLOT(reject()));
	dg.setLayout(&mainl);
	if (dg.exec() == QDialog::Accepted)
	{
	//	if (le2.text()!="")
		{
			QString cmd = "insert into iptable (ip,parentcode) values ('" + le1.text() + "',"+le2.text()+") ;";
			if (mydb->mysql_cmd(cmd.toStdString()))
			{
				QMessageBox msg1;
				msg1.setText("�����ɹ���\n��������ϵͳ");
				msg1.exec();
				dg.close();
			}
			else
			{
				QMessageBox msg1;
				msg1.setText("����ʧ�ܣ��������ݿ�");
				msg1.exec();
			}
		}
	}
	else
	{
		dg.close();
	}
}
void MainWindow::AboutDialog()
{
	if (CheckUserStatus() != 1) return;
	QDialog dg;
	dg.resize(220, 160);
	dg.setWindowTitle("����");
	QLabel l1("����Ŀ��׷�ٿ�������");
	l1.setFont(QFont("Microsoft YaHei", 20, QFont::Normal));
	QLabel l2("�汾v0.3.1");
	QGridLayout ml;
	ml.addWidget(&l1);
	ml.addWidget(&l2);
	dg.setLayout(&ml);
	dg.exec();
}
void MainWindow::SubmitQuerry(struct QuerryStruct &QS)
{
	ipaddr = QS.ipArr;
	stw->show();
}
void MainWindow::Show_Status()
{
}