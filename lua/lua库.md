# 数学库



| `os.time()`               | 获取时间          |
| :------------------------ | ----------------- |
| `math.sin(x)`             | sin函数           |
| `math.rad(x)`             | 角度转弧度        |
| `math.deg(x)`             | 弧度转角度        |
| `math.exp(x)`             | 指数              |
| `math.log(x)`             | 对数              |
| `math.ceil()`             | 向下取整          |
| `math.floor()`            | 向上取整          |
| `math.max()` `math.min()` | 取最大值,和最小值 |
| `math.ramdom(1,10)`       | 随机数            |



# table库

```lua
t={1,2,3}
-- 在指定位置插入数据
table.insert(t,1,20);
-- 尾部插入数据
table.insert(t,20);

-- 指定位置删除位置
table.remove(pos);

-- 排序
table.sort(t);

--连接对象
table.concat(tab)
```



# string库

```lua
-- 寻找子串
string.find(str);

--正则匹配
string.mathch(str,"reg");

-- 截取字符串
string.sub(str,begin,end);

-- 替换字符串
string.gsub(str,str1,replace);

string.format(str,...);
```



## IO库

导入模块库

IO模块没有打开文件则在控制台输出

```lua
--导入模块
require("io");	

--打开文件
i=assert(io:open("txt",'r'));

--写入文件
i.write("写入文件内容");

--读取文件
text=i.read("*all");

-- 读取整个文件
--[[
	*all 读取整个文件
	*line 读取下一行
	*number 读取一个数字
	<num>读取num个字符串
]]

-- 关闭文件
i.close();
```

代开文件进行写入

```lua
--r 读取文件
--w 打开文件
--a 追加文件
--*b 二进制的方式读取 *表示[r,w,a]
file = io.open("1.txt","w");

file.write("abcd");

-- 关闭文件
file:close();
```

输入输出流

```lua
io.input();

op.input("input commend");
```

