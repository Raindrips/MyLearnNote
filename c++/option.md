# option

c++17的新特性

```cpp
#include <option>
```

option的作用

```cpp
//给一个值类型拥有true和false的一个形式
void test2() {
    optional<int> op(10);
    cout << *op << endl;
    op = 20;
    cout << *op << endl;

    optional<float> op2;
    op2 = 3.1415;
    op2.reset();
    if (op2.has_value()) {
        cout << *op2 << endl;
    }
    else {
        cout << "这个类型没有值" << endl;
    } 
}
```

