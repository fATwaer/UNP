#include "unp.h"


int 
main(int argc, char **argv)
{
    int                sockfd, n, connfd;
    char               recvline[MAXLINE+1];
    struct sockaddr_in servaddr, clientaddr;
    socklen_t           len;
    char                buf[MAXLINE];

    if (argc != 2)
        err_quit("usage: a.out <IP address>");
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(13);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_sys("inect_pton error");
    if (connfd = (connect(sockfd, (SA *)&servaddr, sizeof(servaddr))) < 0)
        err_sys("connect error");

    len = sizeof(clientaddr);
    if (getsockname(sockfd, (SA *)&clientaddr, &len) < 0)
        err_quit("get name error");
    printf("self ip = %s, port = %d\n", 
           inet_ntop(AF_INET, &clientaddr.sin_addr, buf, MAXLINE),
           ntohs(clientaddr.sin_port));


    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF)    
            err_sys("fputs error");
    }

    if (n < 0)
        err_sys("read error");

    exit(0);
}
