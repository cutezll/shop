#include <stdio.h>
#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")

#define BUF_SIZE 100

int main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2,2),&wsadata);

	sockaddr_in serverAddr;
	memset(&serverAddr,0,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons(1122);
	char bufSend[BUF_SIZE]={0};
	char bufRecv[BUF_SIZE]={0};

	while (1)
	{
		SOCKET clnsocket = socket(AF_INET,SOCK_STREAM,0);
		if (SOCKET_ERROR==connect(clnsocket,(SOCKADDR*)&serverAddr,sizeof(serverAddr)))
		{
			printf("connect error\n");
			return 1;
		}
		
		printf("请输入内容：");
		gets(bufSend);
		send(clnsocket,bufSend,strlen(bufSend),0);
		printf("sizeof(bufSend)=%d\n",sizeof(bufSend));
		printf("strlen(bufSend)=%d\n",strlen(bufSend));

		recv(clnsocket,bufRecv,sizeof(bufRecv),0);
		printf("来自服务器端的消息回告是：%s\n",bufRecv);

		
		memset(&bufSend,0,sizeof(bufSend));
		memset(&bufRecv,0,sizeof(bufRecv));
		closesocket(clnsocket);
	}

	WSACleanup();
	return 0;
}
