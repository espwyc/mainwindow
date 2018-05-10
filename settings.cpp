#include "settings.h"

dbsetting_w::dbsetting_w(MySql_DB *DB, QWidget *parent)
	:QWidget(parent), base(DB)
{
	this->resize(400, 300);
	this->setWindowTitle("���ݿ�����");
	accountL = new QLabel("���ݿ��ʻ���");
	pwdL = new QLabel("���ݿ��˻�����");
	hostL = new QLabel("���ݿ��ַ");
	portL = new QLabel("�˿�");
	dbnameL= new QLabel("���ݿ���");
	accountE = new QLineEdit("root");
	pwdE = new QLineEdit("312006");
	hostE = new QLineEdit("localhost");
	portE = new QLineEdit("3306");
	dbnameE= new QLineEdit("control_center_base");
	ConfirmButton = new QPushButton("ȷ��");
	CancelButton= new QPushButton("ȡ��");
	mainlayout= new QGridLayout();
/*����*/
	mainlayout->addWidget(hostL, 0, 0, 1, 1);
	mainlayout->addWidget(hostE, 0, 1, 1, 1);
	mainlayout->addWidget(dbnameL, 1, 0, 1, 1);
	mainlayout->addWidget(dbnameE, 1, 1, 1, 1);
	mainlayout->addWidget(portL, 2, 0, 1, 1);
	mainlayout->addWidget(portE, 2, 1, 1, 1);
	mainlayout->addWidget(accountL, 3, 0, 1, 1);
	mainlayout->addWidget(accountE, 3, 1, 1, 1);
	mainlayout->addWidget(pwdL, 4, 0, 1, 1);
	mainlayout->addWidget(pwdE, 4, 1, 1, 1);
	mainlayout->addWidget(ConfirmButton, 5, 0, 1, 1);
	mainlayout->addWidget(CancelButton, 5, 1, 1, 1);
	this->setLayout(mainlayout);
/*����end*/
/*��*/
	connect(ConfirmButton, SIGNAL(clicked()), this,SLOT(ConfirmButtonClicked()) );
	connect(CancelButton, SIGNAL(clicked()), this, SLOT(CancelButtonClicked()));
/*��end*/
}
dbsetting_w::~dbsetting_w()
{}
void dbsetting_w::ConfirmButtonClicked()
{
	QMessageBox msg1;
	if (base->setdb(accountE->text(), pwdE->text(), hostE->text(), dbnameE->text(), portE->text()))
	{	
		msg1.setText("���ӳɹ�");
		msg1.exec();
		this->close();
	}
	else
	{
		msg1.setText("����ʧ��");
		msg1.exec();
	}
}
void dbsetting_w::CancelButtonClicked()
{
	this->close();
}


netsetting_w::netsetting_w(MySql_DB *DB, QWidget *parent)
	:QWidget(parent), base(DB)
{
	QStringList header;
	header << "��Ƶ���ı��" <<"���ص�ַ" << "ip"<<""<<""<<"";
	t1 = new QTimer();
	t1->start(200);
	table = new QTableWidget();
	mainlayout = new QGridLayout();
	smapper = new QSignalMapper(this);
	dmapper = new QSignalMapper(this);
	connect(smapper, SIGNAL(mapped(const QString &)), this, SLOT(DeleteButtonClicked(const QString&)));
	connect(dmapper, SIGNAL(mapped(const QString &)), this, SLOT(EditButtonClicked(const QString&)));
	table->setColumnCount(6);
	table->setHorizontalHeaderLabels(header);
	mainlayout->addWidget(table);
	this->setLayout(mainlayout);
	this->resize(600, 360);
	Init_Table(table);
}
netsetting_w::~netsetting_w()
{
}
void netsetting_w::Init_Table(QTableWidget *table)
{
	table->clearContents();
	table->setRowCount(0);
	if (base != NULL&&base->connection_flag == true)
	{
		QString cmd = "select * from iptable order by code asc;";
		MYSQL_RES nres = base->sql_cmd_rresult(cmd.toStdString());
		MYSQL_ROW sql_row;
		//int i = 0;
		while (sql_row = mysql_fetch_row(&nres))
		{
			table->insertRow(table->rowCount());
			table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem(sql_row[0]));
			table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem(sql_row[5]));
			table->setItem(table->rowCount() - 1, 2, new QTableWidgetItem(sql_row[1]));
			tmpb = new QPushButton();
			QVBoxLayout *v_c = new QVBoxLayout();
			QWidget *cell = new QWidget();
			tmpb->setFixedSize(100, 30);
			tmpb->setText("ɾ��");		
			//connect(tmpb, SIGNAL(clicked()), this, SLOT(ConfirmButtonClicked()));
			connect(tmpb, SIGNAL(clicked()), smapper, SLOT(map()));
			smapper->setMapping(tmpb, QString::fromStdString(sql_row[0]));
			v_c->addStretch();
			v_c->addWidget(tmpb);
			v_c->addStretch();		
			cell->setLayout(v_c);
			v_c->setMargin(0);
			table->setCellWidget(table->rowCount() - 1, 3, cell);
			tmpb = new QPushButton();
			v_c = new QVBoxLayout();
			cell = new QWidget();
			tmpb->setFixedSize(100, 30);
			tmpb->setText("�޸�ip");
			//connect(tmpb, SIGNAL(clicked()), this, SLOT(DeleteButtonClicked(sql_row[0])));
			connect(tmpb, SIGNAL(clicked()), dmapper, SLOT(map()));
			dmapper->setMapping(tmpb, QString::fromStdString(sql_row[0]));
			v_c->addStretch();
			v_c->addWidget(tmpb);
			v_c->addStretch();
			cell->setLayout(v_c);
			v_c->setMargin(0);
			table->setCellWidget(table->rowCount() - 1, 4, cell);
			//delegate button
			/*tmp = new QPushButton();
			tmp->setFixedSize(100, 30);*/
			//
			/*if (atoi(sql_row1[0]) == 0)
			{
				pb1->setText("���޽��");
				pb1->setEnabled(false);
				pb1->setStyleSheet("QPushButton{background: transparent;}");
			}
			else if (atoi(sql_row1[0]) > 0)
			{
				pb1->setText("�鿴���");
				pb1->setEnabled(true);
			}*/
			//pb1->setText(QString::number(i++,10));
			///*��ť�ޱ߾���д���*/
			//QVBoxLayout *v_c = new QVBoxLayout();
			//v_c->addStretch();
			//v_c->addWidget(pb1);
			//v_c->addStretch();
			//QWidget *cell = new QWidget();
			//cell->setLayout(v_c);
			//v_c->setMargin(0);
			///*��ť�ޱ߾���д���end*/
			/*table->setCellWidget(table->rowCount() - 1, 6, cell);*/
		/*	connect(pb1, SIGNAL(clicked()), signalMapper, SLOT(map()));
			signalMapper->setMapping(pb1, QString::fromStdString(sql_row[2]));
			pimg = new QPixmap();
			imglab = new QLabel();
			imglab->setFixedSize(100, 120);
			imglab->setScaledContents(true);
			pimg->load(QString::fromStdString(sql_row[3]));
			imglab->setPixmap(*pimg);
			table->setRowHeight(table->rowCount() - 1, 120);
			table->setCellWidget(table->rowCount() - 1, 1, imglab);*/
		}
	}
}
void	netsetting_w::DeleteButtonClicked(const QString &id)
{
#ifdef SSMSG
	QMessageBox msgl;
	msgl.setText("c"+id);
	msgl.exec();
#endif
	QMessageBox msg1;
	auto ret = msg1.warning(NULL, "ע��",
		/**/	"ȷ��ɾ��?",/**/
		/**/	QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);/**/
	if (ret == QMessageBox::Yes)
	{
		QString cmd = "delete from iptable where code = " + id + ";";
		base->mysql_cmd(cmd.toStdString());
		Init_Table(table);
		return;
}
	else if (ret == QMessageBox::No)
	{
		return;
	}
}
void	netsetting_w::EditButtonClicked(const QString &id)
{
#ifdef SSMSG
	QMessageBox msg1;
	msg1.setText("v"+id);
	msg1.exec();
#endif
	QDialog wg;
	QDialogButtonBox buttonBox(QDialogButtonBox::Ok	| QDialogButtonBox::Cancel);
	QGridLayout mainl;
	QLabel la("����ip");
	QLineEdit le;
	//QPushButton cob("ȷ��"), cab("ȡ��");
	mainl.addWidget(&la, 0, 0,1,1);
	mainl.addWidget(&le, 0, 1, 1, 1);
	mainl.addWidget(&buttonBox, 1, 1, 1, 1);
	connect(&buttonBox, SIGNAL(accepted()), &wg, SLOT(accept()));
	connect(&buttonBox, SIGNAL(rejected()), &wg, SLOT(reject()));
	//mainl.addWidget(&cob, 1, 0, 1, 1);
	//mainl.addWidget(&cab, 1, 1, 1, 1);
	wg.setLayout(&mainl);
	if (wg.exec() == QDialog::Accepted)
	{
#ifdef SSMSG
		QMessageBox msg1;
		msg1.setText("acc");
		msg1.exec();
#endif
		QString cmd = "update iptable  set ip = '"+le.text()+"' where code = " + id + ";";
		if (base->mysql_cmd(cmd.toStdString()))
		{
			QMessageBox msg1;
			msg1.setText("�޸ĳɹ�");
			msg1.exec();
			Init_Table(table);
			wg.close();
		}
	}
	//if (wg.exec() == QDialog::Rejected)
	else
	{
#ifdef SSMSG
		QMessageBox msg1;
		msg1.setText("rej");
		msg1.exec();
#endif
	}
}