#include "status_w.h"

status_w::status_w(MySql_DB *DB,QWidget *parent)
	:QWidget(parent)
{
	base = DB;
	//txtb = new QTextBrowser();
	//this->setTitle("first");
	this->resize(800, 600);
	QStringList header;
	header << "视频中心" << "编号" << "ip地址/映射端口号" << "状态" << "计时";
	layout = new QVBoxLayout();
	tree = new QTreeWidget();
	t1 = new QTimer();
	t1->start(200);
	//layout->addWidget(label);
	layout->addWidget(tree);
	tree->setHeaderLabels(header);
	tree->setColumnCount(5);
	tree->setColumnWidth(0, 250);
	tree->setColumnWidth(1, 150);
	tree->setColumnWidth(2, 100);
	tree->setColumnWidth(3, 100);
	tree->setColumnWidth(4, 200);
	this->setLayout(layout);
}
void status_w::update_status(std::vector <std::string> &iparr)
{
	tree->clear();
	int count = 0;
	//QString cmd = "select * from iptable where flag = '1' ;";
	for (auto &ip : iparr)
	{
		count++;
		QString cmd =  "select * from iptable where ip = '" + QString::fromStdString(ip) + "' ;";
		MYSQL_RES res = base->sql_cmd_rresult(cmd.toStdString());
		MYSQL_ROW sql_row;
			sql_row = mysql_fetch_row(&res);
			item = new QTreeWidgetItem(tree);
			item->setText(0, sql_row[5]);
			item->setText(1, sql_row[0]);
			item->setText(2, sql_row[1]);
			if (atoi(sql_row[2]) == 0)
			{
				int sec = QDateTime::fromString(sql_row[3], "yyyy-MM-dd hh:mm:ss").secsTo(QDateTime::fromString(sql_row[6], "yyyy-MM-dd hh:mm:ss"));
				if (sec <= 0)
				{
					item->setText(3, "目标离线");
					item->setText(4, "");
				}
				else
				{
					item->setText(3, "检索完成");
					item->setText(4, "耗时:" + QString::number(sec / 3600, 10) + "小时" + QString::number((sec % 3600) / 60, 10) + "分钟" + QString::number(sec % 60, 10) + "秒");
				}
			}
			else if (atoi(sql_row[2]) == 1)
			{
				item->setText(3, "正在检索");
				int sec = QDateTime::fromString(sql_row[3], "yyyy-MM-dd hh:mm:ss").secsTo(QDateTime::currentDateTime());
				item->setText(4, QString::number(sec / 3600, 10) + "小时" + QString::number((sec % 3600) / 60, 10) + "分钟" + QString::number(sec % 60, 10) + "秒");
			}
	}
}

status_w::~status_w()
{

}