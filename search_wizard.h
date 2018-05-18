#pragma once
#ifndef SEARCH_WIZARD_H
#define SEARCH_WIZARD_H
#pragma execution_character_set("utf-8")

#include <QWizard>
#include <QWidget>
#include <QWizardPage>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QTimeEdit>
#include <QDateEdit>
#include <QGroupBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QLineEdit>
#include <QMessageBox>
#include <QTextBrowser>
#include <QFileDialog>
#include <QFile>
#include <QDateTime>
#include <QDate>
#include <QTimer>
//#include <mysql.h>
#include "mysql_con.h"
//#include "includes.h"


class search_wizard;

class page_1 : public QWizardPage
{
	Q_OBJECT
public:
	page_1(MySql_DB *base, QWizard * parent = 0);
	~page_1();
	void updateParentItem(QTreeWidgetItem* item);
	void updateChildItem(QTreeWidgetItem* item, int CheckState);
	QTreeWidget * pass_tree_ptr();
	QMessageBox msg;
	QTreeWidgetItem *group2;
private:

	QTextBrowser *txtb;
	QLabel *label;
	QVBoxLayout *layout;
	QTreeWidget *tree;
signals:
	void tree_item_changed(QTreeWidgetItem* item, int column);
	void TreeUpdateFinished();
private slots :
	void treeItemChanged(QTreeWidgetItem* item, int column);
public slots :
};
class page_2 : public QWizardPage
{
	Q_OBJECT
public:
	page_2(MySql_DB *DB,search_wizard *f_p, QWizard * parent=0);
	~page_2();
	QMessageBox msg;
	struct QuerryStruct qs;
private:
	std::vector<std::string> ips;
	QWizard *PW;
	//search_wizard *f_w;
	//search_wizard *f_p;
	/*QAbstractButton *bt;
	QLabel *label ;
	QVBoxLayout *layout;
	QLineEdit *line;*/
	QTimer *timer1;
	MySql_DB *base = NULL;
	QTextBrowser * txtb;
	QGridLayout *layout;
	//QLabel *nameLabel;
	//QLabel *emailLabel;
	//QLineEdit *nameLineEdit;
	QTreeWidget *tree;
	//QLineEdit *emailLineEdit;
	QPushButton *sel_pic_btn;
	QPushButton *confirm_btn;
	QDateEdit *b_date;
	QDateEdit *e_date;
	QTimeEdit *b_time;
	QTimeEdit *e_time;
	QLabel *imglab_sw;
	QPixmap *pimg;
	QGroupBox *b_group;
	QGroupBox *e_group;
	//QGroupBox *btm_group;
	QHBoxLayout *rightlayout;
	QVBoxLayout *leftlayout;
	QVBoxLayout *b_layout;
	QVBoxLayout *e_layout;
	QHBoxLayout *bottom_layout;
	QGridLayout *mainlayout;
	QLabel *bl1;
	QLabel *bl2;
	QLabel *el1;
	QLabel *el2;
	QLabel *fi_l;
	QPushButton *cancel_btn;
	QString *imgname;
	QString *pic_name;
	QTreeWidgetItem *hostgroup;
	//bool b_date_flag = false;
	//QDate bcdate=QDate::fromString("1970-01-01","yyyy-MM-dd");
	QDate bcdate = QDate::currentDate();//qtbug²¹¾È
signals:
	void SubmitQuerry(struct QuerryStruct &QS);
	void PicSelected();
	void PicUnSelected();
private slots :
	void cancel_btn_clicked();
	void confirm_btn_clicked();
	void sel_pic_clicked();
	void b_date_check(const QDate &date);
	void update_status();
	void SBQTWiardButtonClicked();
public slots :
		void treeItemChanged(/*QTreeWidgetItem* item, int column*/);
};
class page_3 : public QWizardPage
{
	Q_OBJECT
public:
	page_3(QWizard * parent = 0);
	~page_3();
	QMessageBox msg;
private:
	struct QuerryStruct qs;
	QLabel *label;
	QTextBrowser *txtb;
	QPushButton *confirm_button;
	QVBoxLayout *layout;
signals:
	void SubmitQuerry(struct QuerryStruct &QS);
private slots :
		void confirm_button_clicked();
public slots :
	void RcvQuerry(struct QuerryStruct &QS);
};

class search_wizard : public QWizard
{
	Q_OBJECT
public:
	search_wizard(MySql_DB *DB, QWidget *parent = 0);
	~search_wizard();
	void HideWizard() { this->hide(); };
	void CloseWizard() { this->close(); };
	bool DB_pass_pter(MySql_DB *DB);
	QTreeWidget * get_tree_ptr();
	QTreeWidgetItem *get_hostgroup_treeitem() { return p1->group2; };
	QMessageBox msg;
	void showfp() { p1->show(); };
protected:
	MySql_DB *base;
private:
	page_1 *p1;
	page_2 *p2;
	page_3 *p3;
private slots:
	void  SBQT();
	void  SBQTS();
	void SBQTpicselected();
	void SBQTpicunselected();
signals:
		   void SubmitQuerry(struct QuerryStruct &QS);
};


#endif