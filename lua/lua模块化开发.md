# lua Modlue

lua模块化编程

+ 一个模块就是一个库



## require

 	将lua内的全局属性包导入进来,如果是`local`,将会被忽略

文件`a1.lua`

 ```lua
--可以被外部导入
function show_name()
	print("show_name");
end

--不能被外部导入
local function local_name()
	print("local_name");
end
 ```



用`require`关键字导入模块,导入后就可以在本文件中使用了

` local`类型的变量虽然不能直接使用,但是可以通过`function`间接调用

````lua
-- 使用require导入模块
-- 参数填写文件名
require("a1");

--如果有多条路径的话用点分割 
-- com/file/a1
require("com.file.a1");
````



使用一个变量来存储导入的包,有多种作用

+ 判断`require`导入的模块是否存在
+ 通过变量存储导入的包

```lua
-- 导入的模块是否存在
a=require("a1");
if a then
    print("导入成功");
end;

-- 模块包导入
b=require("io");
b.write("123");
```



使用`lua` 进行一个伪面向对象编程

````lua
object={
	a=10;
	_name="";
}
object.out=function()
	print("a:"..object.a.." _name:"..object._name);
end

object.setName=function(name)
	object._name=name;
end

return object;
````



## 获取类型

```cpp
tb={a=1,b=2}
type(tb)=='table'  
```



## 类的设计

```lua
--创建一个类,继承cc
local MyApp=class("myApp",cc);

--构造
function MyApp:ctro()
    MyApp.super.ctro(self)
    
end

--
```



