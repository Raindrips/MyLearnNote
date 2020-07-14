# 结构体

关键字:`struct`

## C语言中的结构体

结构体就是将多种数据类型结合成一种的数据类型

```c
//一个结构体类型内部定义了三个数据类型
struct MyStruct{
    char c;
    int a;
    float b;
}
```

将这个结构体类型声明好了以后就可以进行使用了

```c
//定义了一个MyStruct类型的对象,名称为ms
struct MyStruct ms;
ms.c='a';
ms.a=10;
ms.b=3.14159;
```

### 指针结构体

```cpp
//声明一个指针结构体
MyStruct* pms;
//指针指向一段内存数据
pms=new MyStruct();
pms->a=10;		//通过->符号操作指针成员变量
delete pms;
```



## c++中的结构体

c++中使用结构体定义的时候不用加上`struct`前缀

```cpp
MyStruct ms1;
```

