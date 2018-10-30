## 1.2

``` sh
[moonlight@ArchLinux c1]$ ./a.out 200.200.200.200
^C
[moonlight@ArchLinux c1]$
```

if the host is down, the program will be blocked by the read(), else:

``` sh
[moonlight@ArchLinux c1]$ ./a.out 127.0.0.1
Tue Oct 30 19:07:25 2018
```

## 1.3

``` sh
[moonlight@ArchLinux ex]$ ./a.out 127.0.0.1
socket error: Address family not supported by protocol
```

errno = 97

``` sh
[moonlight@ArchLinux ex]$ grep /usr/include "supported by protocol"
grep: supported by protocol: No such file or directory
[moonlight@ArchLinux ex]$ grep "supported by protocol" -r /usr/include 
/usr/include/glusterfs/compat-errno.h:#define GF_ERROR_CODE_AFNOSUPPORT    97      /* Address family not supported by protocol */
/usr/include/apr-1/apr_errno.h:#define SOCEAFNOSUPPORT         (SOCBASEERR+47)            /* Address family not supported by protocol family */
/usr/include/asm-generic/errno.h:#define	EAFNOSUPPORT	97	/* Address family not supported by protocol */
```

``` sh
man 3 socket
```

> ERRORS
       The socket() function shall fail if:

       EAFNOSUPPORT
              The implementation does not support the specified address family.

       EMFILE All file descriptors available to the process are currently open.

       ENFILE No more file descriptors are available for the system.

       `EPROTONOSUPPORT`
              The protocol is not supported by the address family, or the protocol is not supported by the implementation.

       EPROTOTYPE
              The socket type is not supported by the protocol.

       The socket() function may fail if:

       EACCES The process does not have appropriate privileges.

       ENOBUFS
              Insufficient resources were available in the system to perform the operation.

       ENOMEM Insufficient memory was available to fulfill the request.

       The following sections are informative.


## 1-4

``` sh
[moonlight@ArchLinux ex]$ ./a.out 127.0.0.1
Tue Oct 30 19:39:38 2018
count = 1
```


## 1-5

``` C
servaddr.sin_port = htons(9999);

Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

Listen(listenfd, LISTENQ);

for (;;) {
    connfd = Accept(listenfd, (SA *)NULL, NULL);

    while (1) {
        memset(buff, 0, sizeof(buff));
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));
        sleep(1);
    }

    close(connfd);
}   
```


It works! 
``` sh
[moonlight@ArchLinux ex]$ ./1.5c 127.0.0.1
Tue Oct 30 20:59:08 2018
Tue Oct 30 20:59:09 2018
Tue Oct 30 20:59:10 2018
Tue Oct 30 20:59:11 2018
Tue Oct 30 20:59:12 2018
Tue Oct 30 20:59:14 2018
Tue Oct 30 20:59:14 2018
Tue Oct 30 20:59:16 2018
^C
[moonlight@ArchLinux ex]$ ps
  PID TTY          TIME CMD
 1934 pts/0    00:00:00 bash
11546 pts/0    00:00:00 ps
[1]+  Broken pipe             ./1.5s
[moonlight@ArchLinux ex]$ 
```

Broken pipe
