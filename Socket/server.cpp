#include <stdio.h>
#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")

#define BUF_SIZE 100
int main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2,2),&wsadata);

	SOCKET severSock=socket(AF_INET,SOCK_STREAM,0);

	sockaddr_in sockAddr;
	memset(&sockAddr,0,sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1122);

	if (SOCKET_ERROR==bind(severSock,(sockaddr *)&sockAddr,sizeof(sockAddr)))
	{
		printf("bind error\n");
		return 1;
	}
	

	listen(severSock,10);

	sockaddr_in clnSock;
	memset(&clnSock,0,sizeof(clnSock));
	int clnlen = sizeof(clnSock);
	char buf[BUF_SIZE]={0};
	while (1)
	{
		SOCKET clnsocket = accept(severSock,(SOCKADDR*)&clnSock,&clnlen);
	
		int recvlen=recv(clnsocket,buf,BUF_SIZE,0);
		send(clnsocket,buf,recvlen,0);

		closesocket(clnsocket);
		memset(buf,0,BUF_SIZE);

	}

	closesocket(severSock);

	WSACleanup();

	return 0;
}