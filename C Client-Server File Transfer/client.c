#include "csapp.h"

int main(int argc, char **argv)
{
	int clientfd, port;
	char *host, *file, buf[1000];
	rio_t rio;
	//get host, port, and file from arguments
	host = argv[1];
	port = atoi(argv[2]);
	file = argv[3];
	//open connection using host and port
	clientfd = Open_clientfd(host, port);
	Rio_readinitb(&rio, clientfd);
	//build request string
	char request[150];
	strcpy(request, "GET /");
	strcat(request, file);
	strcat(request, " HTTP/1.1\r\nHost: ");
	strcat(request, host);
	strcat(request, "\r\n\r\n");
	//make request to server
	Rio_writen(clientfd, request, strlen(request));
	//output response to stdout
	while(Rio_readlineb(&rio, buf, 1000) > 0)
		Fputs(buf, stdout);
	//clean up
	Close(clientfd);
	exit(0);
}
