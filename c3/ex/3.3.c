#include "unp.h"

#define BFSZ 4096

int 
inet_pton_loose(int family, const char *str, void* addr)
{
    int r;

    if (family == AF_INET) {
        if (inet_pton(AF_INET, str, addr) != 1)
            err_quit("inet_pton error");
        if (inet_aton(str, addr) != 1)
            err_quit("inet_aton error");
    } else {
        if (inet_pton(AF_INET6, str, addr) != 1)
            err_quit("inet_pton v6 error");
        printf("inet_pton get (%lu)\n", (struct in_addr *)addr);
        if (inet_aton(str, addr) != 1)
            err_quit("inet_aton v6 error");
    
    }
    return (0);
}  




int 
main(int argc, char *argv[])
{
    char buf[BFSZ];
    struct sockaddr_in addr;
    const char *ptr;

    if (argc != 2)
        err_quit("usage: <a.out ip>");
   
    printf("ip = %s, ", argv[1]);
    inet_pton_loose(AF_INET6, argv[1], &addr.sin_addr);
    
}
