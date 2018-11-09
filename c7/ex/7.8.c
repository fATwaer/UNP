#include "unp.h"
#include <netinet/tcp.h>

#define LEN1 4
#define LEN2 396
#define LEN3 4

int
main(int argc, char *argv[])
{
    int     sockfd, flag;
    struct sockaddr_in servaddr;
    char buf[BUFSIZ];
    char str1[LEN1], str2[LEN2], str3[LEN3];

    if (argc != 2)
        err_quit("usage: tcpcli <IP>");

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    flag = 0;
    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag));
    Connect(sockfd, (SA *)&servaddr, sizeof(servaddr));


    memset(str1, 65, LEN1);
    memset(str2, 66, LEN2);
    memset(str3, 67, LEN3);

    write(sockfd, str1, LEN1);
    write(sockfd, str2, LEN2);
    write(sockfd, str3, LEN3);
    pause();
    exit(0);
}

