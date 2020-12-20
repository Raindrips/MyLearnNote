## 线程

```c++
#include <pthread.h>
编译和链接时要带上选项 -pthread

//新线程创建出来后的执行顺序不确定，由系统调度，但是只要主线程(main)结束 ，所有的其它线程都会自动结束
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
		thread  用于保存线程的ID
		attr    线程属性，一般用默认的，对用户透明。此处写NULL表示用默认属性
		start_routine  函数指针， 线程任务函数的起始地址
		arg     传递给线程任务函数的参数，可以是任意类型，如果不需要参数，写NULL即可。
		成功返回0
		失败返回一个错误码

//等待线程结束
int pthread_join(pthread_t void **retval);//int *arg, char *arg  void* *arg
	thread 新线程的ID
	retval 用于保存线程的返回值
	成功返回0
	失败返回一个错误码
	
//线程结束
void pthread_exit(void *retval);	
	retval:线程返回值
	
sudo apt-get install manpages-posix-dev

互斥锁
静态：
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

动态：
	int pthread_mutex_init(pthread_mutex_t *restrict mutex,const pthread_mutexattr_t *restrict attr);
	pthread_mutex_t *mutex = malloc(sizeof(*mutex));
	pthread_mutex_init(mutex,NULL);
		
//上锁			
int pthread_mutex_lock(pthread_mutex_t *mutex);

//解锁
int pthread_mutex_unlock(pthread_mutex_t *mutex);

//销毁
int pthread_mutex_destory(pthread_mutex_t mutex);

//尝试销毁
int pthread_mutex_trylock(pthread_mutex_t *mutex);


条件变量:
//有动态和静态两种方式，这里是静态初始化方式

//用于在条件pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
不满足时，进入休眠状态，让出CPU
int pthread_cond_wait(pthread_cond_t *restrict cond,pthread_mutex_t *restrict mutex);
	cond  条件变量的地址
	mutex 互斥锁的地址

/* 初始化一个条件变量 */
int pthread_cond_init (pthread_cond_t* cond, pthread_condattr_t *cond_attr);
 
/* 生产者通知等待在条件变量上的消费者 */
int pthread_cond_signal(pthread_cond_t *cond);

/* 销毁一个条件变量 */
int pthread_cond_destroy(pthread_cond_t* cond);
 
/* 生产者向消费者广播消息 */
int pthread_cond_broadcast(pthread_cond_t* cond);
```

