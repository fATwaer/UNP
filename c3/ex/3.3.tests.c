#include "unp.h"

#define BFSZ 4096

int 
main(int argc, char *argv[])
{
    char buf[BFSZ];
    struct sockaddr_in addr;

    if (argc != 2)
        err_quit("usage: <a.out ip>");
    if (inet_aton(argv[1], &addr.sin_addr) == INADDR_NONE)
        err_sys("inet_aton error");

    printf("ip = %s, (inet_aton)binary ip = %lu\n", 
            argv[1], addr.sin_addr.s_addr);
}
