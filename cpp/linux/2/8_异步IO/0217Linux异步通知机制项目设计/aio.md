# Linux中AIO设计框架
## 概述

> aio异步读写是在Linux内核2.6之后才正式纳入其标准。之所以会增加此模块，是因为众所周知我们计算机CPU的执行速度远大于I/O读写的执行速度，如果我们用传统的阻塞式或非阻塞式来操作I/O的话，那么我们在同一个程序中(不用多线程或多进程)就不能同时操作俩个以上的文件I/O，每次只能对一个文件进行I/O操作，很明显这样效率很低下(因为CPU速度远大于I/O操作的速度，所以当执行I/O时，CPU其实还可以做更多的事)。因此就诞生了相对高效的异步I/O
>  --------------------------------------



## 类比阻塞IO机制

### 同步阻塞IO模型
* 同步阻塞 I/O 模型。在这个模型中，用户空间的应用程序执行一个系统调用，这会导致应用程序阻塞。这意味着应用程序会一直阻塞，直到系统调用完成为止（数据传输完成或发生错误）。调用应用程序处于一种不再消费 CPU 而只是简单等待响应的状态，因此从处理的角度来看，这是非常有效的。
![同步阻塞 I/O 模型的典型流程](https://www.ibm.com/developerworks/cn/linux/l-async/figure2.gif)

-----------------------------------------
### 同步非阻塞 I/O
* 步阻塞 I/O 的一种效率稍低的变种是同步非阻塞 I/O。在这种模型中，设备是以非阻塞的形式打开的。这意味着 I/O 操作不会立即完成，read操作可能会返回一个错误代码，说明这个命令不能立即满足（EAGAIN 或 EWOULDBLOCK），如图 3 所示。
![同步非阻塞 I/O 模型的典型流程](https://www.ibm.com/developerworks/cn/linux/l-async/figure3.gif)

---------------------------------------
### 异步阻塞 I/O
* IO多路复用(复用的select线程)。I/O复用模型会用到select、poll、epoll函数，这几个函数也会使进程阻塞，但是和阻塞I/O所不同的的，这两个函数可以同时阻塞多个I/O操作。而且可以同时对多个读操作，多个写操作的I/O函数进行检测，直到有数据可读或可写时，才真正调用I/O操作函数。对于每个提示符来说，我们可以获取这个描述符可以写数据、有读数据可用以及是否发生错误的通知。

![异步阻塞 I/O 模型的典型流程](https://www.ibm.com/developerworks/cn/linux/l-async/figure4.gif)

* epoll支持水平触发和边缘触发，最大的特点在于边缘触发，它只告诉进程哪些fd刚刚变为就需态，并且只会通知一次。还有一个特点是，epoll使用“事件”的就绪通知方式，通过epoll_ctl注册fd，一旦该fd就绪，内核就会采用类似callback的回调机制来激活该fd，epoll_wait便可以收到通知.

#### epoll的优点
*  没有最大并发连接的限制，能打开的FD的上限远大于1024（1G的内存上能监听约10万个端口）。
*  效率提升，不是轮询的方式,只管你“活跃”的连接，不会随着FD数目的增加效率下降。只有活跃可用的FD才会调用callback函数。
*  内存拷贝，利用mmap()文件映射内存加速与内核空间的消息传递；即epoll使用mmap减少复制开销。

##### Tips

> * 表面上看epoll的性能最好，但是在连接数少并且连接都十分活跃的情况下，select和poll的性能可能比epoll好，毕竟epoll的通知机制需要很多函数回调。

-------------------------------------

### 异步非阻塞 I/O
* 异步非阻塞 I/O 模型是一种CPU处理与 I/O 重叠进行的模型。读请求会立即返回，说明 read 请求已经成功发起了。在后台完成读操作时，应用程序然后会执行其他处理操作。当 read 的响应到达时，就会产生一个信号或执行一个基于线程的回调函数来完成这次 I/O 处理过程。


![异步非阻塞 I/O 模型流程](https://www.ibm.com/developerworks/cn/linux/l-async/figure5.gif)

---------------------------

## AIO编程方法

> AIO 接口的 API 非常简单，但是它为数据传输提供了必需的功能，并给出了两个不同的通知模型。表 1 给出了 AIO 的接口函数，本节稍后会更详细进行介绍。

![AIO基本API介绍](https://i.imgur.com/irAcWoN.png)


### 对象 
* struct aiocb
```
struct aiocb
{
  int aio_fildes;               // File Descriptor
  int aio_lio_opcode;           // Valid only for lio_listio(r/w/nop) 
  volatile void *aio_buf;       // Data Buffer
  size_t aio_nbytes;            // Number of Bytes in Data Buffer
  struct sigevent aio_sigevent; // Notification Structure
  /* Internal fields */
  ...
};
AIO_READ AIO_WRITE 
```
------------------------
### aio_read 

* aio_read 函数请求对一个有效的文件描述符进行异步读操作。这个文件描述符可以表示一个文件、套接字甚至管道。aio_read 函数的原型如下

```
int aio_read(struct aiocb *aiocbp);
```

* aio_read 函数在请求进行排队之后会立即返回。如果执行成功，返回值就为 0；如果出现错误，返回值就为 -1，并设置 errno 的值。

### aio_error

* aio_error 函数被用来确定请求的状态。

```
int aio_error( struct aiocb *aiocbp );
```

* 返回值
>  EINPROGRESS，说明请求尚未完成
   ECANCELLED，说明请求被应用程序取消了
   -1，说明发生了错误，具体错误原因可以查阅 errno
	0 ,说明完成当前请求

### aio_return
* 异步 I/O 和标准块 I/O 之间的另外一个区别是我们不能立即访问这个函数的返回状态，因为我们并没有阻塞在 read 调用上。在标准的 read 调用中，返回状态是在该函数返回时提供的。但是在异步 I/O 中，我们要使用 aio_return 函数。这个函数的原型如下：

```
ssize_t aio_return( struct aiocb *aiocbp );
```

* demo

```
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<aio.h>


#define BUFFER_SIZE 1024

int MAX_LIST = 2;

int main(int argc,char **argv)
{
    //aio操作所需结构体
    struct aiocb rd;

    int fd,ret,couter;

    fd = open("test.txt",O_RDONLY);
    if(fd < 0)
    {
        perror("test.txt");
    }



    //将rd结构体清空
    bzero(&rd,sizeof(rd));


    //为rd.aio_buf分配空间
    rd.aio_buf = malloc(BUFFER_SIZE + 1);

    //填充rd结构体
    rd.aio_fildes = fd;
    rd.aio_nbytes = BUFFER_SIZE;
    rd.aio_offset = 0;

    //进行异步读操作
    ret = aio_read(&rd);
    if(ret < 0)
    {
        perror("aio_read");
        exit(1);
    }
	//do other things
	
    couter = 0;
//  循环等待异步读操作结束
    while(aio_error(&rd) == EINPROGRESS)
    {
       // printf("第%d次\n",++couter);
    }
	
    //获取异步读返回值
    ret = aio_return(&rd);
	
    printf("\n\n返回值为:%d\n",ret);
	printf("%s\n",rd.aio_buf);
	
	free(rd.aio_buf);
	close(fd);
    return 0;
}
```



### aio_write

* aio_write 函数用来请求一个异步写操作。其函数原型如下：

```
int aio_write( struct aiocb *aiocbp );
```
* aio_write 函数会立即返回，说明请求已经进行排队（成功时返回值为 0，失败时返回值为 -1，并相应地设置 errno）。

* 这与 read 系统调用类似，但是有一点不一样的行为需要注意。回想一下对于 read 调用来说，要使用的偏移量是非常重要的。然而，对于 write 来说，这个偏移量只有在没有设置 O_APPEND 选项的文件上下文中才会非常重要。如果设置了 O_APPEND，那么这个偏移量就会被忽略，数据都会被附加到文件的末尾。否则，aio_offset 域就确定了数据在要写入的文件中的偏移量。

#### demo 
```
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<aio.h>

#define BUFFER_SIZE 1024

int main(int argc,char **argv)
{
    //定义aio控制块结构体
    struct aiocb wr;

    int ret,fd;

    char str[20] = {"hello,world"};

    //置零wr结构体
    bzero(&wr,sizeof(wr));

    fd = open("test.txt",O_WRONLY | O_APPEND);
    if(fd < 0)
    {
        perror("test.txt");
    }

    //为aio.buf申请空间
    wr.aio_buf = (char *)malloc(BUFFER_SIZE);
    if(wr.aio_buf == NULL)
    {
        perror("buf");
    }

    wr.aio_buf = str;

    //填充aiocb结构
    wr.aio_fildes = fd;
    wr.aio_nbytes = 1024;

    //异步写操作
    ret = aio_write(&wr);
    if(ret < 0)
    {
        perror("aio_write");
    }

    //等待异步写完成
    while(aio_error(&wr) == EINPROGRESS)
    {
        printf("hello,world\n");
    }

    //获得异步写的返回值
    ret = aio_return(&wr);
    printf("\n\n\n返回值为:%d\n",ret);

    return 0;
}
```



### aio_suspend

* aio_suspend函数可以时当前进程挂起，直到有向其注册的异步事件完成为止 
* 阻塞
* 当有AIO请求返程后，该函数返回


```
int aio_suspend(const struct aiocb *const cblist[],int n,const struct timespec *timeout);
```
* > 第一个参数是个保存了aiocb块地址的数组，我们可以向其内添加想要等待阻塞的异步事件，第二个参数为向cblist注册的aiocb个数,第三个参数为等待阻塞的超时时间，NULL为无限等待


#### demo
```
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<aio.h>


#define BUFFER_SIZE 1024

int MAX_LIST = 2;

int main(int argc,char **argv)
{
    //aio操作所需结构体
    struct aiocb rd;
	struct aiocb wd;
    int fd,ret,couter;

    //cblist链表
    struct aiocb *aiocb_list[2];



    fd = open("test.txt",O_RDONLY);
    if(fd < 0)
    {
        perror("test.txt");
    }



    //将rd结构体清空
    bzero(&rd,sizeof(rd));


    //为rd.aio_buf分配空间
    rd.aio_buf = malloc(BUFFER_SIZE + 1);

    //填充rd结构体
    rd.aio_fildes = fd;
    rd.aio_nbytes =  BUFFER_SIZE;
    rd.aio_offset = 0;

    //将读fd的事件注册
    aiocb_list[0] = &rd;

    //进行异步读操作
    ret = aio_read(&rd);
    if(ret < 0)
    {
        perror("aio_read");
        exit(1);
    }

    printf("我要开始等待异步读事件完成\n");
    //阻塞等待异步读事件完成
    ret = aio_suspend(aiocb_list,MAX_LIST,NULL);
	
	
    //获取异步读返回值
    ret = aio_return(&rd);

    printf("\n\n返回值为:%d\n",ret);


    return 0;
}

```
---------------------------

### lio_listio

> aio同时还为我们提供了一个可以发起多个或多种I/O请求的接口lio_listio 
这个函数效率很高，因为我们只需一次系统调用(一次内核上下位切换)就可以完成大量的I/O操作 

```
int lio_listio(int mode,struct aiocb *list[],int nent,struct sigevent *sig);

```

> 第一个参数mode可以有俩个实参，LIO_WAIT和LIO_NOWAIT，前一个会阻塞该调用直到所有I/O都完成为止，后一个则会挂入队列就返回

* LIO_WAIT 阻塞发起
* LIO_NOWAIT  非阻塞发起

> 批量发起AIO的两种方法
* 阻塞等到所有发起的AIO全部完成后，才会返回
* 发起后立即返回，通过绑定的信号来通知

#### LIO_WAIT demo

```
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<aio.h>

#define BUFFER_SIZE 1025

int MAX_LIST = 2;


int main(int argc,char **argv)
{
    struct aiocb *listio[2];
    struct aiocb rd,wr;
    int fd,ret;

    //异步读事件
    fd = open("test1.txt",O_RDONLY);
    if(fd < 0)
    {
        perror("test1.txt");
    }

    bzero(&rd,sizeof(rd));

    rd.aio_buf = (char *)malloc(BUFFER_SIZE);
    if(rd.aio_buf == NULL)
    {
        perror("aio_buf");
    }

    rd.aio_fildes = fd;
    rd.aio_nbytes = 1024;
    rd.aio_offset = 0;
    rd.aio_lio_opcode = LIO_READ;   ///lio操作类型为异步读

    //将异步读事件添加到list中
    listio[0] = &rd;


    //异步些事件
    fd = open("test2.txt",O_WRONLY | O_APPEND);
    if(fd < 0)
    {
        perror("test2.txt");
    }

    bzero(&wr,sizeof(wr));

    wr.aio_buf = (char *)malloc(BUFFER_SIZE);
    if(wr.aio_buf == NULL)
    {
        perror("aio_buf");
    }

    wr.aio_fildes = fd;
    wr.aio_nbytes = 1024;

    wr.aio_lio_opcode = LIO_WRITE;   ///lio操作类型为异步写

    //将异步写事件添加到list中
    listio[1] = &wr;

    //使用lio_listio发起一系列请求
    ret = lio_listio(LIO_WAIT,listio,MAX_LIST,NULL);

    //当异步读写都完成时获取他们的返回值

    ret = aio_return(&rd);
    printf("\n读返回值:%d",ret);

    ret = aio_return(&wr);
    printf("\n写返回值:%d",ret);



    return 0;
}


```


#### LIO_NOWAIT demo
> 当我们的异步I/O操作完成之时，我们可以通过信号通知我们的进程也可用回调函数来进行异步通知，接下来我会为大家主要介绍以下回调函数来进行异步通知


```
struct sigevent {
    int           sigev_notify;            //Notification type. 
    int           sigev_signo;            //Signal number. 
    union sigval  sigev_value;             //Signal value. 
    void         (*sigev_notify_function)(union sigval); //Notification function. 
    pthread_attr_t *sigev_notify_attributes;  //Notification attributes. 
}; 

```

```
union sigval
{
    int sival_int;
    void *sival_ptr;
};  
```

```

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<aio.h>
#include<unistd.h>

#define BUFFER_SIZE 1025


void aio_completion_handler(sigval_t sigval)
{
    //用来获取读aiocb结构的指针
    struct aiocb *prd;
    int ret;

    prd = (struct aiocb *)sigval.sival_ptr;

    printf("hello\n");

    //获取返回值
    ret = aio_return(prd);

}

int main(int argc,char **argv)
{
    int fd,ret;
    struct aiocb rd;

    fd = open("test.txt",O_RDONLY);
    if(fd < 0)
    {
        perror("test.txt");
    }



    //填充aiocb的基本内容
    bzero(&rd,sizeof(rd));

    rd.aio_fildes = fd;
    rd.aio_buf = (char *)malloc(sizeof(BUFFER_SIZE + 1));
    rd.aio_nbytes = BUFFER_SIZE;
    rd.aio_offset = 0;

    //填充aiocb中有关回调通知的结构体sigevent
    rd.aio_sigevent.sigev_notify = SIGEV_THREAD;//使用线程回调通知
    rd.aio_sigevent.sigev_notify_function = aio_completion_handler;//设置回调函数
    rd.aio_sigevent.sigev_notify_attributes = NULL;//使用默认属性
    rd.aio_sigevent.sigev_value.sival_ptr = &rd;//在aiocb控制块中加入自己的引用

    //异步读取文件
    ret = aio_read(&rd);
    if(ret < 0)
    {
        perror("aio_read");
    }

    printf("异步读以开始\n");
    sleep(1);
    printf("异步读结束\n");



    return 0;
}

```


```
gcc -g -o fast-cp fast-cp.c  -lrt -lpthread

dd if=/dev/zero of=test bs=1M count=1000

sem_init

sem_post

sem_wait




```

Fast-cp项目设计
0.记录当前系统时间
1.发起AIO的读
2.等到AIO读结束后会调用回调函数，发起AIO的写
3.等到AIO写结束后会调用回调函数，计算拷贝时间
4.拷贝完成，显示拷贝时间

sem_wait

sem_post





1.文件操作模块
	1.1 文件状态 
	1.2 文件属性
	1.3 文件类型 
	1.4 文件权限 

2.核心IO模块
3.辅助模块

struct stat {

        mode_t     st_mode;       //文件对应的模式，文件，目录等
    
        ino_t      st_ino;       //inode节点号
    
        dev_t      st_dev;        //设备号码
    
        dev_t      st_rdev;       //特殊设备号码
    
        nlink_t    st_nlink;      //文件的连接数
    
        uid_t      st_uid;        //文件所有者
    
        gid_t      st_gid;        //文件所有者对应的组
    
        off_t      st_size;       //普通文件，对应的文件字节数
    
        time_t     st_atime;      //文件最后被访问的时间
    
        time_t     st_mtime;      //文件内容最后被修改的时间
    
        time_t     st_ctime;      //文件状态改变时间
    
        blksize_t st_blksize;    //文件内容对应的块大小
    
        blkcnt_t   st_blocks;     //伟建内容对应的块数量
    
      };

S_IRUSR
  Permits the file's owner to read it.

S_IWUSR
  Permits the file's owner to write to it.

S_IRGRP
  Permits the file's group to read it.

S_IWGRP
  Permits the file's group to write to it.


#include <fcntl.h>
int posix_fadvise(int fd, off_t offset, off_t len, int advice);


#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>

int fallocate(int fd, int mode, off_t offset, off_t len);

```


```
#define S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)
#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)
#define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#define S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#define S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#define S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#define S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)

```

```
判断是否为统一文件
  if (stat_buf.st_dev  == stat_dst.st_dev && \
        stat_buf.st_ino == stat_dst.st_ino)
        return 0;
```

```
预分配内存
    // TODO tell the kernel that we will need the input file
    posix_fadvise(src_fd, 0, stat_buf.st_size, POSIX_FADV_WILLNEED);

    // more efficient space allocation via fallocate for dst file
    if (fallocate(dst_fd, 0, 0, stat_buf.st_size) == -1) 
        perror("destination file fallocate"
```


sem_t blocking_waiter;


sem_init(&blocking_waiter, 0, 0);
clock_gettime(CLOCK_MONOTONIC, &tv1);
sem_post  
sem_wait   
sem_destroy
clock_gettime(CLOCK_MONOTONIC, &tv2);
### 面向对象编程 


A
开AIO
aio
B



1.发起aio读
2.aio读的回调函数中会调aio_write
3.sem_post



opendir 
mkdir
目录拷贝
	1.获取目录list
	  struct dirent {
               ino_t          d_ino;       /* inode number */
               off_t          d_off;       /* not an offset; see NOTES */
               unsigned short d_reclen;    /* length of this record */
               unsigned char  d_type;      /* type of file; not supported
                                              by all filesystem types */
               char           d_name[256]; /* filename */
           };

```