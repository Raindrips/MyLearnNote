# 时间函数

## C语言时间函数

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
//计数从程序启动开始的时间,返回值是ms
clcok_t clock();

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
//时间格式类型转换
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



