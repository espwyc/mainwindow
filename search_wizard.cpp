#include "search_wizard.h"

page_1::page_1(MySql_DB *base, QWizard * parent) :QWizardPage(parent)
{
	txtb = new QTextBrowser();
	this->setTitle("������");
	this->setSubTitle("��ѡ�������Ƶ����");
	QStringList header;
	header << "��Ƶ����" <<"���"<<"ip��ַ/ӳ��˿ں�"<< "״̬" << "��ʱ";
	label = new QLabel("ѡ����Ƶ����");
	layout = new QVBoxLayout;
	tree = new QTreeWidget();
	layout->addWidget(label);
	layout->addWidget(tree);
	tree->setHeaderLabels(header);
	tree->setColumnCount(5);
	tree->setColumnWidth(0, 300);
	tree->setColumnWidth(1, 100);
	tree->setColumnWidth(2, 200);
	tree->setColumnWidth(3, 100);
	//QTreeWidgetItem *group1 = new QTreeWidgetItem(tree);
	//group1->setText(0, "group1");
	//group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	//group1->setCheckState(0, Qt::Unchecked);
	//QTreeWidgetItem *subItem11 = new QTreeWidgetItem(group1);

	//subItem11->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	//subItem11->setText(0, "subItem11");
	//subItem11->setCheckState(0, Qt::Unchecked);
	//QTreeWidgetItem *ss1 = new QTreeWidgetItem(subItem11);
	//ss1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	//ss1->setText(0, "ss1");
	//ss1->setCheckState(0, Qt::Unchecked);
	//QTreeWidgetItem *subItem12 = new QTreeWidgetItem(group1);
	//subItem12->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	//subItem12->setText(0, "subItem12");
	//subItem12->setCheckState(0, Qt::Unchecked);
	//QTreeWidgetItem *subItem13 = new QTreeWidgetItem(group1);
	//subItem13->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	//subItem13->setText(0, "subItem13");
	//subItem13->setCheckState(0, Qt::Unchecked);
	//QTreeWidgetItem *subItem14 = new QTreeWidgetItem(group1);
	//subItem14->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	//subItem14->setText(0, "subItem14");
	//subItem14->setCheckState(0, Qt::Unchecked);
	//�ڶ�������
	group2 = new QTreeWidgetItem(tree);
	group2->setText(0, "��Ƶ����");
	//group2->setText(1, "0");
	group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	group2->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem *tmpt;
	QString cmd = "select * from iptable order by code asc ;";
	MYSQL_RES res = base->sql_cmd_rresult(cmd.toStdString());
	MYSQL_ROW sql_row;
	while (sql_row = mysql_fetch_row(&res))
	{
		tmpt = new QTreeWidgetItem(group2);
		tmpt->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
		tmpt->setCheckState(0, Qt::Unchecked);
		tmpt->setText(0, sql_row[5]);
		tmpt->setText(1, sql_row[0]);
		tmpt->setText(2, sql_row[1]);
	}
/*QTreeWidgetItem *group2 = new QTreeWidgetItem(tree);
	group2->setText(0, "����");
	group2->setText(1, "0");
	group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	group2->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem *subItem21 = new QTreeWidgetItem(group2);
	subItem21->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem21->setText(0, "������Ƶ����1");
	subItem21->setText(1, "-1");
	subItem21->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem *subItem22 = new QTreeWidgetItem(group2);
	subItem22->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem22->setText(0, "������Ƶ����2");
	subItem22->setText(1, "-2");
	subItem22->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem *subItem23 = new QTreeWidgetItem(group2);
	subItem23->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem23->setText(0, "������Ƶ����3");
	subItem23->setText(1, "-3");
	subItem23->setCheckState(0, Qt::Unchecked);*/
	//��3������
	QTreeWidgetItem *group3 = new QTreeWidgetItem(tree);
	group3->setText(0, "�й�");
	group3->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	group3->setCheckState(0, Qt::Unchecked);


	if (base != NULL&&base->connection_flag == true)
	{
		struct address_node *graph = base->init_addr_graph();
		QTreeWidgetItem *tmp1;
		QTreeWidgetItem *tmp2;
		QTreeWidgetItem *tmp3;
		//QTreeWidgetItem *tmp4;
		struct address_node *level1;
		struct address_node *level2;
		struct address_node *level3;
		struct address_node *level4;
		level1 = graph;
		while (level1->next!= NULL&&level1 !=NULL)
		{
			level1 = level1->next;//ȥ��һ����ͷ�ڵ�������
			tmp1 = new QTreeWidgetItem(group3);
			tmp1->setText(0, level1->name);
			tmp1->setText(1, QString::number(level1->code,10));
			//tmp1->setText(2, QString::number(level1->id, 10));
			//tmp1->setText(3, QString::number(level1->level,10));
			tmp1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
			tmp1->setCheckState(0, Qt::Unchecked);
			level2 = level1->child;
			while (level2->next != NULL&&level2 != NULL)
			{
				level2 = level2->next;//ȥ��һ����ͷ�ڵ�������
				tmp2 = new QTreeWidgetItem(tmp1);//tmp1Ϊ�ϲ�
				tmp2->setText(0, level2->name);
				tmp2->setText(1, QString::number(level2->code, 10));
				//tmp2->setText(2, QString::number(level2->id, 10));
				//tmp2->setText(3, QString::number(level2->level, 10));
				tmp2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
				tmp2->setCheckState(0, Qt::Unchecked);
				level3 = level2->child;
				while (level3->next != NULL&&level3 != NULL)
				{
					level3 = level3->next;//ȥ��һ����ͷ�ڵ�������
					tmp3 = new QTreeWidgetItem(tmp2);//tmp1Ϊ�ϲ�
					tmp3->setText(0, level3->name);
					tmp3->setText(1, QString::number(level3->code, 10));
					//tmp3->setText(2, QString::number(level3->id, 10));
					//tmp3->setText(3, QString::number(level3->level, 10));
					tmp3->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
					tmp3->setCheckState(0, Qt::Unchecked);
					//level4 = level3->child;
					//while (level4->next != NULL&&level4 != NULL)//4����ַ
					//{
					//	level4 = level4->next;//ȥ��һ����ͷ�ڵ�������
					//	tmp4 = new QTreeWidgetItem(tmp3);//tmp1Ϊ�ϲ�
					//	tmp4->setText(0, level4->name);
					//	tmp4->setText(1, QString::number(level4->code, 10));
					//	tmp4->setText(2, QString::number(level4->id, 10));
					//	tmp4->setText(3, QString::number(level4->level, 10));
					//	tmp4->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
					//	tmp4->setCheckState(0, Qt::Unchecked);
					//}
				}
			}
		}
	}
#ifdef SSMSG
	layout->addWidget(txtb);
#endif
	connect(tree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
	connect(tree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SIGNAL(tree_item_changed(QTreeWidgetItem*, int)));
	this->setLayout(layout);
}

void page_1::updateChildItem(QTreeWidgetItem* item, int CheckState)
{
	int count=item->childCount();
	for (int i = 0; i < count; i++)
	{
		item->child(i)->setCheckState(0, (CheckState==0? Qt::Checked: Qt::Unchecked));
		if (item->child(i)->childCount() > 0)//�����child
		{
			updateChildItem(item->child(i),CheckState);
		}
	}
}
void page_1::treeItemChanged(QTreeWidgetItem* item, int column)
{
	disconnect(tree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
	disconnect(tree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SIGNAL(tree_item_changed(QTreeWidgetItem*, int)));

	QString itemText = item->text(0);
	label->setText(itemText);
	//ѡ��ʱ
	if (Qt::Checked == item->checkState(0))
	{
		QTreeWidgetItem* parent = item->parent();
		int count = item->childCount();
		if (count > 0)
		{
			updateChildItem(item,0);
		}
			//���¸��ڵ�
			updateParentItem(item);
	}
	else if (Qt::Unchecked == item->checkState(0))
	{
		int count = item->childCount();
		if (count > 0)
		{
			updateChildItem(item, 1);
		}
			updateParentItem(item);
	}
	QTreeWidgetItemIterator it(tree, QTreeWidgetItemIterator::Checked);
	while (*it)
	{
		txtb->append("selected " + (*it)->text(0));
		++it;
	}
	connect(tree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
	connect(tree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SIGNAL(tree_item_changed(QTreeWidgetItem*, int)));
	emit TreeUpdateFinished();
}
void page_1::updateParentItem(QTreeWidgetItem* item)
{
	QTreeWidgetItem *parent = item->parent();
	if (parent == NULL)
	{
		return;
	}
	//ѡ�е��ӽڵ����
	int selectedCount = 0;
	int childCount = parent->childCount();
	for (int i = 0; i < childCount; i++)
	{
		QTreeWidgetItem *childItem = parent->child(i);
		if (childItem->checkState(0) == Qt::Checked)
		{
			selectedCount++;
		}
	}
	if (selectedCount <= 0)
	{
		//δѡ��״̬
		parent->setCheckState(0, Qt::Unchecked);
	}
	else if (selectedCount > 0 && selectedCount < childCount)
	{
		//����ѡ��״̬
		parent->setCheckState(0, Qt::PartiallyChecked);
	}
	else if (selectedCount == childCount)
	{
		//ѡ��״̬
		parent->setCheckState(0, Qt::Checked);
	}
}
QTreeWidget * page_1::pass_tree_ptr()
{
	return tree;
}


page_1::~page_1()
{

}


page_2::page_2(MySql_DB *DB,search_wizard *f_p,QWizard * parent) :QWizardPage(parent)
{
	//button()
	//QWizard::NextButton
	//this->wizard()->button(QWizard::NextButton)->setEnabled(false);
	//parent->button(QWizard::NextButton)->setEnabled(false);
	//PW = parent;
	base = DB;
	/*setTitle(tr("Evaluate <i>Super Product One</i>&trade;"));
	setSubTitle(tr("Please fill both fields. Make sure to provide a valid "
		"email address (e.g., john.smith@example.com)."));*/
	this->setTitle("������");
	this->setSubTitle("ѡ��Ŀ����Ƭ�ͼ�������");
	setButtonText(QWizard::NextButton, "ȷ������");
	//connect(, SIGNAL(clicked()), this, SLOT(SBQTWiardButtonClicked()));
	//nameLabel = new QLabel(tr("N&ame:"));
	//nameLineEdit = new QLineEdit;
	//! [20]
	//nameLabel->setBuddy(nameLineEdit);
/*page2::timer*/
	timer1 = new QTimer();
	timer1->start(400);
	connect(timer1, SIGNAL(timeout()), this, SLOT(update_status()));
/*page2::timer end*/
	txtb = new QTextBrowser();
	sel_pic_btn = new QPushButton();
	confirm_btn = new QPushButton();
	b_date = new QDateEdit(QDate::currentDate());
	//b_date->setMaximumDate(QDate::currentDate());
	b_date->setMinimumDate(QDate::fromString("1970-01-01", "yyyy-MM-dd"));
	e_date = new QDateEdit(QDate::currentDate());
	e_date->setMinimumDate(QDate::fromString("1970-01-01", "yyyy-MM-dd"));
	b_time = new QTimeEdit(QTime::currentTime());
	e_time = new QTimeEdit(QTime::currentTime());
	imglab_sw = new QLabel();
	pimg = new QPixmap();
	b_group = new QGroupBox();
	e_group = new QGroupBox();
	//btm_group = new QGroupBox();
	e_layout = new QVBoxLayout();
	b_layout = new QVBoxLayout();
	rightlayout = new QHBoxLayout();
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
	/*��಼��*/
	//imglab->setFixedHeight(300);
	//imglab->setFixedWidth(185);
	imglab_sw->setMinimumWidth(600);
	imglab_sw->setMinimumHeight(370);
	imglab_sw->setMaximumWidth(1000);
	imglab_sw->setMaximumHeight(618);

	imglab_sw->resize(400, 247);
	//imglab_sw->setFixedSize(600, 370);
	//imglab->setSizePolicy(GrowFlag);
	imglab_sw->setScaledContents(true);
	pimg->load("cover/cover.jpg");

	imglab_sw->setPixmap(*pimg);
#ifdef SSMSG
	//leftlayout->addWidget(txtb);
#endif
	leftlayout->addWidget(imglab_sw);
	//mainlayout->addWidget(imglab, 0, 0, 2, 1);
	/*��಼��end*/
	/*�Ҳ಼��*/
	e_date->setCalendarPopup(true);
	//e_date->calendarPopup()
	b_date->setCalendarPopup(true);

	el1->setText("ѡ����ֹ����");
	el2->setText("ѡ����ֹʱ��");
	bl1->setText("ѡ����ʼ����");
	bl2->setText("ѡ����ʼʱ��");
	e_layout->addWidget(el1);
	e_layout->addWidget(e_date);
	e_layout->addWidget(el2);
	e_layout->addWidget(e_time);
	b_layout->addWidget(bl1);
	b_layout->addWidget(b_date);
	b_layout->addWidget(bl2);
	b_layout->addWidget(b_time);
	e_group->setLayout(e_layout);
	e_group->setTitle("��ֹ����");
	b_group->setLayout(b_layout);
	b_group->setTitle("��ʼ����");

	//e_date->setFixedWidth(200);
	//el1->setFixedWidth(200);
	//el2->setFixedWidth(200);
	//b_date->setFixedWidth(200);
	//bl1->setFixedWidth(200);
	//bl2->setFixedWidth(200);
	e_date->setMinimumWidth(200);
	b_date->setMinimumWidth(200);
	el1->setMinimumWidth(200);
	el2->setMinimumWidth(200);
	bl1->setMinimumWidth(200);
	bl2->setMinimumWidth(200);
	mainlayout->addLayout(b_layout, 0, 0, 1, 1);
	mainlayout->addLayout(e_layout, 0, 1, 1, 1);
	rightlayout->addWidget(b_group);
	rightlayout->addWidget(e_group);
	/*�Ҳ಼��end*/
	/*�ײ�����*/
	sel_pic_btn->setText("ѡ����Ƭ");
	fi_l->setText("δѡ����Ƭ");
	confirm_btn->setText("ȷ������");
	cancel_btn->setText("ȡ��");
	//btm_group->setTitle("ѡ��ͼƬ");
	bottom_layout->addWidget(sel_pic_btn);
	bottom_layout->addWidget(fi_l);
	bottom_layout->addStretch();
	//bottom_layout->addWidget(confirm_btn);
	//bottom_layout->addWidget(cancel_btn);
	mainlayout->addLayout(rightlayout,0,0,1,1);
	mainlayout->addLayout(bottom_layout,1,0,1,1);
	mainlayout->addLayout(leftlayout, 2, 0, 1, 1);
	//btm_group->setLayout(bottom_layout);
	/*�ײ�����end*/
	/*���岼��*/
	//mainlayout->addLayout(leftlayout, 0, 0, 1, 1);
	//mainlayout->addLayout(rightlayout, 0, 1, 1, 1);
	mainlayout->addLayout(bottom_layout, 1, 0, 1, 2);
	this->setLayout(mainlayout);

	connect(cancel_btn, SIGNAL(clicked()), this, SLOT(cancel_btn_clicked()));
	connect(confirm_btn, SIGNAL(clicked()), this, SLOT(confirm_btn_clicked()));
	connect(sel_pic_btn, SIGNAL(clicked()), this, SLOT(sel_pic_clicked()));
	connect(b_date, SIGNAL(dateChanged(const QDate &)), this, SLOT(b_date_check(const QDate &)));
	//registerField("evaluate.name*", nameLineEdit);
	//registerField("evaluate.my_test_name*", nameLineEdit);

	//layout = new QGridLayout;
	//layout->addWidget(nameLabel, 0, 0);
	//layout->addWidget(nameLineEdit, 0, 1);
	//layout->addWidget(emailLabel, 1, 0);
	//	layout->addWidget(emailLineEdit, 1, 1);
	//layout->addWidget(txtb,0,0);


	//setLayout(layout);
	
	tree = f_p->get_tree_ptr();
	hostgroup = f_p->get_hostgroup_treeitem();
	QTreeWidgetItemIterator it(tree, QTreeWidgetItemIterator::Checked);
	txtb->clear();
	while (*it)
	{
		/*	if ((*it)->text(0) == itemText)
		(*it)->setSelected(true);*/
		txtb->append("selected " + (*it)->text(0));
		++it;
	}
	
}
void page_2::treeItemChanged(/*QTreeWidgetItem* item, int column*/)  
{
	//QTreeWidget *tmp = tree;
	//
	QTreeWidgetItemIterator it(tree, QTreeWidgetItemIterator::Checked);
	txtb->clear();
	ips.clear();
	while (*it)
	{
		//if ((*it)->text(1).isEmpty()==false)
		{
			txtb->append("selected host" + (*it)->text(0));
			if (base != NULL&&base->connection_flag == true)
			{
				QString citycode = (*it)->text(1);
				if (citycode.isEmpty())
				{ 
					++it; 
					continue;
				}
				QString cmd = "select * from iptable where code =" + citycode + ";";
				MYSQL_RES res = base->sql_cmd_rresult(cmd.toStdString());
				MYSQL_ROW sql_row;
				while (sql_row = mysql_fetch_row(&res))
				{
					txtb->append("ip " + QString::fromStdString(sql_row[1]));
					ips.push_back(sql_row[1]);
				}
			}
			++it;
		}
		}
		
	
}
void page_2::cancel_btn_clicked()
{
	this->close();
}
void page_2::confirm_btn_clicked()
{
	QDate edt;
	edt = e_date->date();
	QDate bdt = b_date->date();
	QTime et = e_time->time();
	QTime bt = b_time->time();
	QMessageBox msg1;
	auto ret = msg1.information(NULL, "ȷ������",
		/**/	"�û��ύ������Ϣ:\n��Ƭ��" + *imgname + "\n��" + bdt.toString() + "\n��" + edt.toString(),/**/
		/**/	QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);/**/
																	  //msg.setText("");
																	  //msg.exec();
	if (ret == QMessageBox::Yes)
	{
		/*�ύ������Ϣ*/
		/*QMessageBox msg;
		msg.setText("yes");
		msg.exec();*/
		MySql_DB m;
		int x = m.save_pic(PICLIBPATH + *pic_name);/*��ȡ����*/
		m.save_querry(x, PICLIBPATH + *pic_name, bdt, bt, edt, et);
		/*�ύ��ͨ��ģ��ͻ���*/
		struct QuerryStruct s;
		s.ipArr = ips;
		s.pic_id = x;//pid
					 //s.pic_path = CQPATH+ PICLIBPATH + *pic_name;//picpath�ύ����·��
		s.pic_path = PICLIBPATH + *pic_name;//picpath�ύ���·��
		s.e_t.setDate(edt);
		s.e_t.setTime(et);
		s.b_t.setDate(bdt);
		s.b_t.setTime(bt);//et&bt
		s.errorcode = "0";
		//
		//s.zipcode=
		emit SubmitQuerry(s);
		/*�ύ��ͨ��ģ��ͻ���end*/
	}
	else if (ret == QMessageBox::No)
	{

	}
}
void page_2::sel_pic_clicked()
{
	//imgname = NULL;
	*imgname = QFileDialog::getOpenFileName(this, tr("��ͼƬ"), ".", tr("ͼƬ�ļ� (*.jpg)"));
	//pimg->load(fileName);
#ifdef SSMSG
	QMessageBox m1;
	m1.setText(*imgname);
	m1.exec();
#endif

	if (*imgname == "")
	{
		//PW->button(QWizard::NextButton)->setEnabled(false);
		//fi_l->show();
		emit PicUnSelected();
		pimg->load("cover/cover.jpg");
		imglab_sw->setPixmap(*pimg);
		return;
	}
	else
	{
		emit PicSelected();
		//PW->button(QWizard::NextButton)->setEnabled(true);
		//QFile::copy("img/img1.jpg","img/imgt.jpg");
		QDateTime t = QDateTime::currentDateTime();
		//QString ts = t.toString("yyyy-MM-dd hh:mm:ss");
		*pic_name = t.toString("yyyyMMddhhmmss");
		*pic_name += ".jpg";
		QFile::copy(*imgname, PICLIBPATH + *pic_name);
		QFile file(PICLIBPATH + *pic_name);
		file.setPermissions(QFile::ReadOther);//readonly
											  /*msg.setText(ts);
											  msg.exec();*/
		//fi_l->setText(*imgname);
		fi_l->hide();
		pimg->load(*imgname);
		imglab_sw->setPixmap(*pimg);
		
		QDate edt;
		edt = e_date->date();
		QDate bdt = b_date->date();
		QTime et = e_time->time();
		QTime bt = b_time->time();
		//QMessageBox msg1;
		//auto ret = msg1.information(NULL, "ȷ������",
		//	/**/	"�û��ύ������Ϣ:\n��Ƭ��" + *imgname + "\n��" + bdt.toString() + "\n��" + edt.toString(),/**/
		//	/**/	QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);/**/
		//																  //msg.setText("");
		//																  //msg.exec();
		//if (ret == QMessageBox::Yes)
		{
			/*�ύ������Ϣ*/
			/*QMessageBox msg;
			msg.setText("yes");
			msg.exec();*/
			//MySql_DB m;
			//int x = m.save_pic(PICLIBPATH + *pic_name);/*��ȡ����*/
			//m.save_querry(x, PICLIBPATH + *pic_name, bdt, bt, edt, et);
			/*�ύ��ͨ��ģ��ͻ���*/
			//struct QuerryStruct s;
			qs.ipArr = ips;
			//qs.pic_id = x;//pid
						 //s.pic_path = CQPATH+ PICLIBPATH + *pic_name;//picpath�ύ����·��
			qs.pic_path = PICLIBPATH + *pic_name;//picpath�ύ���·��
			qs.e_t.setDate(edt);
			qs.e_t.setTime(et);
			qs.b_t.setDate(bdt);
			qs.b_t.setTime(bt);//et&bt
			qs.errorcode = "0";
			//
			//s.zipcode=
			emit SubmitQuerry(qs);
			/*�ύ��ͨ��ģ��ͻ���end*/
		}
		/*else if (ret == QMessageBox::No)
		{

		}*/

	}
}
void page_2::b_date_check(const QDate &date)
{
	/*msg.setText(date.toString());
	msg.exec();*/
	//if (b_date->date() > QDate::currentDate())//�û����ĸĴ��ڵ�ǰ����
	if ((date>QDate::currentDate()) && (date != bcdate))
	{
		QMessageBox msg1;
		auto ret = msg1.warning(NULL, "ע��",
			/**/	"��ѡ���ڳ�����ǰ���ڣ��Ƿ������",/**/
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
	else if ((date > QDate::currentDate()) && (date == bcdate))//����qtbug�ڶ��ν���
	{
		bcdate = QDate::currentDate();
		b_date->setDate(QDate::currentDate());
	}
	else if (date <= QDate::currentDate())
	{
		//bcdate = QDate::currentDate();���ù�
		return;
	}
}
void page_2::SBQTWiardButtonClicked()
{
	QMessageBox m1;
	m1.setText("sbqt");
	m1.exec();
}
//void page_2::confirm_btn_clicked()
//{
	//msg.setText("/*�ύ������*/");
//	msg.exec();
	//EMIT
//}
void page_2::update_status()
{
	//QMessageBox msg1;
	//msg1.setText("aa");
	//msg1.exec();
	//QTreeWidgetItemIterator it(/*tree*/hostgroup);
	/*qt�ṩ�������������ͼ�����֧������һ��*/
	//QTreeWidgetItem tmp=hostgrou
	//while (*it)
	static int flag= 0;

	for (int i = 0; i < hostgroup->childCount();i++)
	{
		if (hostgroup->child(i)->text(1).isEmpty())
		{
			continue;
		}
		else
		{
			QString code = hostgroup->child(i)->text(1);
			QString cmd = "select  flag,last_comit_time,last_result_time from iptable where code = '" +code+ "';";
			MYSQL_RES res = base->sql_cmd_rresult(cmd.toStdString());
			MYSQL_ROW sql_row;
			while (sql_row = mysql_fetch_row(&res))
			{
				//(*it)->setText(2, QString::fromStdString(sql_row[1]));
				if (QString::fromStdString(sql_row[0]).isEmpty())
				{
					continue;
				}
				if (atoi(sql_row[0]) == 0)
				{
				//	if (flag == 0)
					{
						hostgroup->child(i)->setText(3, "����");
						hostgroup->child(i)->setText(4, "");
					}
					/*else
					{
						hostgroup->child(i)->setText(3, "�������");
						hostgroup->child(i)->setText(4, "");
						if (!QString::fromStdString(sql_row[2]).isEmpty())
						{
							int sec = QDateTime::fromString(sql_row[1], "yyyy-MM-dd hh:mm:ss").secsTo(QDateTime::fromString(sql_row[2], "yyyy-MM-dd hh:mm:ss"));
							hostgroup->child(i)->setText(4, "��ʱ:" + QString::number(sec / 3600, 10) + "Сʱ" + QString::number((sec % 3600) / 60, 10) + "����" + QString::number(sec % 60, 10) + "��");
						}
					}*/

				}
				else if (atoi(sql_row[0]) == 1)
				{
					hostgroup->child(i)->setText(3, "������");
					flag = 1;
					//subItem21->setText(4, QString::fromStdString(sql_row[3]));
					int sec = QDateTime::fromString(sql_row[1], "yyyy-MM-dd hh:mm:ss").secsTo(QDateTime::currentDateTime());
					hostgroup->child(i)->setText(4, QString::number(sec / 3600, 10) + "Сʱ" + QString::number((sec % 3600) / 60, 10) + "����" + QString::number(sec % 60, 10) + "��");
				}
			}
		}
	}
}
page_2::~page_2()
{

}
page_3::page_3(QWizard * parent) :QWizardPage(parent)
{
	this->setTitle("������");
	label = new QLabel("������������Ƿ���ȷ���ύ��������");
	txtb = new QTextBrowser();
	confirm_button = new QPushButton();
	confirm_button->setText("ȷ�������ύ����");
	layout = new QVBoxLayout();
	layout->addWidget(label);
	layout->addWidget(txtb);
	//layout->addWidget(confirm_button);
	this->setLayout(layout);
	connect(confirm_button, SIGNAL(clicked()), this, SLOT(confirm_button_clicked()));

	setButtonText(QWizard::FinishButton, "�ύ����");
}
void page_3::RcvQuerry(struct QuerryStruct &QS)
{
	qs = QS;
	txtb->clear();
	txtb->append("��ѡ����Ƭ"+QS.pic_path);
	txtb->append("��ʼʱ��" + QS.b_t.toString());
	txtb->append("����ʱ��" + QS.e_t.toString());
	txtb->append("id" + QS.pic_path);
	txtb->append("��ѡ�������" );
	for (auto i : QS.ipArr)
	{
		txtb->append(QString::fromStdString(i));
	}
}
void page_3::confirm_button_clicked()
{
	/**/
	/*emit*/
#ifdef SSMSG
	msg.setText("confirm");
	msg.exec();
#endif
	emit SubmitQuerry(qs);
	//this->close();
	//this->hide();
	//parent->hide();
}
page_3::~page_3()
{

}


search_wizard::search_wizard(MySql_DB *DB,QWidget *parent)
	: QWizard(parent)
{
	base = DB;
	this->setWizardStyle(ModernStyle);

	p1 = new page_1(base, this);
	p2 = new page_2(base,this,this);
	p3 = new page_3(this);
	this->addPage(p1);
	this->addPage(p2);
	this->addPage(p3);
	this->setWindowTitle("������");
	this->resize(1000,618);
	connect(button(QWizard::NextButton), SIGNAL(clicked()), this, SLOT(SBQT()));
	connect(button(QWizard::FinishButton), SIGNAL(clicked()), this, SLOT(SBQTS()));
	//connect(p1, SIGNAL(tree_item_changed(QTreeWidgetItem*, int)), p2, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
	connect(p1, SIGNAL(TreeUpdateFinished()), p2, SLOT(treeItemChanged(/*QTreeWidgetItem*, int*/)));
	connect(p2, SIGNAL(SubmitQuerry(struct QuerryStruct &)), p3, SLOT(RcvQuerry(struct QuerryStruct &)));
	connect(p2, SIGNAL(PicSelected()), this, SLOT(SBQTpicselected()));
	connect(p2, SIGNAL(PicUnSelected()), this, SLOT(SBQTpicunselected()));
	connect(p3, SIGNAL(SubmitQuerry(struct QuerryStruct &)), this, SIGNAL(SubmitQuerry(struct QuerryStruct &)));
}
//void search_wizard::showfp()
//{
//	//p1->show();
//}
void search_wizard::SBQTpicunselected()
{
	this->button(QWizard::NextButton)->setEnabled(false);
}
void search_wizard::SBQTpicselected()
{
	this->button(QWizard::NextButton)->setEnabled(true);
}
void search_wizard::SBQTS()
{
	emit SubmitQuerry(p2->qs);
}
void search_wizard::SBQT()
{
#ifdef SSMSG
	QMessageBox m1;
	QString s = QString::number(this->currentId());
	m1.setText("SBQT" + s);
	m1.exec();
#endif
	if (this->currentId() == 1)
	{
		this->button(QWizard::NextButton)->setEnabled(false);
	}
	if (this->currentId ()== 2)
	{
		/*�ύ������Ϣ*/
#ifdef SSMSG
		QMessageBox msg;
		msg.setText("qs");
		msg.exec();
#endif
		//MySql_DB m;

		int x = base->save_pic(p2->qs.pic_path);/*��ȡ����*/
		p2->qs.pic_id = x;
		//base->save_querry(x, PICLIBPATH + *pic_name, bdt, bt, edt, et);
	}

}
search_wizard::~search_wizard()
{

}
bool search_wizard::DB_pass_pter(MySql_DB *DB)
{
	base = DB;
	//base->init_addr_graph();
	return true;
}
QTreeWidget * search_wizard::get_tree_ptr()
{
	return p1->pass_tree_ptr();
}
