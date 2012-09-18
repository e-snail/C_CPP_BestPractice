/* 
client.c 
*/ 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <stdio.h> 
#include <sys/un.h> 
#include <unistd.h> 

int main() 
{ 
	int sockfd; 
	int len; 
	struct sockaddr_un address; 
	int result; 
	char ch='A'; 

	sockfd=socket(AF_UNIX,SOCK_STREAM,0); 
	/*以上建立客户端的套接口,采用AF_UNIX的unix域协议*/ 

	address.sun_family=AF_UNIX; 
	strcpy(address.sun_path,"server_socket"); 
	len=sizeof(address); 
	/*以上创建服务器套接口的地址,其中包括套接口类型,名称*/ 

	result=connect(sockfd,(struct sockaddr *)&address,len); 

	if(result==-1){ 
		perror("oops:client1"); 
		exit(1); 
	} 
	/*以上我们试图与服务器套接口建立连接*/ 

	write(sockfd,&ch,1); 
	read(sockfd,&ch,1); 
	/*如果成功,将向服务器端发送一个字符,然后读取服务器的回答*/ 

	printf("char from server=%c\n",ch); 
	close(sockfd); 
	exit(0); 
} 
