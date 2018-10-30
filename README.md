# UNP
Unix Network Programming

    
## Install 

source code: <http://www.unpbook.com/src.html>

``` sh
$ tar -xzvf unpv13e.tar.gz
$ cd unpv13e 
$ ./configure
```

there are two files that need to modify.

`libfree/inet_ntop.c`:line 60
``` diff
- size_t size;
+ socklen_t size;
```

`lib/unp.h`:line 7
``` diff
- #include "../config.h"
+ #include "config.h"
```

``` sh
$ cd lib
$ make
$ cd libfree
$ make
$ cd libgai
$ make
$ cd ..
```
you will find `libunp.a` in the root directory, copy to /usr/lib

``` sh
$ sudo cp libunp.a /usr/lib
$ sudo cp libunp.a /usr/lib64
```

and copy head file.

``` sh
$ sudo cp lib/unp.h /usr/include
$ sudo cp config.h /usr/include
```
## compile
    
    gcc 1-5.c -lunp 

## running
the server on 206.168.112.96 is down, we can use the 1-9 instead.

```
[moonlight@ArchLinux c1]$ sudo ./1-9
[moonlight@ArchLinux c1]$ ./a.out 127.0.0.1
Tue Oct 30 19:07:25 2018
 
```






