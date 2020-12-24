## 调试工具的使用

命令`gdb`

```sh
#断点 [行号][函数名]
b 25 #break
b 函数名
b 函数 if (条件判断)
## 设置参数 给main函数传递
set args 1 2 3 4

## 运行 r
r	#run

## 往下走
n		#next
## 汇编下一步
nexti

## 逐语句 不进入函数
s		##step

## 查看值 print p
p  [变量名]
p/x [变量名]  ## 查看地址
p *[指针]
p *(struct 结构体类型*)对象名

## 查看所有地址的值
vmap

## 查看堆
heap

## 查看变量数据

x/20wx		## 查看20个16字节 十六进制查看

## 查看当前栈
info frame 0		## 第0个栈

##删除断点 delete d
d 
```

## 扩展插件

