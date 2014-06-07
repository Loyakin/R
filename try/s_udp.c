#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main (int argc, char*  argv[])
{
	int n;
	int portno, clilen;
	int sockfd;
	int bytesread;
	struct sockaddr_in a_server, a_client;
	char buffer[1000];

	sockfd = socket(AF_INET,SOCK_DGRAM, 0);

	if(sockfd < 0)
	{
		printf("ERROR opening socket");
	}
	
	bzero((char*)&a_server, sizeof(a_server));
	portno = atoi(argv[1]);
	a_server.sin_family = AF_INET;
	a_server.sin_addr.s_addr = INADDR_ANY;
	a_server.sin_port = htons(portno);
	
	n = bind(sockfd, (struct sockaddr*)&a_server, sizeof(a_server));

	printf ("%d\n", n);

	clilen = sizeof(a_client);

	for(;;)
	{
		printf("ciao\n");
		bzero(buffer, 1000);

		printf("sono prima\n");

		bytesread = recvfrom(sockfd, buffer, 1000, 0, (struct sockaddr*)&a_client, (socklen_t*)&clilen);
	
		printf("sono dopo\n");	
	
		printf("è stato mandato il testo: %s", buffer);

		printf("\n ricevuto \n");
	}
}
	  
