# 时间函数

## C语言时间函数

#include <time.h>

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

计算程序执行的时间

```cpp
clock_t start = clock();        //毫秒级别的
cout << start << endl;
for (size_t i = 0; i < INT_MAX; i++);;
clock_t end = clock();
cout << "花费时间" << end - start << "ms" << endl;
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

使用格式转换函数

```c
//时间格式类型转换  会被安全检查阻止使用
//这个函数或者变量可能是不安全的. 建议使用 localtime_s 替代掉
struct tm* localtime(time_t *time);
//转化为结构体,不安全
struct tm *gettime(const time_t *timeval);

//更安全的一种写法
erron_t localtime_s(tm* _tm, time_t *time);
```

使用格式化输出

```cpp
tm date;        //日期结构体
time_t t = time(nullptr);
localtime_s(&date, &t);
cout << "当前时间:"
    << date.tm_year + 1900 << "年"
    << date.tm_mon + 1 << "月"
    << date.tm_mday << "日"
    << date.tm_hour << "时"
    << date.tm_min << "分"
    << date.tm_sec << "秒"
    << endl;
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





