#include "result_window.h"

result_window::result_window(QWidget *parent)
	: QWidget(parent)
{
	table = new QTableWidget();
	tab_view = new QTableView();
	mainlayout = new QGridLayout();
	signalMapper = new QSignalMapper(this);
	fresh_btn = new QPushButton();
	fresh_btn->setFixedWidth(100);
	fresh_btn->setText("刷新数据");
	connect(signalMapper, SIGNAL(mapped(const QString&)), this, SLOT(ClickedButton(const QString&)));
	QStringList table_header;
	table->setColumnCount(7);
	//table->setColumnWidth(1, 80);
	table->setColumnWidth(1, 100);
	table->setColumnWidth(4, 70);
	table->setColumnWidth(5, 70);
	table->setColumnWidth(6, 100);
	//table->setRowCount(6);
	table_header << "指令发出时间" << "检索照片" << "起始时间" << "终止时间" << "图片id" << "结果数量" << "";
	table->setHorizontalHeaderLabels(table_header);
	mainlayout->addWidget(fresh_btn, 0, 0, 1, 1);
	mainlayout->addWidget(table, 1, 0, 10, 1);
	this->setLayout(mainlayout);
	this->resize(1000, 636);
	this->setWindowTitle("结果浏览");
	connect(fresh_btn, SIGNAL(clicked()), this, SLOT(fresh_btn_clicked()));
}

result_window::~result_window()
{

}
void result_window::load_querry(const QString &ts)
{
	if (base != NULL&&base->connection_flag == true)
	{
		QString cmd = "select * from querrytable " + ts + " order by qid desc;";
		MYSQL_RES nres = base->sql_cmd_rresult(cmd.toStdString());
		MYSQL_ROW sql_row;
		//int i = 0;
		while (sql_row = mysql_fetch_row(&nres))
		{
			table->insertRow(table->rowCount());
			table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem(sql_row[6]));
			table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem(sql_row[3]));
			table->setItem(table->rowCount() - 1, 2, new QTableWidgetItem(sql_row[4]));
			table->setItem(table->rowCount() - 1, 3, new QTableWidgetItem(sql_row[5]));
			table->setItem(table->rowCount() - 1, 4, new QTableWidgetItem(sql_row[2]));
			int pic_id = atoi(sql_row[2]);
			std::string s = "select count(*) from querryresult where pic_id = " + QString::number(pic_id, 10).toStdString() + ";";
			MYSQL_RES nres1 = base->sql_cmd_rresult(s);
			MYSQL_ROW sql_row1;
			sql_row1 = mysql_fetch_row(&nres1);
			table->setItem(table->rowCount() - 1, 5, new QTableWidgetItem(sql_row1[0]));
			//delegate button
			pb1 = new QPushButton();
			pb1->setFixedSize(100, 30);
			//
			if (atoi(sql_row1[0]) == 0)
			{
				pb1->setText("暂无结果");
				pb1->setEnabled(false);
				pb1->setStyleSheet("QPushButton{background: transparent;}");
			}
			else if (atoi(sql_row1[0]) > 0)
			{
				pb1->setText("查看结果");
				pb1->setEnabled(true);
			}
			//pb1->setText(QString::number(i++,10));
			/*按钮无边距居中处理*/
			QVBoxLayout *v_c = new QVBoxLayout();
			v_c->addStretch();
			v_c->addWidget(pb1);
			v_c->addStretch();
			QWidget *cell = new QWidget();
			cell->setLayout(v_c);
			v_c->setMargin(0);
			/*按钮无边距居中处理end*/
			table->setCellWidget(table->rowCount() - 1, 6, cell);
			connect(pb1, SIGNAL(clicked()), signalMapper, SLOT(map()));
			signalMapper->setMapping(pb1, QString::fromStdString(sql_row[2]));
			pimg = new QPixmap();
			imglab = new QLabel();
			imglab->setFixedSize(100, 120);
			imglab->setScaledContents(true);
			pimg->load(QString::fromStdString(sql_row[3]));
			imglab->setPixmap(*pimg);
			table->setRowHeight(table->rowCount() - 1, 120);
			table->setCellWidget(table->rowCount() - 1, 1, imglab);
		}
	}

}
void result_window::reload_querry(const QString &ts)
{
	table->setRowCount(0);
	table->clearContents();
	table->clear();
	QStringList table_header;
	table->setColumnCount(7);
	//table->setColumnWidth(1, 80);
	table->setColumnWidth(1, 100);
	table->setColumnWidth(4, 70);
	table->setColumnWidth(5, 70);
	table->setColumnWidth(6, 100);
	//table->setRowCount(6);
	table_header << "指令发出时间" << "检索照片" << "起始时间" << "终止时间" << "图片id" << "结果数量" << "";
	table->setHorizontalHeaderLabels(table_header);

	load_querry(ts);
}
bool result_window::DB_pass_pter(MySql_DB *DB)
{
	base = DB;
	load_querry("");
	return true;
}
void result_window::button_clicked(int i)
{
#ifdef SSMSG
	msg.setText(QString::number(i, 10));
	msg.exec();
#endif
}
void result_window::ClickedButton(const QString &text)
{
#ifdef SSMSG
	msg.setText(text);
	msg.exec();
#endif
	emit show_result_byid(text);
}
void result_window::fresh_btn_clicked()
{
#ifdef SSMSG
	msg.setText("relaod");
	msg.exec();
#endif
	reload_querry("");
}