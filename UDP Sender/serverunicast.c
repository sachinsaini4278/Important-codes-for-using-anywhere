#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main()
{
int listenfd,port,r;
char buff[1024]="HELLO WORLD";
struct sockaddr_in servaddr,cliaddr;
socklen_t servlen;
listenfd = socket(AF_INET,SOCK_DGRAM,0);
if(listenfd==-1)
{
perror("Socket");
return 0;
}
char IP[20];	
printf("Enter IP\n");
scanf("%s",IP);	
printf("\n Enter the port no:");
scanf("%d",&port);
printf("The port no is:%d",port);
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(port);
//servaddr.sin_addr.s_addr = inet_addr("192.168.95.136");
servaddr.sin_addr.s_addr = inet_addr(IP);
int count=0;
while(1){
sendto(listenfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
//r=recvfrom(listenfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,&servlen);
printf("\n SENT:%s\n",buff);
sleep(1);
}
exit(0);
return 0;
}


