# IPC通信

## 进程

IPC是进程之间特定通讯机制的总称

+ 并发程序设计的两个问题:
+ 同步
+ 互斥
+ 临界资源
+ 临界区
+ 互斥管理的方法
+ 软件算法:Peterson,Dekker
+ 硬件

设s为一个记录型数据结构,一个分量为整形量value,另一个为信号量队列queue, P和V操作原语定义：

P(s):将信号量s减去l，若结果小于0，则调用P(s)的进程被置成等待信号量s的状态。

V(s)：将信号量s加1，若结果不大于0，则释放一个等待信号量s的进程。


```cpp
typedef struct semaphore {
	int value;                   //信号量值
	struct pcb *list;         //信号量队列指针

 }; void P(semaphore &s) {
	 s.value--;            
	if(s.value<0)         
           W(s.list);      
}                     
void V(semaphore &s) {
	s.value++;            
      if(s.value<=0)        
        R(s.list);        
}    
```

1. 若信号量s为正值，则该值等于在封锁进程之前对信号量s可施行的P操作数、亦等于s所代表的实际还可以使用的物理资源数
2. 若信号量s为负值，则其绝对值等于登记排列在该信号量s队列之中等待的进程个数、亦即恰好等于对信号量s实施P操作而被封锁起来并进入信号量s队列的进程数
3. 通常，P操作意味着请求一个资源，V操作意味着释放一个资源。在一定条件下，P操作代表挂起进程操作，而V操作代表唤醒被挂起进程的操作


## 一般信号量与临界区管理机制

1. 设置一个信号量(初始值一般为1);
2. 每个进程进入临界区之前先对该信号量P操作;
3. 进入临界区;
4. 离开临界区之后对该信号量进行V操作;

## 信号量接口

```cpp
#include <sys/sem.h>
int semctl(int sid,int sn,int c,union semun a);
int semget(key_t k,int n,int sf);
int semop(int s,struct sembuf *s,size _t n);
```
特点
对成组的通用信号量进行操作,而不是仅针对一个二进制信号量;
将单一信号量的操作使用视为成组信号量的特例;

### 信号量接口
创建一个新信号量或获取已有信号量键的标识符. int semget(key_t k,int n,int sf);
该函数成功执行返回具有sf访问权限的n数量的k键所对应的信号量标识符(整数);失败返回-1;
第一个参数k是一个整数值,即信号量键;
n即是需要的信号量数目;可以取1;
sf类似open函数的一组标志:
IPC_CREAT指出如果信号量键不存在,则创建一个新的信号量键;如果已经存在,该标志会被忽略;
IPC_CREAT|IPC_EXCL指出创建一个新的、唯一的信号量;

```cpp
int semop(int s,struct sembuf *sb,size _t n);
```
操作一个或一组信号;
第一个参数s即semget函数返回的信号量标识符;
*sb为指向sembuf结构体数组的指针;
最后参数n是指信号操作的数量,该值恒大于等于1;

定义(red hat 9中):
```cpp

struct sembuf{
unsigned short int sem_num; 
short int sem_op; 
short int sem_flg;};
```
+ sem_num:将要处理的信号量编号,0代表第一个信号量,依次类推;
+ sem_op表示要改变的数值,它的含义如下:

| >0   | 信号量值增加sem_op;                                          |
| ---- | ------------------------------------------------------------ |
| =0   | 如果没有设置IPC_NOWAIT,则等待信号量值为0;如果设有IPC_NOWAIT则立即返回; |
| <0   | 如果信号量值小于该sem_op绝对值,则等待;如果此时还设有IPC_NOWAIT,则立即返回错误;如果信号量值不小于该sem_op绝对值,则从信号量中减去sem_op的绝对值; |

sem_flg:通常设为SEM_UNDO,表示由操作系统跟踪当前进程对这个信号量的修改情况.



```cpp
int semctl(int sid,int sn,int c,union semun a);
```

设置控制信号队列的方式;
第一个参数sid即semget函数返回的信号量标识符;
sn:将要处理的信号量编号,0代表第一个信号量,依次类推;
c:表示将要采取的动作;
a:是联合体union semun类型.该类型一般使用系统提供的定义.如果没有,可以由程序员定义;

有的系统提供了它的声明与定义;
有的系统没有提供的它的声明与定义,需要程序员自己声明定义该结构;

SETVAL:把sn指定的信号量的初始值设为a.val;
IPC_RMID:删除一个无须使用的信号量标识符;

union semun 的声明

```cpp
#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
    /* union semun is defined by including <sys/sem.h> */
#else
    /* according to X/OPEN we have to define it ourselves */
    union semun {
        int val;                    /* value for SETVAL */
        struct semid_ds *buf;  /* buffer for IPC_STAT, IPC_SET */
        unsigned short int *array;  /* array for GETALL, SETALL */
        struct seminfo *__buf;      /* buffer for IPC_INFO */
    };
#endif


```

### 信号量的使用

```cpp
static int semaphore_v(void)
{
    struct sembuf sem_b;
     
    sem_b.sem_num = 0;
    sem_b.sem_op = 1; /* V() */
    sem_b.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_b, 1) == -1) {
        fprintf(stderr, "semaphore_v failed\n");
        return(0);
    }
    return(1);
}

```



## 进程通信概述

+ 进程是相互独立的，进程间的通信需要专门的机制。
  进程之间的通信可以经由文件系统，但实际使用较为复杂（例如，需要锁机制）。
+ **UNIX IPC (InterProcess Communication)**机制是各种进程通信方式的统称。
+ **Linux**下的进程通信手段基本上是从Unix平台上的进程通信手段继承而来的。

## 

