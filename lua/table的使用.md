# lua的table类型

1. table的下标是从1开始
2. 类型其他数据类型中的map容器
3. 遍历的时候对象会被忽略



```lua
my_tb={
	11,2,3,4,15
	,"OK","hello",
	config={1,2,3,4};		--对象会被忽略
	"66"
};

for i=1,#my_tb do
	print(i..":"..my_tb[i]);
end
```



## table 遍历方式

table可以用对象的方式访问,也可以用字符串的形式访问

```lua
my_tb2={
	k=2,
	a=10,
}

--访问方式
print(my_tb2["k"]);
print(my_tb2.k);
```

普通遍历,按照下标顺序返回

```
for i,v in ipairs(my_tb) do
	print(i.."-"..v);
end
```

通过pairs遍历,将所有值显示出来

```lua
for i,v in pairs(my_tb2) do
	print(i,"-",v);
end
```



## userdata



## 原表

```lua
t={}
mt={}

setmetatable(t,mt)

m=getmetatable(t);

```

## SLAXML

github上搜索

## 线程

## 状态

## 内存管理