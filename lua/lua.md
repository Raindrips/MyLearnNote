## lua语言

lua语言是一个解释型语言,不需要编译就可以直接运行

## 基本语法

```lua
-- 单行注释
[[

]]
--循环
for v -1,100 do
	print(v); 
end
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

## cocos2d创建lua项目

```sh
## 加上参数 -l lua
cocos new -l lua 
```

