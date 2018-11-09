#include "unp.h"
#include <sys/socket.h>

int 
main(int argc, char **argv)
{
    int     sockfd;
    struct  sockaddr_in servaddr;
    socklen_t len;
    struct  linger lgopt;             //declare for SO_LINGER
    if (argc != 2)
        err_quit("usage: tcpcli <IP>");

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    
    //strcut linger
    lgopt.l_onoff = 1;
    lgopt.l_linger = 0;
    len = sizeof(lgopt);
    setsockopt(sockfd, SOL_SOCKET, SO_LINGER, &lgopt, len);

    Connect(sockfd, (SA *)&servaddr, sizeof(servaddr));

    str_cli(stdin, sockfd);

    exit(0);
}
