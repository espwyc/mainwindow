#pragma once
#ifndef STRUCT_CLASS_FILE_H
#define STRUCT_CLASS_FILE_H
//����꣬�ļ���أ������



//#define SSMSG

#include <QDateTime>
#include <QString>
#include <QDir>
//#include "includes.h"

#define CQPATH (QDir::currentPath()+"/")
#define CSPATH (QDir::currentPath().toStdString()+"/")
#define PICLIBPATH "picture_lib/"/*ͼƬ���ļ���*/
#define RCVPICLIBPATH "rcv_floder/"/*ͼƬ�����ļ���*/
#define RESULTPICLIBPATH "rcvpicture_lib/"/*���ͼƬ��*/
#define MAX_PNTCOUNT 30

struct address_node
{
	int id;
	int code;
	int parentcode;
	int level;
	QString name;
	struct address_node *next;
	struct address_node *child;
};

struct QuerryStruct
{
	std::vector<std::string> ipArr;
	QDateTime b_t;
	QDateTime e_t;
	QString pic_path;
	QString errorcode;
	QString zipcode;
	int pic_id;
};
struct QuerryResultStruct
{
	QDateTime b_t;
	QDateTime e_t;
	QString pic_path;
	QString addr;
	QString errorCode;
	QString zipcode;
	QString picsimilarity;
	int pic_id;
};

class FaceInfo
{
public:
	QString path;
	QString pic_id;
	QString location;
	QString zipcode;
};
class User
{
public:
	QString UserName;
	int status;
};

#endif
