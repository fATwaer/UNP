#include "unp.h"
#include <netinet/tcp.h>

int 
main(int argc, char **argv)
{
    int                sockfd, n, recv, mss;
    socklen_t          len;
    char               recvline[MAXLINE+1];
    struct sockaddr_in servaddr;

    if (argc != 2)
        err_quit("usage: a.out <IP address>");
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");

    // before connection
    mss = 0;
    len = sizeof(recv);
    getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &recv, &len);
    len = sizeof(mss);
    getsockopt(sockfd, IPPROTO_TCP, TCP_MAXSEG, &mss, &len);
    printf("recvbuf size = %d, MSS = %d\n", recv, mss);
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(13);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_sys("inect_pton error");
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
        err_sys("connect error");

    // after connection
    mss = 0;
    len = sizeof(recv);
    getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &recv, &len);
    len = sizeof(mss);
    getsockopt(sockfd, IPPROTO_TCP, TCP_MAXSEG, &mss, &len);
    printf("recvbuf size = %d, MSS = %d\n", recv, mss);


    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF)    
            err_sys("fputs error");
    }

    if (n < 0)
        err_sys("read error");

    exit(0);
}
