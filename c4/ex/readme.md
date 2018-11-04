# 4.1


``` c
/* Defines for Multicast INADDR.  */
#define INADDR_UNSPEC_GROUP	((in_addr_t) 0xe0000000) /* 224.0.0.0 */
#define INADDR_ALLHOSTS_GROUP	((in_addr_t) 0xe0000001) /* 224.0.0.1 */
#define INADDR_ALLRTRS_GROUP    ((in_addr_t) 0xe0000002) /* 224.0.0.2 */
#define INADDR_MAX_LOCAL_GROUP  ((in_addr_t) 0xe00000ff) /* 224.0.0.255 */
```


# 4.2

I upload the server program to my remote pc. 
``` C
[moonlight@ArchLinux ex]$ ./a.out 111.231.57.172
self ip = 172.27.9.128, port = 35996
Thu Nov  1 14:05:44 2018
```

# 4.5

if don't bind, it will get a temporary port.
```
[moonlight@ArchLinux ex]$ ./a.out
self ip = 0.0.0.0, port = 44255
```

