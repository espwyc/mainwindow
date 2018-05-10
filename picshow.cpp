#include "picshow.h"

picshow::picshow(QWidget *parent)
	: QDialog(parent)
{
	imglab = new QLabel();
	pimg = new QPixmap();
	mainlayout = new QGridLayout();
	pimg->load("img/img1.jpg");
	imglab->setPixmap(*pimg);
	mainlayout->addWidget(imglab);
	this->setLayout(mainlayout);
}

picshow::~picshow()
{

}
void picshow::picw_load(const QString &text)
{
	pimg->load(text);
	imglab->setPixmap(*pimg);
}
