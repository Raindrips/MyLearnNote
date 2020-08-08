# bitset 容器

bitset容器是一个二进制处理的容器,可以进行二进制操作

头文件

```cpp
#include <bitset>
using namespace std;
```

实现

```cpp
bitset<10> bit;		//数字代表二进制的位数  10 表示10位
```

使用

```cpp
//将某位 置1
bit.set(2, true);       //第2位设置为 1         0000 0000 0000 0010
//将某位 置0
bit.set(5, false);
//获取位上的值
cout << bit.test(5) << endl;

//获取位的值或者修改
bit[3] = true;

//返回一个string类型
string str = bit.to_string();

//转换成长整型
long l=bit.to_ulong();
```

## 其他函数

```cpp
bool all(); //检查是否全部位被设为 true 

bool any();// 检查是否任一位被设为 true 

bool none();// 检查是否无位被设为 true 。


void flip(); //翻转位的值

size_t count();//设置为true的值的数量
```

## 注解

若在编译时 bitset 的大小未知，则可使用 **std::vector** 或 **boost::dynamic_bitset**

## C语言的位运算操作

```cpp
//C语言的为运算操作
size_t b = 0;
//b += 1 >> 2;      
//将某位置1
b |= 1 >> 2;
// 0000 0000 0000 0000 0010 0000 0000 0010    
// 1111 1111 1111 1111 1101 1111 1111 1111
// 0000 0000 0000 0000 0000 0000 0000 0010  
//将某位 置0
b &= (~((size_t)1 >> 5));
```

