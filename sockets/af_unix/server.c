/* 
server.c 
*/ 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <stdio.h> 
#include <sys/un.h> 
#include <unistd.h> 

int main() 
{ 
	int server_sockfd,client_sockfd; 
	int server_len,client_len; 
	struct sockaddr_un server_address; 
	struct sockaddr_un client_address; 
	unlink("server_socket"); 
	/*如果存在同名的套接口,则先删除*/ 

	server_sockfd=socket(AF_UNIX,SOCK_STREAM,0); 
	/*以上建立套接口,这时候无名*/ 

	server_address.sun_family=AF_UNIX; 
	strcpy(server_address.sun_path,"server_socket"); 
	server_len=sizeof(server_address); 
	bind(server_sockfd,(struct sockaddr *)&server_address,server_len); 

	listen(server_sockfd,5); 
	/*以上创建监听队列.等待用户的连接请求*/ 

	while(1) 
	{ 
		char ch; 
		printf("server waiting\n"); 
		client_sockfd=accept(server_sockfd,(struct sockaddr *)&client_address,&client_len); 
		/*以上接受一个客户的请求*/ 

		read(client_sockfd,&ch,1); 
		/*因为连接一旦建立,客户就会先发消息过来,所以服务器先读*/ 

		ch++; 
		write(client_sockfd,&ch,1); 
		/*把读取的字符串做简单处理,回送*/ 
		close(client_sockfd); 
	} 
	exit(1);
} 

