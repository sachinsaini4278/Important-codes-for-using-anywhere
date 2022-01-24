 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>
#include <iostream>
#include <ctime>
#include "Nanolog.hpp"
int main()
{
     std::time_t t = time(NULL) + 19800;
    auto gmtime = std::gmtime( &t) ;
    char buffer[32];
    strftime( buffer, 32, "%Y%m%d-%T", gmtime ) ;
    std::string t1 ( buffer ) ;
    std::string fileName = "log-" + t1 + "_";
//    std::cout << "FName: " << fileName << std::endl ;
    nanolog::initialize(nanolog::GuaranteedLogger(), "logs/", fileName, 200);
	LOG_INFO<<"*************************";
     	int sfd,r,bi,port;
	char buff[1024];
	struct sockaddr_in servaddr,cliaddr;
	socklen_t clilen;
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sfd==-1)
	{
		perror("Socket");
		return 0;
	}

	printf("\n Enter the port no:");
	scanf("%d",&port);
	printf("The port no is:%d\n",port);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = INADDR_ANY;

	bi=bind(sfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(bi==-1)
	{
		perror("Bind()");
		return 0;
	}

	clilen = sizeof(cliaddr);
	
	int count=0;
	while(1){

	r=recvfrom(sfd,buff,sizeof(buff),0,(struct sockaddr*)&cliaddr,&clilen);
//	printf("Server:%s\n",buff);
	LOG_INFO<<buff;
	buff[r]=0;

	}
exit(0);
return 0;
}
