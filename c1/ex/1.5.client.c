#include "unp.h"
#include <errno.h>

int 
main(int argc, char **argv)
{
    int                sockfd, n, count = 0;
    char               recvline[MAXLINE+1];
    struct sockaddr_in servaddr;

    if (argc != 2)
        err_quit("usage: a.out <IP address>");
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(9999);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_sys("inect_pton error");
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
        err_sys("connect error");

    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        count++;
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF)    
            err_sys("fputs error");
    }

    if (n < 0)
        err_sys("read error");
    printf("count = %d\n", count);
    exit(0);
}
