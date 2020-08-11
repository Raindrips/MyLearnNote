# lua面向对象



使用`self`关键字访问本类成员对象

```lua
-- 简单的类封装
model={
	a=0;		--局部变量
	setA=function(self,a)
		self.a=a;
	end;

	getA=function(self)
		return self.a;
	end;
};

```

调用类,并实现对象

```lua
require("模块");
m=model;
m:setA(10);
a=m:getA();
```

## lua 面向对象



## 继承

```lua
Account={
	new=function(self,o)
		o = o or {};
		setmetatable(o,self);
		self.__index=self;
		return o;
	end;

	show=function()
		print("hello world");
	end
};


obj=Account:new
{ 
	aa=2;
	bb=0;
};

obj.show();
print(obj.aa);
```



## 私有变量和单一方法



