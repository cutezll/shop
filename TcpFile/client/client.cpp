#include <iostream>
#include <stdio.h>
#include <WINSOCK2.H>
using namespace std;

#pragma comment(lib,"ws2_32.lib")

#define BUF_SIZE 1024

int main()
{
	char filename[64]={0};
	cout<<"�����ļ�����";
	cin>>filename;
//	printf("%s",filename);
	FILE* file=fopen(filename,"wb");
	if (file==NULL)
	{
		cout<<"�ļ�����������"<<endl;
		exit(-1);
	}

	WSADATA wsadata;
	WSAStartup(MAKEWORD(2,2),&wsadata);
	
	SOCKET clnsocket=socket(AF_INET,SOCK_STREAM,0);

	sockaddr_in sockAddr;
	memset(&sockAddr,0,sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port= htons(1234);
	if(SOCKET_ERROR==connect(clnsocket,(SOCKADDR*)&sockAddr,sizeof(sockAddr)))
	{
		cout<<"���Ӵ���"<<endl;
		exit(-1);
	}else
	{
		cout<<"�ļ����ڴ���....."<<endl;
	}

	char filebuf[BUF_SIZE]={0};
	int nCount;
	while ((nCount=recv(clnsocket,filebuf,BUF_SIZE,0))>0)
	{
		fwrite(filebuf,nCount,1,file);
		
	}
	puts("�ļ��������");
	
	fclose(file);
	closesocket(clnsocket);
	WSACleanup();
	return 0;
}
