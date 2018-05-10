/*
//webenginevie需要添加 WebEngineView 文件路径
//$(QTDIR)\include\QtWebEngineWidgets
//$(QTDIR)\include\QtWebChannel
//第二步: 添加lib 库文件
//Qt5WebEngined.lib
//Qt5WebEngineWidgetsd.lib到连接器linker的input
//Qt5WebChanneld.lib
*/

#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QLabel>
#include <QObject>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QTextBrowser>
#include <QImage>
#include <QPixmap>
#include <QCheckBox>
#include <QMouseEvent>
#include <QFileDialog>
#include <QMenu>
#include  <QMenuBar>
#include <QAction>
#include <QStatusBar>
#include <QTimer>
#include <QIcon>
#include <QSize>
#include <QDialog>
#include <QDesktopServices>
#include "InteractObject.h"
#include "correction.h"
#include "picshow.h"
#include "mysql_con.h"
#include "network_pannel.h"
#include "search_w.h"
#include "struct_class_file.h"
#include "result_window.h"
#include "search_wizard.h"
#include "status_w.h"
#include "user_w.h"
#include "user_cw.h"
#include "timepicker.h"
#include "settings.h"
//#include "includes.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void RcvFromWeb(const QString &text);
	QMessageBox msg;
	int *nw_flag;
	int js_flag = 0;
private:
	
	/*全局*/
	std::vector<QString> picpath;
	std::vector<QString> loca;
	std::vector<QString> aptime;
	std::vector<QString> zipcodes;
	std::vector<QString> similarity;
	FaceInfo CurrentFace;
	std::vector<std::string> ipaddr;
	/*全局end*/
	/*菜单栏相关*/
	QMenu *m1;
	QMenu *m2;
	QMenu *m3;
	QMenu *m4;
	QMenu *m5;
	QMenu *m6;
	QMenu *m7;
	QMenu *m8;
	QMenu *me;
	QMenuBar *mbar;
	QAction *m1_1;
	QAction *m2_1;
	QAction *m2_2;
	QAction *m2_3;
	QAction *m3_1;
	QAction *m3_2, *m4_1, *m4_2, *m5_1;
	QMenu *m5_2;
	QAction * m5_2_1, *m5_2_2;
	QAction *m6_1, *m6_2, *m6_3;
	QAction *me_1;
	/*菜单栏相关end*/
	/*用户栏相关*/
	QHBoxLayout *user_bar;
	QVBoxLayout *user_bar_layout;
	QPushButton *ul1;
	QPushButton *ul2;
	QPushButton *ul3;
	QPushButton *ul4;
	QPushButton *ul5;
	QPushButton *ul6;
	QPushButton *ul7;
	QIcon *up1;
	QIcon *up2;
	QIcon *up3;
	QIcon *up4;
	QIcon *up5;
	QIcon *up6;
	QIcon *up7;
	/*用户栏相关end*/
	/*状态栏相关*/
	QLabel *sbar_l1;
	QLabel *sbar_l2;
	QLabel *sbar_l3;
	QLabel *sbar_l4;
	QLabel *sbar_l5;
	QLabel *sbar_le;
	QStatusBar *sbar;
	QTimer *t1;

	/*状态栏相关end*/
	/*窗体*/
	user_w *userw;
	user_cw *usercw;
	search_wizard *scww;
	result_window *rsw;
	NetWork *ntw;
	search_w *sw;
	picshow *picw;
	correction *cw;
	status_w *stw;
	timepicker *tpw;
	dbsetting_w *dbsw;
	netsetting_w *ntsw;
	/*窗体end*/
	InteractObject *Int_Obj;
	MySql_DB *mydb;
	//-mysql_pannel *sqpannel;
	QWidget *centalwidget;//mainlayout_widget
	QGridLayout *mainlayout;
	QGridLayout *right_weblayout;
	QVBoxLayout *rightlayout;
	QHBoxLayout *bottomlayput;
	QVBoxLayout *leftlayout;
	QWebEngineView *webview;
	QLabel *label1;
	QPushButton *bottomlayout_button1;
	QPushButton *leftlayout_button1;
	QPushButton *bottomlayout_testbutton;
	QLineEdit *lineedit1;
	//QWebFrame *webFrame;
	QWebChannel *webchannel;
	QHBoxLayout *bottom_test;
	QPushButton *bte1;
	QPushButton *hide_btn;
	QLineEdit *bteline;
	QLabel *btelb;
	QTextBrowser *textbrowswer;
	QLabel *imglab_mw;
	//Mylabel *imglab;
	//ClickedLabel *imglab;
	//QImage *img;
	QPushButton *imgbutton;
	QPixmap *pimg;
	QCheckBox *chkbox1;
	QCheckBox *chkbox2;
	//QPushButton *correct_btn;
	QPushButton *wrong_btn;
	QPushButton *jiansuo_btn;
	QPushButton *test_mysql_btn;
	QPushButton *test_showpath_btn;

	private slots:
	void bb1_clicked();
	void lb1_clicked();
	void Web_Jump(const QUrl &url);
	void bbt_clicked();
	void bte_clicked();
	//void correct_btn_clicked();
	void wrong_btn_clicked();
	//void test_wd();
	void test_wd(const QString &text);
	//void web_url_changed();	
	void pic_show();
	void test_mysql_btn_clicked();
	void test_showpath_btn_clicked();
	void hide_btn_clicked(int sig = 0);
	void sta_tl_update();
	void m1_1_triggered();
	void m2_1_triggered();
	void m2_2_triggered();
	void m2_3_triggered();
	void m3_1_triggered();
	void m3_2_triggered();
	void m4_1_triggered();
	void m4_2_triggered();
	void m5_1_triggered();
	void m5_2_triggered();
	void m6_1_triggered();
	void ShowSearchResult(const QString &picid);
	void ShowResultByPicId(const QString &picid);
	void ul1_clicked();
	void ul2_clicked();
	void ul3_clicked();
	void ul4_clicked();
	void ul5_clicked();
	void ul6_clicked();
	void ul7_clicked();
	void result_withspan(const QString &ts);
	void addvideocenterw();
	void AboutDialog();
	void SubmitQuerry(struct QuerryStruct &QS);
	void Show_Status();
signals:
	void testemit();
protected:
	bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINWINDOW_H
