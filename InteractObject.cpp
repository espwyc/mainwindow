#include "InteractObject.h"
//#include "Jswidget.h"
#include "mainwindow.h"


//交互对象
InteractObject::InteractObject(MainWindow *parent)
	: QObject(parent)
	, mwd(parent)
{

}
//
void InteractObject::sendStringToHtml(const QString &text)
{
	/*QMessageBox msg;
	msg.setText("emit");
	msg.exec();*/
	emit sendStringSignal(text);//emit 是发送信号给槽，槽在头文件声明
}


//This slot is invoked from the HTML client side and the text displayed on the server side.
void InteractObject::recvStringSlot(const QString &text)
{
	mwd->RcvFromWeb(text);
	/*QMessageBox msg;
	msg.setText("recive");
	msg.exec();*/
}