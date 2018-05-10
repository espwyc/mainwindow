#include "mysql_con.h"


using namespace std;



MySql_DB::MySql_DB()
{
	if (ConnectDB())
	{
		connection_flag = true;
	}
	else
	{
		connection_flag = false;
	}
	mysql_query(&my_con, "SET NAMES UTF8");
}
MySql_DB::~MySql_DB()
{
	CloseDB();
}
bool MySql_DB::ConnectDB()
{
	mysql_init(&my_con);
	if (mysql_real_connect(&my_con, host, user, pswd, dbname, port, NULL, 0))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
bool MySql_DB::CloseDB()
{
	if (connection_flag == true)
	{
		mysql_close(&my_con);
		connection_flag = false;
		return true;
	}
	else return false;
}
bool MySql_DB::setdb(const QString username, const QString pwd, const QString hostname, const QString basename, const QString portnum)
{
	//user = username.toStdString().c_str();
	//const char *tmp = username.toStdString().c_str();
	if (connection_flag == true)
	{
		CloseDB();
	}
	if (connection_flag == false)
	{
		strcpy_s(user, sizeof(user), username.toStdString().c_str());
		strcpy_s(pswd, sizeof(pswd), pwd.toStdString().c_str());
		strcpy_s(host, sizeof(host), hostname.toStdString().c_str());
		strcpy_s(dbname, sizeof(dbname), basename.toStdString().c_str());
		port = portnum.toInt();
		if (ConnectDB())
		{
			connection_flag = true;
			mysql_query(&my_con, "SET NAMES UTF8");
			return true;
		}
		else
		{
			connection_flag = false;
			return false;
		}
	}
	return false;
}
QString MySql_DB::mysql_test()
{

	int res;
	mysql_init(&my_con);
	if (mysql_real_connect(&my_con, host, user, pswd, dbname, port, NULL, 0))
	{
		mysql_query(&my_con, "SET NAMES GBK"); //���ñ����ʽ
		res = mysql_query(&my_con, "select * from city");//��ѯ
		if (!res)
		{
			result = mysql_store_result(&my_con);
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					cout << "name:" << sql_row[1] << endl;
					cout << "  location:" << sql_row[2] << endl;
					emit send_row((QString)"name:" + (QString)sql_row[1] + (QString)" location:" + (QString)sql_row[2]);
				}
				/*sql_row = mysql_fetch_row(result);
				return sql_row[1];*/
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
		mysql_free_result(result);
	mysql_close(&my_con);
	return NULL;
}
QString MySql_DB::mysql_test2()
{

	int res;
	mysql_init(&my_con);
	if (mysql_real_connect(&my_con, host, user, pswd, dbname, port, NULL, 0))
	{
		mysql_query(&my_con, "SET NAMES GBK"); //���ñ����ʽ
		res = mysql_query(&my_con, "select * from erroritem");//��ѯ
		if (!res)
		{
			result = mysql_store_result(&my_con);
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					//cout << "name:" << sql_row[1] << endl;
					//cout << "  location:" << sql_row[2] << endl;
					emit send_row((QString)"name:" + (QString)sql_row[1] + (QString)" location:" + (QString)sql_row[2]);
					//emit send_row((QString)sql_row[1]);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
		mysql_free_result(result);
	mysql_close(&my_con);
	//system("pause");
	return NULL;

}

MYSQL_RES* MySql_DB::mysql_test3()
{
	int res;
	mysql_init(&my_con);
	if (mysql_real_connect(&my_con, host, user, pswd, dbname, port, NULL, 0))
	{
		mysql_query(&my_con, "SET NAMES GBK"); //���ñ����ʽ
		res = mysql_query(&my_con, "select * from city");//��ѯ
		if (!res)
		{
			result = mysql_store_result(&my_con);
			if (result)
			{
				return result;
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
		mysql_free_result(result);
	mysql_close(&my_con);
	//system("pause");
	return NULL;

}
/*ִ��mysql���*/
bool MySql_DB::mysql_cmd(const string &cmd)
{
	int retval;
	if (connection_flag == true)
	{
		retval= mysql_query(&my_con, cmd.c_str());
		if (retval == 0)
		{
			return true;
		}
		else return false;//querry����
	}

	else return false;//δ����
}
/*ִ��mysql���end*/
/*����ͼƬ·��������ͼƬ�����ݿ��е�����*/
int MySql_DB::save_pic(const QString &text)
{
	string cmd = "insert into picture (pic_path)values('"+text.toStdString()+"');";
	mysql_query(&my_con, cmd.c_str());
	int x = mysql_insert_id(&my_con);
	return x;
	to_string(2);
}
/*����������ͼƬ·��������ͼƬ�����ݿ��е�����*/
int MySql_DB::save_rpic(const QString &text)
{
	string cmd = "insert into rpicture (pic_path)values('" + text.toStdString() + "');";
	mysql_query(&my_con, cmd.c_str());
	int x = mysql_insert_id(&my_con);
	return x;
}
/*����������ͼƬ·��������ͼƬ�����ݿ��е�����end*/
int MySql_DB::save_querry(int pic_id, const QString &pic_path, QDate &begaindate, QTime &begaintime, QDate &enddate, QTime &endtime)
{
	QDateTime bt;
	QDateTime et;
	//et.fromString("1970-12-12*20:20:20", "yyyy-MM-dd*hh:mm:ss");
	bt.setDate(begaindate);
	bt.setTime(begaintime);
	et.setTime(endtime);
	et.setDate(enddate);
	QString bt_s=bt.toString("yyyy-MM-dd*hh:mm:ss");
	QString et_s=et.toString("yyyy-MM-dd*hh:mm:ss");
	string cmd = "insert into querrytable (pic_id,pic_path,begin_time,end_time)values("+to_string(pic_id)+",'"+pic_path.toStdString()+"',str_to_date('" + bt_s.toStdString() + "','%Y-%m-%d*%H:%i:%s'),str_to_date('" + et_s.toStdString() + "','%Y-%m-%d*%H:%i:%s'));";
#ifdef SSMSG
	msg.setText(QString::fromStdString(cmd));
	msg.exec();
#endif
	
	//mysql_query(&my_con, cmd.c_str());
	mysql_cmd(cmd);
	/*int x = mysql_insert_id(&my_con);
	return x;*/
	int x= last_insert_PK();
#ifdef SSMSG
	msg.setText(QString::fromStdString(to_string(x)));
	msg.exec();
#endif
	return x;
	//return last_insert_PK();
}
/*���淵�ؼ�����������������ݿ��е�����һ������ߣ�ͨ��ģ��*/
/*usage:save_querry_result("c:/win/img", "1182", "2017-12-12 20:20:20", "�츮�㳡");*/
int MySql_DB::save_querry_result(struct QuerryResultStruct RS,const QString pic_path)
{
	if (connection_flag == true)
	{
		string cmd = "insert into rpicture (rpic_path) values ('" + pic_path.toStdString() + "');";
		mysql_cmd(cmd);
		int rpic_id=last_insert_PK();
		QString bt_s = RS.b_t.toString("yyyy-MM-dd*hh:mm:ss");
		QString et_s = RS.e_t.toString("yyyy-MM-dd*hh:mm:ss");
		//QString et_s = et.toString("yyyy-MM-dd*hh:mm:ss");
		cmd = "insert into querryresult (pic_id,appeartime,disappeartime,location,rpic_id,rpic_path,errorcode,zipcode,picsimilarity) values (" + to_string(RS.pic_id) + ",str_to_date('" + bt_s.toStdString() + "','%Y-%m-%d*%H:%i:%s')"+ ",str_to_date('" + et_s.toStdString() + "','%Y-%m-%d*%H:%i:%s'),'" +RS.addr.toStdString()+"',"+QString::number(rpic_id,10).toStdString()+",'"+ pic_path.toStdString() +"','"+RS.errorCode.toStdString()+"','"+RS.zipcode.toStdString()+"','"+ RS.picsimilarity.toStdString() +"');";
		mysql_cmd(cmd);
		rpic_id = last_insert_PK();
		return rpic_id;
		//msg.setText(QString::fromStdString( cmd));
		//msg.exec();
	}
	else return 0;

}
/*���淵�ؼ�����������������ݿ��е�����һ������ߣ�ͨ��ģ��end*/
/*���淵�ؼ�����������������ݿ��е�����һ������ߣ�ͨ��ģ��*/
/*usage:save_querry_result("c:/win/img", "1182", "2017-12-12 20:20:20", "�츮�㳡");*/
//int MySql_DB::save_correction_result(struct QuerryResultStruct RS, const QString pic_path)
//{
//	if (connection_flag == true)
//	{
//		string cmd = "insert into rpicture (rpic_path) values ('" + pic_path.toStdString() + "');";
//		mysql_cmd(cmd);
//		int rpic_id = last_insert_PK();
//		QString bt_s = RS.b_t.toString("yyyy-MM-dd*hh:mm:ss");
//		QString et_s = RS.e_t.toString("yyyy-MM-dd*hh:mm:ss");
//		//QString et_s = et.toString("yyyy-MM-dd*hh:mm:ss");
//		cmd = "insert into querryresult (pic_id,appeartime,disappeartime,location,rpic_id,rpic_path) values (" + to_string(RS.pic_id) + ",str_to_date('" + bt_s.toStdString() + "','%Y-%m-%d*%H:%i:%s')" + ",str_to_date('" + et_s.toStdString() + "','%Y-%m-%d*%H:%i:%s'),'" + RS.addr.toStdString() + "'," + QString::number(rpic_id, 10).toStdString() + ",'" + pic_path.toStdString() + "');";
//		mysql_cmd(cmd);
//		rpic_id = last_insert_PK();
//		return rpic_id;
//		//msg.setText(QString::fromStdString( cmd));
//		//msg.exec();
//	}
//	else return 0;
//
//}
/*���淵�ؼ�����������������ݿ��е�����һ������ߣ�ͨ��ģ��end*/
/*������һ���ɹ��Ĳ�������PK*/
int MySql_DB::last_insert_PK()
{
	if (connection_flag == true)
	{
		return mysql_insert_id(&my_con);
	}
	else return 0;
}
/*������һ���ɹ��Ĳ�������PKend*/
std::vector<QString> MySql_DB::read_resultPICSIMILARITY_bypicid(/*...*/const QString pic_id)
{
	std::vector<QString> vec;
	//string cmd = "select location from querryresult where rpic_id ="+to_string(pic_id)+";";
	string cmd = "select picsimilarity from querryresult where pic_id =" + pic_id.toStdString() + " order by appeartime asc;";
	if (connection_flag)
	{
		if (mysql_cmd(cmd))
		{
			result = mysql_store_result(&my_con);
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))
				{
					vec.push_back(QString::fromStdString(sql_row[0]));
				}
				return vec;
			}
			else return vec;
		}
		else return vec;
	}
	else return vec;
}
/*����ͼƬid��ѯ��������zipcode*/
std::vector<QString> MySql_DB::read_resultZIPCODE_bypicid(/*...*/const QString pic_id)
{
	std::vector<QString> vec;
	//string cmd = "select location from querryresult where rpic_id ="+to_string(pic_id)+";";
	string cmd = "select zipcode from querryresult where pic_id =" + pic_id.toStdString() + " order by appeartime asc;";
	if (connection_flag)
	{
		if (mysql_cmd(cmd))
		{
			result = mysql_store_result(&my_con);
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))
				{
					vec.push_back(QString::fromStdString(sql_row[0]));
				}
				return vec;
			}
			else return vec;
		}
		else return vec;
	}
	else return vec;
}
/*����ͼƬid��ѯ��������zipcode end*/
/*����ͼƬid��ѯ�������ؼ���������еص�*/
std::vector<QString> MySql_DB::read_resultLOCATION_bypicid(/*...*/const QString pic_id)
{
	std::vector<QString> vec;
	//string cmd = "select location from querryresult where rpic_id ="+to_string(pic_id)+";";
	string cmd = "select location from querryresult where pic_id =" + pic_id.toStdString() + " order by appeartime asc;";  
	if (connection_flag)
	{
		if (mysql_cmd(cmd))
		{
			result = mysql_store_result(&my_con);
				if (result)
				{
					while (sql_row = mysql_fetch_row(result))
					{
						vec.push_back(QString::fromStdString(sql_row[0]));
					}
					return vec;
				}
				else return vec;
		}
		else return vec;
	}
	else return vec;
}
/*����ͼƬid��ѯ�������ؼ���������еص�end*/
/*����ͼƬid��ѯ�������ؼ���������г���ʱ��*/
std::vector<QString> MySql_DB::read_resultAPTIME_bypicid(/*...*/const QString pic_id)
{
	std::vector<QString> vec;
	//-string cmd = "select appeartime from querryresult where rpic_id =" + to_string(pic_id) + ";";
	string cmd = "select appeartime from querryresult where pic_id =" + pic_id.toStdString() + " order by appeartime asc;";
	if (connection_flag)
	{
		if (mysql_cmd(cmd))
		{
			result = mysql_store_result(&my_con);
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))
				{
					vec.push_back(QString::fromStdString(sql_row[0]));
				}
				return vec;
			}
			else return vec;
		}
		else return vec;
	}
	else return vec;
}
/*����ͼƬid��ѯ�������ؼ���������г���ʱ��end*/
/*����ͼƬid��ѯ��������ͼƬ·��*/
std::vector<QString> MySql_DB::read_resultPICPATH_bypicid(/*...*/const QString pic_id)
{
	std::vector<QString> vec;
	//-string cmd = "select rpic_path from querryresult where rpic_id =" + to_string(pic_id) + ";";
	string cmd = "select rpic_path from querryresult where pic_id =" +pic_id.toStdString() + " order by appeartime asc;";
	if (connection_flag)
	{
		if (mysql_cmd(cmd))
		{
			result = mysql_store_result(&my_con);
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))
				{
					vec.push_back(QString::fromStdString(sql_row[0]));
				}
				return vec;
			}
			else return vec;
		}
		else return vec;
	}
	else return vec;
}
/*����ͼƬid��ѯ��������ͼƬ·��end*/
/*��ѯ����з���ֵ*/
MYSQL_RES MySql_DB::sql_cmd_rresult(const string &cmd)
{

	int retval;
	if (connection_flag == true)
	{
		retval = mysql_query(&my_con, cmd.c_str());
		if (retval == 0)
		{
			result = mysql_store_result(&my_con);
			if (result)
			{
				return *result;
			}
			//return true;
		}
		//else return false;//querry����
	}
	//else return false;//δ����
	return *result;
}
struct address_node * MySql_DB::init_addr_graph()
{
	if (addr_graph == NULL)
	{
		struct address_node * tmp1;
		struct address_node * tmp2;
		struct address_node * tmp3;
		struct address_node * tmp4;
		
		//addr_graph->next = tmp;//graph_head
		MYSQL_RES res1 = this->sql_cmd_rresult("select * from cities where code between 0 and 100;");
		MYSQL_ROW sql_row;
		addr_graph = new struct address_node();//head����ռ䲻������
		tmp1 = addr_graph;
		while (sql_row = mysql_fetch_row(&res1))
		{
			tmp1->next = new  struct address_node();//ͷ�ڵ㲻������
			tmp1 = tmp1->next;
			tmp1->name = QString::fromStdString(sql_row[3]);
			tmp1->id = atoi(sql_row[0]);
			tmp1->code = atoi(sql_row[1]);
			tmp1->parentcode = atoi(sql_row[2]);
			tmp1->level = atoi(sql_row[4]);
			QString cmd = "select * from cities where  parentcode = " + QString::fromStdString(sql_row[1]) + ";";
			MYSQL_RES res2 = this->sql_cmd_rresult(cmd.toStdString());
			tmp1->child = new struct address_node();//Ϊ��һ��ͷ����ռ�
			tmp2 = tmp1->child;
			while (sql_row = mysql_fetch_row(&res2))
			{
				tmp2->next = new  struct address_node();//ͷ�ڵ㲻������
				tmp2 = tmp2->next;
				tmp2->name = QString::fromStdString(sql_row[3]);
				tmp2->id = atoi(sql_row[0]);
				tmp2->code = atoi(sql_row[1]);
				tmp2->parentcode = atoi(sql_row[2]);
				tmp2->level = atoi(sql_row[4]);
				QString cmd = "select * from cities where  parentcode = " + QString::fromStdString(sql_row[1]) + ";";
				MYSQL_RES res3= this->sql_cmd_rresult(cmd.toStdString());
				tmp2->child = new struct address_node();//Ϊ��һ��ͷ����ռ�
				tmp3 = tmp2->child;
				while (sql_row = mysql_fetch_row(&res3))
				{
					tmp3->next = new  struct address_node();
					tmp3 = tmp3->next;
					tmp3->name = QString::fromStdString(sql_row[3]);
					tmp3->id = atoi(sql_row[0]);
					tmp3->code = atoi(sql_row[1]);
					tmp3->parentcode = atoi(sql_row[2]);
					tmp3->level = atoi(sql_row[4]);
					QString cmd = "select * from cities where  parentcode = " + QString::fromStdString(sql_row[1]) + ";";
					MYSQL_RES res4 = this->sql_cmd_rresult(cmd.toStdString());
					tmp3->child = new struct address_node();//Ϊ��һ��ͷ����ռ�
					tmp4 = tmp3->child;
					while (sql_row = mysql_fetch_row(&res4))
					{
						tmp4->next = new  struct address_node();
						tmp4 = tmp4->next;
						tmp4->name = QString::fromStdString(sql_row[3]);
						tmp4->id = atoi(sql_row[0]);
						tmp4->code = atoi(sql_row[1]);
						tmp4->parentcode = atoi(sql_row[2]);
						tmp4->level = atoi(sql_row[4]);
						tmp4->child = NULL;
					}
					tmp4->next = NULL;
				}
				tmp3->next = NULL;
			}
			tmp2->next = NULL;
		}
		tmp1->next = NULL;
		return addr_graph;
	}
	else return addr_graph;
}
int MySql_DB::CheckUserPWD(const QString username, const QString password)
{
	if (connection_flag)
	{
		if (mysql_cmd("select pwd from user where aname='"+username.toStdString()+"'"))
		{
			result = mysql_store_result(&my_con);
			if (result)
			{
				sql_row = mysql_fetch_row(result);
				if (QString::compare(QString::fromStdString(sql_row[0]) , password)==0)
				{
					return 1;//��ȷ
				}
				else return 0;//�û�/�������
			}
			else return 0;
		}
		else return -2;
	}
	else return -1;
}