#include "unp.h"
#include <time.h>


int
main(int argc, char **argv)
{
    int     listenfd, connfd;
    struct sockaddr_in servaddr;
    char    buff[MAXLINE];
    time_t  ticks;
    socklen_t len;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof((servaddr)));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13);

    //Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);
    len = sizeof(servaddr);
    if (getsockname(listenfd, (SA *)&servaddr, &len) < 0)
        err_quit("get name error");
    printf("self ip = %s, port = %d\n", 
           inet_ntop(AF_INET, &servaddr.sin_addr, buff, MAXLINE),
           ntohs(servaddr.sin_port));
        
    for (;;) {
        connfd = Accept(listenfd, (SA *)NULL, NULL);

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        printf("%s", buff);
        Write(connfd, buff, strlen(buff));

        close(connfd);
    }
}
