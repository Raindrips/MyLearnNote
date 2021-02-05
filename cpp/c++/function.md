## 仿函数 Function

可以将函数做为一个变量进行存储

```cpp
//头文件
#include <functional>
```

使用仿函数可以使特定的动作抽象化,从而实现事件等逻辑

```cpp
#include <functional>

using namespace std;

//定义一个函数
int add(int a, int b){
  return a + b;
}

// 仿函数结束函数参数
function<int(int,int)> func=add;

function<int()> func2;
//判断仿函数是否被引用
if(bool(func)){
    cout<<"已经引用了一个函数";
    func(10,20);  //通过仿函数调用函数
}else{
    cout<<"没有引用函数";
}
```

### 调用类的成员函数

```cpp
class AA{
    public:
    AA(){}
    //非静态函数
    void fn(){ cout << "fn()" << endl; }
	//静态函数
    static void instance(){
        cout << "instance" << endl;
    }
};
```

使用function指向类的函数

```cpp
AA::instance();
//指向静态变量,可以直接指向
function<void()> fn1 = &AA::instance;
fn1();

//调用类的成员函数,需要实例化对象才能使用
AA aa;
function<void()> fn2= std::bind(&AA::fn, aa);
fn2();
```

