## 仿函数 Function

#include <functional>

```cpp
#include <functional>

using namespace std;

int add(int a, int b){
  return a + b;
}

// 仿函数结束函数参数
function<int(int,int)> func=add;

function<int()> func2;
if(bool(func)){
    cout<<"已经引用了一个函数";
}else{
    cout<<"没有引用函数";
}
```

### 调用类的成员函数

```cpp
class AA{
public:
  AA(){}
  void fn(){ cout << "fn()" << endl; }
  static void instance(){
	cout << "instance" << endl;
  }
};
```

使用function指向类的函数

```cpp
AA::instance();
//指向静态变量
function<void()> fn1 = &AA::instance;
fn1();

//调用类的成员函数
AA aa;
function<void()> fn2= std::bind(&AA::fn, aa);
fn2();
```

