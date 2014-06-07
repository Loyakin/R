#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>

int main (int argc, char* argv[])
{
	int portno;
	int sockfd;
	struct sockaddr_in a_server;
	struct hostent* server;
	char manda[1000];

	portno = atoi(argv[1]);
	sockfd = (AF_INET, SOCK_DGRAM, 0);

	if (sockfd < 0) 
	{
		printf("ERROR opening socket");
	}

	server = gethostbyname(argv[2]);

	if (server == NULL)
	{
		printf("ERROR non such host");
	}

	bzero((char*) &a_server, sizeof (a_server));
	a_server.sin_family = AF_INET;
	bcopy((char*)server->h_addr, (char*)&a_server.sin_addr.s_addr, server->h_length);
	a_server.sin_port = htons(portno);

	while (fgets(manda, 1000, stdin))
	{
		sendto(sockfd,manda, 10, 0, (struct sockaddr*)&a_server, sizeof(a_server));
		printf ("mandato \n");
	}  	
}
