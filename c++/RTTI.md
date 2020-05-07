# 类型识别

auto自动识别类型

```cpp
auto p=new int; //int*
int a=10; //int类型
```

通过模板识别类型

 ```cpp
template <typename T>
T max(T a1,T a2){
 	return a1>a2?a1:a2;   
}

max(10,20);
 ```

类型推导

```cpp
//类型推断
int a=10;
decltype(a)	b=20; //int
```

## 动态类型识别

```cpp
//判断类型名称
string str;
cout<<typeid(str).name()<<endl;

//
typedef int type;
//给创建类型标识符 
using type= int;
```



