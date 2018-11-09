#include "unp.h"

int
main(int argc, char *argv[])
{
    int     sockfd;
    struct sockaddr_in servaddr;
    int     n;
    char    buf[4096];

    if (argc != 2)
        err_quit("usage: tcpcli <IP>");

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(19);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Connect(sockfd, (SA *)&servaddr, sizeof(servaddr));
    
//    while ((n = read(sockfd, buf, BUFSIZ)) > 0)
//            printf("%s\n", buf);
    shutdown(sockfd, SHUT_RD);
    pause();

    exit(0);
}

