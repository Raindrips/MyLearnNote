## lua语言

lua语言是一个解释型语言,不需要编译就可以直接运行

## 基本语法

表示单行注释

```lua
-- 单行注释
--[[
这是多行注释
这是多行注释
]]

```

print 输出函数

```lua
a=10;
print(a);
```

## 数据类型

lua是弱类型语言,类型可以直接转换

```lua
a=10;
print(a)
a="hello world"
print(a);
//字符串拼接
```

类型有

1. number数字类型
2. string字符串类型
3. bool布尔类型
4. thread类型
5. function类型
6. table类型
7. nil类型

## 条件表达式

if  then elseif else end

```cpp
b=10;
if b>10 then
 print("b>10 "..b);
elseif b<10 then
	print("b<0 "..b);
else
	print("last "..b);
end
```

## 循环

`while`循环 表达式为真就继续

```lua
--循环语句
i=1;
sum=0;
while i<=100 do
	sum=sum+i;		--lua 没有++ -- 的语句
	i=i+1;
end
print(sum);
```

`repeat .. until ` 直到型循环

```lua
re=0
repeat 
	re=re+1;
until re==3; --表达式为真时结束循环
print(re);
```

`for` 循环

第一个参数赋值

第二个是结束条件

第三个是自变量

```lua
a="";
for i=1,10 do
	a=a.." "..i;
end
print(a);

a="";
for i=20,0,-1 do
	a=a.." "..i;
end
print(a);

--循环
for v -1,100 do
	print(v); 
end
```



## 作用域

`local` 定义局部变量,默认的是定义全局变量

  ```lua
local a=10;
--全局变量
b=0;
  ```

## 布尔运算

`true` 和 `false` 两种

nil是空类型,表示的是false

`and`且 

`or` 或

```lua
--且
print(true and false);
print(true and true);

--或
print(true or false);
print(true or true);

print(true or nil);
print(true and nil);
```



## 表

```lua
config={
	a=10;
};
config.b=20;

-- 遍历
for key,var pairs(config) do
   	print( key,var);
end
```

## 数组

```lua
-- lua没有数组概念,可以用表替代
arr={1,2,3,4,5,6,7,8,9};

-- 插入数据
table.insert(arr,1,10);

-- 求最大值
table.maxn(arr);
```



## 拷贝表

```lua
function clone(tab) 
    ins={};
	for key,var in pair(tab) do
        ins[key]=var;
    end
end
```



## 闭包

```lua
function class(name)
    local obj={};
    obj.name=name;
    obj.say=function()
    	print(obj.name);
    end
    return obj;
end

a=class("hello");

a.say();
```
