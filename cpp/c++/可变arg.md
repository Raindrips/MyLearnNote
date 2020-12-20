# 可变参数

## 认识可变参
我们在使用printf scanf 这些格式输出语句的时候,是不是很好奇他们是怎么实现的,其实他们就用到了可变参数

比如printf的原型是
> `printf(const char* format,...);`

scanf的原型是
> `scanf(const char* format,...);`

C语言中,我们可以用可变参数来实现一些比较复杂的参数传递应对多种形式的功能
例如:

+ 控制台的输入		`printf	`	
+ 控制台的输出		`scanf`
-----------------------------

+ 文件的输出		`fprintf`	
+ 文件的输入		`fscanf`
-----------------------------
+ 字符串的输入		`sprintf`
+ 字符串的输出 		`sscanf`


## 可变参数的定义

*可变参数的定义步骤*

1. 声明一个函数
2. 声明一个参数,可变参的至少要有一个实际的参数
3. 第二个参数用 三个点号 （...） `...`
4. 需要导入一个头文件  `#include<stdarg.h>`

*例:*
```c
int func(int, ... ) 
{
   .
   .
   .
}
 
int main()
{
   func(2, 2, 3);
   func(3, 2, 3, 4);
}
```

## 可变参数的实现


- 在函数定义中 `va_list` 类型变量
- 使用 `int` 参数和 `va_start` 宏来初始化 `va_list` 变量为一个参数列表。
- 使用 va_arg 宏和 va_list 变量来访问参数列表中的每个项。
- 使用宏 va_end 来清理赋予 va_list 变量的内存。

> va_list vl;   //创建一个vl的变量

> va_start(vl,"变量名");		//变量名是...冒号前的参数

> 类型名 变量 = va_arg(vl,类型名)		//要返回的类型名称

> 清理内存 va_end(vl);

**代码示例**
```cpp

int sum(int num, ...)
{

  va_list vl;
  int sum = 0;
  int i;

  /* 为 num 个参数初始化 vl */
  va_start(vl, num);

  /* 访问所有赋给 vl 的参数 */
  for (i = 0; i < num; i++)
  {
	sum += va_arg(vl, int);
  }
  /* 清理为 vl 保留的内存 */
  va_end(vl);

  return sum;
}

int main()
{
  printf("%d\n", sum(4, 2, 3, 4, 5));
  printf("%d\n", sum(3, 5, 10, 15));
}

```

## 模板可变参数

使用模板识别可变参数

```cpp
template <typename T,class ...args>
void fn(T &t,args...a);
```



示例

```cpp
template <typename T>
void print(const T& t)
{
	std::cout << t<<endl;
}

template <typename T,class ...args>
void print(const T& t,const args&... a)
{
	std::cout << t;
	print(a...);
}
```

