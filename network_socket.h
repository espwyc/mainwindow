#ifndef NETWORK_SOCKET_H
#define NETWORK_SOCKET_H

#include <fstream>  
#include <string>  
#include <iostream> 
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <thread>
#include "winsock2.h"
#include "Ws2tcpip.h"
#pragma comment(lib,"ws2_32.lib")//引用库文件

SOCKET client_socket;
SOCKADDR Client_addr;
int len = sizeof(SOCKADDR);

struct mypack
{
	unsigned long id;
	int pic_gcount;
	char location[50];
	char data[50];
	char canshu1[10];
	char canshu2[10];
	char picbuf[40960];
};

void read_t()
{
	char rBuff[1024];
	int iret;
	while (1)
	{
		memset(rBuff, 0, sizeof(rBuff));
		iret = recv(client_socket, rBuff, sizeof(rBuff), 0);
		if (iret == SOCKET_ERROR)
		{
			std::cout << "receive error" << std::endl;
		}
		std::cout << rBuff << std::endl;
	}
}
void write_t()
{
	char wBuff[1024];
	int iret;
	while (1)
	{
		memset(wBuff, 0, sizeof(wBuff));
		std::cin >> wBuff;
		iret = send(client_socket, wBuff, sizeof(wBuff), 0);
		if (iret == SOCKET_ERROR)
		{
			std::cout << "receive error" << std::endl;
		}
		//std::cout << wBuff <<std:: endl;
	}
}

void sendpic()
{
	std::ifstream fin("1.jpg", std::ifstream::binary);
	//std::ifstream fin("1.jpg");
	//std::ofstream fout("2.jpg", std::ofstream::binary);
	//std::string filename;
	//std::string line;
	//char buff[1024];
	struct mypack sendpac;
	int iret;
	sendpac.id = 0;
	char *s = "电子科技大学，成都";
	memcpy(sendpac.location, s, strlen(s));
	//sendpac.location = "chengduchengdu";
	if (fin) // 打开成功 
	{
		/*while (getline(fin, line)) // line中不包括每行的换行符
		{
		cout << line << endl;
		fout << line << endl;
		}*/
		//while (fin.read(buff, sizeof(buff)))
		while (fin.read(sendpac.picbuf, sizeof(sendpac.picbuf)))
		{
			//std::cout << buff << std::endl;
			//fout.write(buff, sizeof(buff));
			//iret = send(client_socket, buff, sizeof(buff), 0);
			sendpac.pic_gcount = fin.gcount();
			iret = send(client_socket, (const char*)(&sendpac), sizeof(sendpac), 0);
			if (iret == SOCKET_ERROR)
			{
				std::cout << "send error" << std::endl;
			}
			memset(sendpac.picbuf, 0, sizeof(sendpac.picbuf));
			sendpac.id++;
			std::cout << sendpac.id << std::endl;

		}
		sendpac.pic_gcount = fin.gcount();
		iret = send(client_socket, (const char*)(&sendpac), sizeof(sendpac), 0);
		if (iret == SOCKET_ERROR)
		{
			std::cout << "send error" << std::endl;
		}
	}
	else // 没有该文件  
	{
		std::cout << "no such file" << std::endl;
	}
	//fin.close();
	char a;
	std::cin >> a;
	return;
}
void receive_pic()
{
	struct mypack recvpac;
	int rsize = sizeof(recvpac);
	//(const char*)(&recvpac);
	//ifstream fin("1.jpg", std::ifstream::binary);
	std::ofstream fout("2.jpg", std::ofstream::binary);
	//std::ofstream fout("2.jpg");
	//string filename;
	//string line;
	//char buff[1024];
	int iret;
	while (1)
	{
		memset(&recvpac, 0, rsize);
		iret = recv(client_socket, (char*)&recvpac, rsize, 0);
		if (iret == SOCKET_ERROR)
		{
			std::cout << "receive error" << std::endl;
			break;
		}
		std::cout << "id:" << recvpac.id << "  location" << recvpac.location << "\n" << std::endl;
		//std::cout << buff << std::endl;
		//printf("id:%ld loc:%s\n", recvpac.id, recvpac.location);
		fout.write(recvpac.picbuf, recvpac.pic_gcount);
		//Sleep(1000);
	}

	//fout.write(recvpac.picbuf, sizeof(recvpac.picbuf));
	fout.close();
	char a;
	std::cin >> a;
	return;
	//if (fin) // 打开成功 
	//{
	/*while (getline(fin, line)) // line中不包括每行的换行符
	{
	cout << line << endl;
	fout << line << endl;
	}*/
	//}
	//else // 没有该文件  
	//{
	//	cout << "no such file" << endl;
	//}
}


int test()
{
	int mode = -1;
	std::cout << "服务器模式输1客户端模式输0：测试client发图片输3，测试server收图片输4" << std::endl;
	std::cin >> mode;
	int port = 5000;
	SOCKADDR_IN server_addr_in;
	server_addr_in.sin_family = AF_INET;
	server_addr_in.sin_port = htons(port);
	InetPton(AF_INET, _T("127.0.0.1"), &server_addr_in.sin_addr.s_addr);
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		/*启用WSA(Windows Sockets Asynchronous，Windows异步套接字)*/
		printf("初始化失败");
		return 0;
	}
	if (mode == 1)
	{

		SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
		/*SOCKADDR_IN server_addr_in;
		server_addr_in.sin_family = AF_INET;
		server_addr_in.sin_port = htons(port);
		InetPton(AF_INET, _T("127.0.0.1"), &server_addr_in.sin_addr.s_addr);*/
		int retVal = bind(server_socket, (LPSOCKADDR)&server_addr_in, sizeof(SOCKADDR_IN));
		if (retVal == SOCKET_ERROR) {
			printf("bind失败:%d\n", WSAGetLastError());
			return 0;
		}
		if (listen(server_socket, 10) == SOCKET_ERROR)
		{//listen第二个参数是 链接上限
			printf("监听失败:%d", WSAGetLastError());
			return 0;
		}
		//while (1)
		std::cout << "listen:\n" << std::endl;
		client_socket = accept(server_socket, &Client_addr, NULL);
		//第三个参数存放addrlen是个局部整形变量，设置为sizeof(struct   sockaddr_in)，如不用可填null
		//存放client的info，若不用可填null
		std::cout << "accept:" << std::endl;
		std::thread read(read_t);
		std::thread write(write_t);
		//while (1);
		read.join();
		write.join();
		return 0;
	}
	else if (mode == 0)
	{
		client_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (SOCKET_ERROR == client_socket)
		{
			printf("Socket() error:%d", WSAGetLastError());
			return 0;
		}
		while (true)
		{
			if (connect(client_socket, (struct  sockaddr*)&server_addr_in, sizeof(server_addr_in)) == INVALID_SOCKET) {
				printf("连接失败:%d", WSAGetLastError());
				//return 0;
				Sleep(3000);
			}
			else break;
		}
		std::cout << "connect:" << std::endl;
		std::thread read(read_t);
		std::thread write(write_t);
		read.join();
		write.join();
		return 0;
	}
	else if (mode == 3)
	{
		client_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (SOCKET_ERROR == client_socket)
		{
			printf("Socket() error:%d", WSAGetLastError());
			return 0;
		}
		while (true)
		{
			if (connect(client_socket, (struct  sockaddr*)&server_addr_in, sizeof(server_addr_in)) == INVALID_SOCKET) {
				printf("连接失败:%d", WSAGetLastError());
				//return 0;
				Sleep(3000);
			}
			else break;
		}
		std::cout << "connect:" << std::endl;
		sendpic();
		std::cout << sizeof(mypack) << std::endl;
		//char a;
		//std::cin >> a;
		return 0;
	}
	else if (mode == 4)
	{
		SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
		/*SOCKADDR_IN server_addr_in;
		server_addr_in.sin_family = AF_INET;
		server_addr_in.sin_port = htons(port);
		InetPton(AF_INET, _T("127.0.0.1"), &server_addr_in.sin_addr.s_addr);*/
		int retVal = bind(server_socket, (LPSOCKADDR)&server_addr_in, sizeof(SOCKADDR_IN));
		if (retVal == SOCKET_ERROR) {
			printf("bind失败:%d\n", WSAGetLastError());
			return 0;
		}
		if (listen(server_socket, 10) == SOCKET_ERROR)
		{//listen第二个参数是 链接上限
			printf("监听失败:%d", WSAGetLastError());
			return 0;
		}
		//while (1)
		std::cout << "listen:\n" << std::endl;
		client_socket = accept(server_socket, &Client_addr, NULL);
		//第三个参数存放addrlen是个局部整形变量，设置为sizeof(struct   sockaddr_in)，如不用可填null
		//存放client的info，若不用可填null
		std::cout << "accept:" << std::endl;
		receive_pic();
		return 0;
	}
	


#endif