#include "csapp.h"

void doit(int fd);
void read_requesthdrs(rio_t *rp);
void serve(int fd, char *filename, int filesize);

int main(int argc, char **argv)
{
	int listenfd, connfd, port, clientlen;
	struct sockaddr_in clientaddr;
	//get port from argument
	port = atoi(argv[1]);
	//listen to port argument
	listenfd = open_listenfd(port);
	//run until ctrl+c
	while(1){
		clientlen = sizeof(clientaddr);
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen); //accept incoming connection
		doit(connfd); //respond to connection
		Close(connfd); //close connection
	}
}

void doit(int fd)
{
	struct stat sbuf;
        char buf[1000], method[1000], uri[1000], version[1000], filename[1000];
        rio_t rio;
	//parse request from fd
        Rio_readinitb(&rio, fd);
        Rio_readlineb(&rio, buf, 1000);
        sscanf(buf, "%s %s %s", method, uri, version);
        read_requesthdrs(&rio);
	//get filename from uri
	strcpy(filename, ".");
	strcat(filename, uri);

	stat(filename, &sbuf);
	//serve file contents back to requester
        serve(fd, filename, sbuf.st_size);
}

void read_requesthdrs(rio_t *rp)
{
	char buf[1000];
	//read until end of line to get all header content
	Rio_readlineb(rp, buf, 1000);
	while(strcmp(buf, "\r\n"))
		Rio_readlineb(rp, buf, 1000);

	return;
}

void serve(int fd, char *filename, int filesize)
{
	int srcfd;
	char *srcp, filetype[MAXLINE], buf[MAXBUF];

	Rio_writen(fd, buf, strlen(buf));

	srcfd = Open(filename, O_RDONLY, 0);
	srcp = Mmap(0, filesize, PROT_READ, MAP_PRIVATE, srcfd, 0);
	Close(srcfd);

	Rio_writen(fd, srcp, filesize);
	Munmap(srcp, filesize);
}
