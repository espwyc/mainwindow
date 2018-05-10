#include "con2thread.h"
#pragma execution_character_set("utf-8")


bool con2thread::sendmsgback(const QString &text)
{
	emit con2thread::mysig(text);
	return true;
}
bool con2thread::recvpic_fin(struct QuerryResultStruct RS)
{
	//emit con2thread::mysig(text);
	//struct QuerryResultStruct nrs = rs;
	//-msg.setText("befe:"+rs.pic_path);
	//-msg.exec();
	tmp.addr = RS.addr;
	tmp.pic_id = RS.pic_id;
	tmp.pic_path = RS.pic_path;
	tmp.b_t = RS.b_t;
	tmp.e_t = RS.e_t;
	tmp.zipcode = RS.zipcode;
	tmp.picsimilarity = RS.picsimilarity;
	/*struct QuerryResultStruct t;
	t.addr = RS.addr;
	t.pic_id = RS.pic_id;
	t.pic_path = RS.pic_path;
	t.b_t = RS.b_t;
	t.e_t = RS.e_t;*/
	//emit con2thread::rcvpic_sig(t);
	QString s = RS.addr + "|" + RS.pic_path + "|" + QString::number(RS.pic_id) + "|" + RS.b_t.toString("yyyy-MM-dd hh:mm:ss") + "|" + RS.e_t.toString("yyyy-MM-dd hh:mm:ss") + "|" + RS.errorCode+ "|"+RS.zipcode+ "|" + RS.picsimilarity;
	emit rcvpic_sig(s/*, RS.pic_path, RS.pic_id, RS.b_t, RS.e_t*/);
	//emit rcv_sig(t.pic_path);
	return true;
}
con2thread::con2thread()
{
	rcv_fin_flag = false;
}
con2thread::~con2thread()
{}