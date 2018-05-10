#include "InteractObject.h"
//#include "Jswidget.h"
#include "mainwindow.h"


//��������
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
	emit sendStringSignal(text);//emit �Ƿ����źŸ��ۣ�����ͷ�ļ�����
}


//This slot is invoked from the HTML client side and the text displayed on the server side.
void InteractObject::recvStringSlot(const QString &text)
{
	mwd->RcvFromWeb(text);
	/*QMessageBox msg;
	msg.setText("recive");
	msg.exec();*/
}