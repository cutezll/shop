#include <iostream>
#include <stdio.h>
#include <WINSOCK2.H>
using namespace std;

#pragma comment(lib,"ws2_32.lib")

#define BUF_SIZE 100

int main()
{
	char* filename="G:\\001.wmv";
	FILE *fd=fopen(filename,"rb");
	if (fd==NULL)
	{
		cout<<"文件打开失败"<<endl;
		exit(0);
	}

	WSADATA wsadata;
	WSAStartup(MAKEWORD(2,2),&wsadata);
	
	SOCKET servsocket=socket(AF_INET,SOCK_STREAM,0);
	sockaddr_in sockAddr;
	memset(&sockAddr,0,sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);

	if(SOCKET_ERROR==bind(servsocket,(SOCKADDR*)&sockAddr,sizeof(sockAddr)))
	{
		cout<<"bind 错误"<<endl;
		exit(-1);
	}
	listen(servsocket,20);

	SOCKADDR clnsockAddr;
	int len=sizeof(clnsockAddr);
	SOCKET clnsocket=accept(servsocket,&clnsockAddr,&len);
	if (clnsocket)
	{
		cout<<"文件正在传输......."<<endl;
	}
	char buf[BUF_SIZE];
	int ncount=0;
	while ((ncount=fread(buf,1,BUF_SIZE,fd))>0)
	{
		send(clnsocket,buf,ncount,0);
	}

	shutdown(clnsocket,SD_SEND);
	recv(clnsocket,buf,BUF_SIZE,0);
	cout<<"文件传输完成"<<endl;

	fclose(fd);
	closesocket(clnsocket);
	closesocket(servsocket);
	WSACleanup();

	return 0;
}