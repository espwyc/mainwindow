#pragma once
#ifndef PICSHOW_H
#define PICSHOW_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QImage>
#include <QPixmap>
//#include "includes.h"


class picshow : public QDialog
{
	Q_OBJECT

public:
	picshow(QWidget *parent = 0);
	~picshow();
	void picw_load(const QString &text);
private:
	QGridLayout *mainlayout;
	QLabel *imglab;
	QPixmap *pimg;
};

#endif // DIALOG_H