# 时间函数

## C语言时间函数

#include <time>

### 时间

```c
//返回时间的函数
time_t time(time_t* t);

//计算时间差
time_t difftime(time_t end,time_t begin);

//原型
typedef __int64 time_t;
```

### 计时器

```c++
//计数从程序启动开始的时间,返回值单位是(毫秒)ms
clock_t clock();

//原型
typedef long time_t;
```

## 日期

```c
struct tm{
	int tm_sec;     /* 秒 - [0,59] */
    int tm_min;     /* 分  - [0,59] */
    int tm_hour;    /* 时 - [0,23] */
    int tm_mday;    /* 日期 - [1,31] */
    int tm_mon;     /* 月份 - [0,11] */
    int tm_year;    /* 年份 从 1900 */
    int tm_wday;    /* 星期 - [0,6] */
    int tm_yday;    /* 一年的第几天 - [0,365] */
    int tm_isdst;   /* daylight savings time flag */
}
```

```c
//时间格式类型转换  会被安全检查阻止使用
//这个函数或者变量可能是不安全的. 建议使用 localtime_s 替代掉
tm* localtime(time_t *time);

//更安全的一种写法
erron_t localtime_s(tm* _tm, time_t *time);
```



## C++时间函数

## 头文件

```c++
#include <chrono>
```

表示系统时间的一个类

```c++
class system_clock{
	operator<<();  //进行输出
        
}
```





//获取时间,参数或返回值均是获取时间
time_t time(time_t* t);

//获取时间差
difftime(time_t t1, time_t t2);



//转化为结构体
struct tm *gettime(const time_t *timeval);

struct tm{
	tm_sec			//秒0~61
	tm_min			//分0~59
	tm_hour			//小时0~23
	tm_mday			//日期1~31
	tm_mon			//月份0~11
	tm_year			//年份从1900开始计算	
	tm_wday			//星期几0~6
	tm_yday			//年份中的日期0~265	
	tm_isdst
}