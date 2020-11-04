

# C#基础

## 值类型

```c#
int i = 0;
System.Int32 i2 = 0;
```

## 枚举类型

`enum`关键字声明枚举类型

```c#
enum Day{Sunday,Firday,};
```

## 结构类型

`struct` 或`class`声明类

```c#
struct Str {
    public int a;
    public char b;
    public float c;
    Str(int a, char b, float c) {
      this.a = a;
      this.b = b;
      this.c = c;
    }
    void outArr() {
      Console.WriteLine("{},{},{}",a,b,c);
    }
  }
```

### 类的封装

```c#
class MyData {
    int a;
    public int A {
      set {
        a = value;
      }
      get {
        return a;
      }
    }
  }
```

### 静态变量

```c#
class MyData {
static public void fn() {
      Console.WriteLine("fn()");
    }
}

//k可以直接调用
MyData.fn();
```



## Object对象

```c#
Object o = new Object();
```



## 类型转换

### 类型判断

```c#
int a;
Console.WriteLine(a is bool);}
```

### 类型强转

+ 普通强转

```c#
int a=10;
float f=(float)a;
```

+ 强制强转

```cpp
//转换失败抛出异常
int i3=int.Parse("123");

//不会抛出异常
bool erron;
bool flag = bool.TryParse("ture", out  erron);
Console.WriteLine("{0} {1}", erron, flag);
```

### 类型装箱

```cpp
int a=10;
//栈内存装箱到堆内存
object box = a;
int b=
```



## 集合

### 数组

```c#
int[,] arr2 = {
    {1,2,3 },
    {4,5,6 },
    {7,8,9 },
};
```

