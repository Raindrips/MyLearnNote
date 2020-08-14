# tuple 元组

c++14 新增加的一个特性

```cpp
#include <tuple>
```

元组对象的初始化

```cpp
//可以填上不同的数据类型 
tuple<int, float, double> tp1;
//初始化时赋值
tuple<int, float, double> tp2(10,20.5f,123);

//访问和修改元素
get<1>(tp1) = 20;
cout << get<2>(tp2) << endl;
```

自动识别类型

```cpp
auto mytp = make_tuple(1, string("hello"), 'c');
```

结构化绑定`C++17`

```cpp
//结构化绑定
auto [a, b, c] = tp2;
//让一个函数有多个返回值
auto [q, w, e] = fn();
```





