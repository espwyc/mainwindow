#pragma once
#ifndef __INTERACT_OBJECT_H__
#define __INTERACT_OBJECT_H__
//��������ͷ�ļ�

#pragma execution_character_set("utf-8")
#include <QWebChannel>
#include <QObject>
#include <QString>
//#include "includes.h"



//---------------------------������---------------------------------
class MainWindow;

class InteractObject : public QObject
{
	Q_OBJECT

public:
	InteractObject(MainWindow *parent);

	void sendStringToHtml(const QString &text);

	// ��
public slots:
	// ���Ա�javascript����
	void recvStringSlot(const QString &text);

	// �ź�
signals:
	// ��javascript�ļ����涨�����Ӻ�����
	// Ȼ�����źŴ���javascript����
	void sendStringSignal(const QString &text);

private:
	QString _text;
	QString _recieveText;
	//JsWidget *_jsWidget;
	MainWindow *mwd;
};
//---------------------------������------------end---------------------


#endif
