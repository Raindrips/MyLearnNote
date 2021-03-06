# Signal 异步通知方法

## 目标
* 如何发起异步操作(对本身发起、对其他进程发起)
* 如何安装信号
* 如何屏蔽及管理信号
* 如何利用信号进行阻塞操作

## 项目
* 信号驱动的服务器
* 电报机



### Linux中的信号

```sh
#发送信号
kill -9 pid 
```




```
#define SIGHUP		 1
#define SIGINT		 2
#define SIGQUIT		 3
#define SIGILL		 4
#define SIGTRAP		 5
#define SIGABRT		 6
#define SIGIOT		 6
#define SIGBUS		 7
#define SIGFPE		 8
#define SIGKILL		 9
#define SIGUSR1		10
#define SIGSEGV		11
#define SIGUSR2		12
#define SIGPIPE		13
#define SIGALRM		14
#define SIGTERM		15
#define SIGSTKFLT	16
#define SIGCHLD		17
#define SIGCONT		18
#define SIGSTOP		19
#define SIGTSTP		20
#define SIGTTIN		21
#define SIGTTOU		22
#define SIGURG		23
#define SIGXCPU		24
#define SIGXFSZ		25
#define SIGVTALRM	26
#define SIGPROF		27
#define SIGWINCH	28
#define SIGIO		29
#define SIGPOLL		SIGIO
/*
#define SIGLOST		29
*/
#define SIGPWR		30
#define SIGSYS		31
/* signal 31 is no longer "unused", but the SIGUNUSED macro remains for backwards compatibility */
#define	SIGUNUSED	31

/* These should not be considered constants from userland.  */
#define SIGRTMIN	32
#define SIGRTMAX	_NSIG
```



```c
signal(int signum,myfunc());
signal(SIGINT,myfunc);
```



SIGINT
### 信号的基本操作
* 发送信号
* 安装中断
* 递送信号
* 捕获信号
* 屏蔽信号


### 如何发起异步操作
> kill
 kill 命令  eg：kill -signum pid

```c
/*
 pid>0  发给pid进程 
 pid=0  发给当前进程组的所有进程
 pid=-1 发送给所有进程
 pid<0  发送给|PID|所对应的组上 c
*/
 int kill(pid,signum);
```



```c
//获取pid
pid=getpid();
gpid=getgpid();
```



```c
//自举信号，会给自己发送一个信号
int raise(int sig);
int kill(getpid(),signum);
```



```c
//定时函数
//函数会在所指定的seconds之后收到SIGALRM信号
unsigned int alarm(unsigned int seconds);
```

每格固定的时间发送信号

```c
//每格interval发送一次信号
unsigned int ualarm(size_t usize,size_t interval);
```



```c
void handler(int sig){
    
}
//消息接收,然后执行对应函数
signal(SIGALRM,handler);
```



```c
 //以useconds为单位，第一个参数为第一次产生时间，第二个参数为间隔产生c
 useconds_t ualarm(useconds_t usecs, useconds_t interval);
```



> 

```C

int getitimer(int which, struct itimerval *curr_value);
//setitimer 定时器
int setitimer(int which, const struct itimerval *new_value,
                     struct itimerval *old_value);
```

Linux会给进程提供三个定时器
ITIMER_REAL:以逝去时间递减
ITIMER_VIRTUAL：

```c
struct itimerval {
    struct timeval it_interval; /* next value */
    struct timeval it_value;    /* current value */
};

struct timeval{
    time_t      tv_sec;         /* seconds */
    suseconds_t tv_usec;        /* microseconds */
};
```

### 安装和捕获信号
* 忽略信号
* 自定义捕捉函数
* 系统默认信号函数

> signal
 signal(signum,handler)



```sh
kill -SIGUSR1 pid
```



SIGKILL SIGSTOP 不能够被安装

忽略信号
 signal(signum,SIG_IGN)

signal(SIGINT,SIG_IGN)
signal(SIGPIPE,SIG_IGN)



> sigaction对象

```c
int sigaction(int signum, const struct sigaction *act,
                     struct sigaction *oldact);

struct sigaction 
{
       void     (*sa_handler)(int);
       void     (*sa_sigaction)(int, siginfo_t *, void *);
       sigset_t   sa_mask;
       int        sa_flags;  //会影响信号接受特殊标志
       void     (*sa_restorer)(void);

};

sigset_t 信号集合 
SA_SIGINFO


siginfo_t {
   int      si_signo;    /* Signal number */
   int      si_errno;    /* An errno value */
   int      si_code;     /* Signal code */
   int      si_trapno;   /* Trap number that caused
                            hardware-generated signal
                            (unused on most architectures) */
   pid_t    si_pid;      /* Sending process ID */
   uid_t    si_uid;      /* Real user ID of sending process */
   int      si_status;   /* Exit value or signal */
   clock_t  si_utime;    /* User time consumed */
   clock_t  si_stime;    /* System time consumed */
   sigval_t si_value;    /* Signal value */
   int      si_int;      /* POSIX.1b signal */
   void    *si_ptr;      /* POSIX.1b signal */
   int      si_overrun;  /* Timer overrun count; POSIX.1b timers */
   int      si_timerid;  /* Timer ID; POSIX.1b timers */
   void    *si_addr;     /* Memory location which caused fault */
   long     si_band;     /* Band event (was int in
                            glibc 2.3.2 and earlier) */
   int      si_fd;       /* File descriptor */
   short    si_addr_lsb; /* Least significant bit of address
                            (since Linux 2.6.32) */
}

```

* 信号会唤醒当前进程的阻塞状态

sigval_tc

```c
union sigval {
    int sival_int;
    void *sival_ptr;
};
```



* sigqueue 
```c
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("arguments error!");
        exit(0);
    }

    pid_t pid=atoi(argv[1]);//将进程号转化为整数
    union sigval v;
    v.sival_int=100;
    //这儿只是利用SIGINT来发送数据，
    //任何信号都行，只需要发送端与接收端规定一致即可
    sigqueue(pid,SIGINT,v);
    return 0;
}
```

### 信号集合
* sigset_t   sa_mas



```c
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signum);
int sigdelset(sigset_t *set, int signum);
int sigismember(const sigset_t *set, int signum);
```



*设置信号屏蔽集合
 int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
SIG_BLOCK
SIG_UNBLOCK
SIG_SETMASK


### 未决信号
sigpending(sigset）

int block 
32bit 
00000000000000000000000000000100


### sigsuspend 函数 等待信号 
 int sigsuspend(const sigset_t *mask);


## 项目设计 一
* server 
a
96 
1100000
USER2
USER2
USER1
USER1
USER1
USER1
USER1

* client 
stdin： a
97
1100001
USER2
USER2
USER1
USER1
USER1
USER1
USER1



process 
{

 int sigmask ;



}

00000000000000000000010000000000000000000000000011

 sigset_t s
sigemptyset
sigaddset
sigprocmask
sigpending
sigismember


sigsuspend() 阻塞等待信号



a 
96
01100000
USER1 USER2 USER2 USER1 USER1 USER1 USER1 USER1





 clock_gettime(CLOCK_MONOTONIC, &tv1);

  clock_gettime(CLOCK_MONOTONIC, &tv2);

 uint64_t tv = (tv2.tv_sec - tv1.tv_sec) * 1000000000+ tv2.tv_nsec -tv1.tv_nsec;
  printf("completion time = %ld.%06ld s\n", tv / 1000000000, tv % 1000000000);



a ---->0x61---->1100001--->sigusr2 sigusr2 sigusr1 sigusr1 sigusr1 sigusr1 sigusr2 



1. 信号是可以打断阻塞的，
	```
		#include <error.h>
		 /*接收新的链接*/
		confd=accept(srvfd,(struct sockaddr*)(&tCliaddr),&tCliaddlen);
		if(confd == -1)
		{
			if(errno==EINTR)
			{
				goto ACCEPT;
			}
			else
			{
				fprintf(stderr,"accept error,error:%s\n",strerror(errno));
				return -1;
			}
		}

		a =malloc
	if a ==NULL
		ret =
		goto error-a
	if  b==NULL
		ret =
		goto error-b
	
		c = malloc
		pthread_mutex_lock(mutex)
		if  c==NULL
			ret =
			goto error-c
		d = malloc
		if d==NULL
			ret =
			goto error-d
		e = malloc
		if  e==NULL
			ret =
			goto error-e
		
		return ;
		
		error-e:
			free(d)	
		error-d:
			free(c)
		error-c:
			free(b)
			pthread_mutex_unlock(mutex)
		error-b:
			free(a)
		error-a:
			return ret;

	```
2. 信号函数不能做时间长的时，容易死锁的，线程不安全的操作 
3. 服务器要处理 SIGINT SIGCHLD SIGPIPE 


