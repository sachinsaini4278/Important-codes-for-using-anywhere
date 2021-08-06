 #include <stdio.h>          /* printf(), snprintf() */
 #include <stdlib.h>         /* strtol(), exit() */
 #include <sys/types.h>
 #include <sys/socket.h>     /* socket(), setsockopt(), bind(), recvfrom(), sendto() */
 #include <errno.h>          /* perror() */
 #include <netinet/in.h>     /* IPPROTO_IP, sockaddr_in, htons(), htonl() */
 #include <arpa/inet.h>      /* inet_addr() */
 #include <unistd.h>         /* fork(), sleep() */
 #include <sys/utsname.h>    /* uname() */
 #include <string.h>         /* memset() */
 
 #define MAXLEN 1024
 
 
 int main()
 {
    string group;
	int port;
	cout<<"Enter Server ip : ";
	cin>>group;

	cout<<"\nEnter Server port : ";
	cin>>port;
	
	u_char no = 0;
      u_int yes = 1;      /* Used with SO_REUSEADDR. 
                             In Linux both u_int */
                         /* and u_char are valid. */
	struct sockaddr_in mcast_group;
	struct ip_mreq mreq;
	struct utsname name;
	int n;
    socklen_t len;
    struct sockaddr_in from;
    char message [MAXLEN+1];
    int recv_s;
     
     memset(&mcast_group, 0, sizeof(mcast_group));
     mcast_group.sin_family = AF_INET;
     mcast_group.sin_port = htons(port);
     mcast_group.sin_addr.s_addr = inet_addr(group.c_str());
     
     if ( (recv_s=socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
         perror ("recv socket");
         exit(1);
     }
 
     if (setsockopt(recv_s, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
         perror("reuseaddr setsockopt");
         exit(1);
     }
 
     if (bind(recv_s, (struct sockaddr*)&mcast_group, sizeof(mcast_group)) < 0) {
         perror ("bind");
         exit(1);
     }

    	/* Preparatios for using Multicast */ 
	mreq.imr_multiaddr = mcast_group.sin_addr;
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);

     /* Tell the kernel we want to join that multicast group. */
	if (setsockopt(recv_s, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
	perror ("add_membership setsockopt");
	exit(1);
	}
 
	for (;;) {
	len=sizeof(from);
        if ( (n=recvfrom(recv_s, message, MAXLEN, 0, 
                        (struct sockaddr*)&from, &len)) < 0) {
            perror ("recv");
            exit(1);
        }
        message[n] = '\0'; /* null-terminate string */
        printf("%s: Received message from %s, size=%d !!\n", 
                name.nodename,
                inet_ntoa(from.sin_addr), n);
      printf("Message : %s ",message);
}