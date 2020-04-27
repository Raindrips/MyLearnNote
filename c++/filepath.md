# 文件系统库

头文件

```cpp
#include <filesystem>
```

类名

path

成员变量

```cpp
class path{
	//构造函数
    //p 路径
    path(string& p);
    
    //可以用cout输出
    ostream& operator<<();
    
    //返回相对路径
    path filename();
    //检查路径是否为空
    bool empty();
    
}
```

