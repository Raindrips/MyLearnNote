## any类型

头文件 `#include <any>`

### 使用any替代void*

```cpp
#include <iostream>
#include <any>
using namespace std;

class AA {
	int a;
public:
	AA(int a) :a(a) {}
	void out() { cout << a << endl; }
};
int main()
{
	any a=10;
	any b = 3.14;
	any A = new AA(10);
	int a1 = any_cast<int>(a);
	double b2= any_cast<double>(b);
	AA* A2 = any_cast<AA*>(A);
	A2->out();
	return 0;
}
```

### any异常

```cpp
void any_test() {
	any an = new AA(1);
	BB* b;
	try
	{
		 b= any_cast<BB*>(an);
	}
	catch (const std::bad_any_cast&)
	{
		cout << "类型强转错误" << endl;
		b = nullptr;
	}
	cout << b;
}
```

