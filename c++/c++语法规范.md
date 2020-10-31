# C++规范

1. 命名规范
1. 设计规范

## 设计类

+ 模板类可以全部写在头文件中,然后用`.hpp`命名
+ 普通的类应该头文件和源文件分离编译
+ 引用或者指针数据,如果是只读的,那么应该加上`const`

```cpp
//类的名称要大写
class MyClass{
public:
    MyClass();		//构造申请了堆内存,一定要放在析构中进行消耗
    
    ~MyClass();		//析构函数消耗内存一定要判断是否为空,delete掉之后要置空
    
    MyClass(const MyClass& cla);		//拷贝构造实现内存的复制  深拷贝
    
    //如果需要深拷贝,建议将=符号重载一并完成
    MyClass& operator=(const MyClass& cla);
    // 三之法则
    //构造申请内存-析构消耗内存-拷贝复制内存
       
    setA(int a);		//需要进行封装的类用set和get进行
    int getA() const;	//如果只进行类的数据读取,不修改类的变量的话就应该使用const 
    
private:
    int a;
};
```

## 设计接口

实现一个虚基类应该做的

+ 不能有变量
+ 每个函数应该有`virtual`修饰符
+ 不需要构造函数

```cpp
//虚基类
class Base{
public:
    //纯虚函数
    virtual void fn()=0;			
    
    //默认虚函数,表示子类可以不重写这个函数,这个函数没有任何功能 c++11
    virtual void fn1()=default;		
    
    //给虚函数一个默认行为,子类可以不用重写,并且可以直接调用这个默认函数
    virtual void fn2(){/*do something*/}
    
    //析构函数应声明默认
    virtual ~Base()=default;
}
```

如果设计的类,没有达到上述条,那么其就不是虚基类,应该作为一个普通类使用,普通的类不应该被多继承

+ 普通的类应该只能继承一个
+ 虚基类可以继承多个

```cpp
//继承虚基类
class Item:public Base{
    //重写父类方法时应该加上override,然编辑器进行检查
    virtual void fn() override;
}
```



## 数据传输

结构体进行数据传输,应遵循下列规范

+ 字节要对齐
+ 结构体内应该是没有指针的(指针只进行地址的存储,不进行数据存储)
+ 应该是C语言的语法风格

```c
#pragma pack(1)

typedef struct data{
    int id,
    char name[20];
}data_t;

#pragma pack()
```

