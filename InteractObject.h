#pragma once
#ifndef __INTERACT_OBJECT_H__
#define __INTERACT_OBJECT_H__
//交互对象头文件

#pragma execution_character_set("utf-8")
#include <QWebChannel>
#include <QObject>
#include <QString>
//#include "includes.h"



//---------------------------交互类---------------------------------
class MainWindow;

class InteractObject : public QObject
{
	Q_OBJECT

public:
	InteractObject(MainWindow *parent);

	void sendStringToHtml(const QString &text);

	// 槽
public slots:
	// 可以被javascript调用
	void recvStringSlot(const QString &text);

	// 信号
signals:
	// 在javascript文件里面定义链接函数，
	// 然后发送信号触发javascript函数
	void sendStringSignal(const QString &text);

private:
	QString _text;
	QString _recieveText;
	//JsWidget *_jsWidget;
	MainWindow *mwd;
};
//---------------------------交互类------------end---------------------


#endif
