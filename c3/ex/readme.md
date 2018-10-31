# 1.3

some tests

``` sh
[moonlight@ArchLinux ex]$ ./a.out 192.168.1.1
ip = 192.168.1.1, (inet_aton)binary ip = 16885952
[moonlight@ArchLinux ex]$ ./a.out 0x192.0x168.1.1
ip = 0x192.0x168.1.1, (inet_aton)binary ip = 0
[moonlight@ArchLinux ex]$ ./a.out 0x192.168.1.1
ip = 0x192.168.1.1, (inet_aton)binary ip = 0
[moonlight@ArchLinux ex]$ ./a.out 0xc0.168.1.1
ip = 0xc0.168.1.1, (inet_aton)binary ip = 16885952
[moonlight@ArchLinux ex]$ ./a.out 0xc0.0xA8.1.1
ip = 0xc0.0xA8.1.1, (inet_aton)binary ip = 16885952
[moonlight@ArchLinux ex]$ ./a.out 0xc0.0250.1.1
ip = 0xc0.0250.1.1, (inet_aton)binary ip = 16885952
[moonlight@ArchLinux ex]$ 
```



under this problem, I got this error: `inet_aton` don't support IPv6 conversion.

`3.3.c`
``` sh
[moonlight@ArchLinux ex]$ ./a.out ::FFFF:192.168.1.1
ip = ::FFFF:192.168.1.1, inet_pton get (140733777209892)
inet_aton v6 error
[moonlight@ArchLinux ex]$
[moonlight@ArchLinux ex]$ ./a.out ::FFFF:192.168.1.1
ip = ::FFFF:192.168.1.1, inet_pton get (140733777209892)
inet_aton v6 error
[moonlight@ArchLinux ex]$
```
