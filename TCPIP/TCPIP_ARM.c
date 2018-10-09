#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#define SERVPORT 3333
#define BACKLOG 10
#define MAX_CONNECTED_NO 10
#define MAXDATASIZE 64


static char RcvBuf[100];
static char SendBuf[100];
int main()
{
	struct sockaddr_in server_sockaddr,client_sockaddr;
	int sin_size,recvbytes;
	int sockfd,client_fd;
	char buf[MAXDATASIZE];

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket");
		exit(1);
	}
	printf("socket success! sockfd=%d\n",sockfd);
	
	server_sockaddr.sin_family=AF_INET;
	server_sockaddr.sin_port=htons(SERVPORT);
	server_sockaddr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(server_sockaddr.sin_zero),8);

	if(bind(sockfd,(struct sockaddr *)&server_sockaddr,sizeof(struct sockaddr))==-1)
	{
		perror("bind");
		exit(1);
	}
	printf("bind success!\n");
	if(listen(sockfd,BACKLOG)==-1)
	{
		perror("listen");
		exit(1);
	}
	printf("listen success\n");
	if((client_fd=accept(sockfd,(struct sockaddr *)&client_sockaddr,&sin_size))==-1)
	{
		perror("accept");
		exit(1);
	}
	printf("accept success\n");
	
	while(1)
	{
		if((recvbytes=recv(client_fd,buf,MAXDATASIZE,0))>0)
		{	
			buf[recvbytes]='\0';
			printf("Receive:%s\n",buf);

			HandleTCP(buf,recvbytes);
			//printf("222\n");
			send(client_fd,SendBuf,8,0);
			//printf("333\n");
		}		
		
		else if(recvbytes<=0)
		{
			printf("Connection closed!\n");
			close(client_fd);
			client_fd=accept(sockfd,(struct sockaddr *)&client_sockaddr,&sin_size);
		}
	}

	close(sockfd);
}


void HandleTCP(char *bf,int len)
{
	int i,RcvPtr=0;
	for(i=0;i<len;i++)
	{
		if(*(bf+i)=='2')
		{
			//printf("b1\n");
			RcvBuf[0]='2';
			RcvPtr=1;
		}
		else if(*(bf+i)=='3')
		{
			//printf("c1\n");
			if(RcvPtr==7) ParseFrame();
			//printf("c1end\n");
			RcvPtr=0;
		}
		else
		{
			//printf("ptr %d\n",RcvPtr);
			if(RcvPtr>0) RcvBuf[RcvPtr++]=*(bf+i);
			//printf("bf i %c\n",*(bf+i));
		}
	}
}


void ParseFrame()
{
	int adc,led;
	int d,len;
	char buffer[32];
	
	SendBuf[0]='2';
	if(RcvBuf[1]=='R')
	{
		SendBuf[1]='B';
		SendBuf[2]=RcvBuf[2];
		switch(RcvBuf[2])
		{
			case '0': 
				adc=open("/dev/adc",0);
				if(adc<0) SendBuf[1]='E';
				else 
				{
					len=read(adc,buffer,sizeof(buffer)-1);
					sscanf(buffer,"%d",&d);
					sprintf(&SendBuf[3],"%04d",d);
					close(adc);
				}
				SendBuf[7]='3';
				break;
			case '1':
				adc=open("/dev/adc",1);
				if(adc<0) SendBuf[1]='E';
				else 
				{
					len=read(adc,buffer,sizeof(buffer)-1);
					sscanf(buffer,"%d",&d);
					sprintf(&SendBuf[3],"%04d",d);
					close(adc);
				}
				SendBuf[7]='3';
				break;
			case '2':
				adc=open("/dev/adc",2);
				if(adc<0) SendBuf[1]='E';
				else 
				{
					len=read(adc,buffer,sizeof(buffer)-1);
					sscanf(buffer,"%d",&d);
					sprintf(&SendBuf[3],"%04d",d);
					close(adc);
				}
				SendBuf[7]='3';
				break;
			case '3':
				adc=open("/dev/adc",3);
				if(adc<0) SendBuf[1]='E';
				else 
				{
					len=read(adc,buffer,sizeof(buffer)-1);
					sscanf(buffer,"%d",&d);
					sprintf(&SendBuf[3],"%04d",d);
					close(adc);
				}
				SendBuf[7]='3';
				break;
		}
	}
	else if(RcvBuf[1]=='W')
	{
		if(RcvBuf[2]=='4')
		{
			led=open("/dev/leds",O_RDONLY);
			//RcvBuf[6]-0x30;
			if(RcvBuf[3]=='1') ioctl(led,0,3);
			else if(RcvBuf[3]=='0') ioctl(led,1,3);
			if(RcvBuf[4]=='1') ioctl(led,0,2);
			else if(RcvBuf[4]=='0') ioctl(led,1,2);
			if(RcvBuf[5]=='1') ioctl(led,0,1);
			else if(RcvBuf[6]=='0') ioctl(led,1,1);
			if(RcvBuf[6]=='1') ioctl(led,0,0);
			else if(RcvBuf[6]=='0') ioctl(led,1,0);
			
			close(led);
		}
	}
}
