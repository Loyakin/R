#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main (int argc, char*  argv[])
{
	//dichiaro valori base 
	int n;
	int portno, clilen;
	int sockfd;
	int bytesread;
	struct sockaddr_in a_server, a_client;
	char buffer[1000];

	//inizializzo socket server + controllo
	sockfd = socket(AF_INET,SOCK_DGRAM, 0);

	if(sockfd < 0)
	{
		printf("ERROR opening socket");
	}
	
	//inizializzo alcuni valori del server dopo aver azzerato i dati precedenti nella struttura
	bzero((char*)&a_server, sizeof(a_server));
	portno = atoi(argv[1]);
	a_server.sin_family = AF_INET;
	a_server.sin_addr.s_addr = INADDR_ANY;
	a_server.sin_port = htons(portno);
	
	//apro la porta controllando che tutto vada bene
	n = bind(sockfd, (struct sockaddr*)&a_server, sizeof(a_server));

	if (n < 0 )
		printf ("ERRORE nel binding\n");

	clilen = sizeof(a_client);

	//ciclo ricezione
	for(;;)
	{
		printf("ciao\n");
		bzero(buffer, 1000);

		printf("sono prima\n");

		bytesread = recvfrom(sockfd, buffer, 1000, 0, (struct sockaddr*)&a_client, (socklen_t*)&clilen);
		//non arriva oltre la recvfrom, non stmapa nulla...
	
		printf("sono dopo\n");	
	
		printf("è stato mandato il testo: %s", buffer);

		printf("\n ricevuto \n");
	}
}
	  
