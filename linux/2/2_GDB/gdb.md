## 调试工具的使用

```sh
#调试时加上-g参数
gcc main.c -g

# 使用gdb工具 不打日志
gdb a.out -q
```

命令`gdb`

### 断点

```sh
# 断点 [行号|函数名]
break
b	##简称 
b [函数] if (条件判断)
info break  #查看断点信息

##删除断点 delete d
d 

#继续运行continuing
c	
```

### 当前位置

```sh
#list l 当前代码位置
list
l
```

### 单步执行

```sh
## 往下走
n		#next
## 汇编下一步
nexti

## 逐语句 不进入函数
s		##step

## 退出函数
finish    
```

### 查看信息

```sh
##查看函数堆栈
bt  		

## 查看堆
heap		

## 查看当前栈
info frame 0		## 第0个栈

## 查看值 print p
p  [变量名]
p/x [变量名]  ## 查看地址
p *[指针]
p *(struct 结构体类型*)对象名
```





```sh
## 设置参数 给main函数传递
set args 1 2 3 4

## 运行 r
r	#run

## 查看所有地址的值
vmap

## 查看变量数据
x/20wx		## 查看20个16字节 十六进制查看
```

### 设置观察点

```sh
#为表达式（变量）expr设置一个观察点。一量表达式值有变化时，马上停住程序。
watch <expr>

#当表达式（变量）expr被读时，停住程序。
rwatch <expr>
        
#当表达式（变量）的值被读或被写时，停住程序。    
awatch <expr>
        
#列出当前所设置了的所有观察点。
info watchpoints
```

### 设置捕捉点
`catch <event>`
当event发生时，停住程序。event可以是下面的内容：
1. throw 一个C++抛出的异常。（throw为关键字）
2. catch 一个C++捕捉到的异常。（catch为关键字）
3. exec 调用系统调用exec时。（exec为关键字，目前此功能只在HP-UX下有用）
4. fork 调用系统调用fork时。（fork为关键字，目前此功能只在HP-UX下有用）
5. vfork 调用系统调用vfork时。（vfork为关键字，目前此功能只在HP-UX下有用）
6. load 或 load `<libname>` 载入共享库（动态链接库）时。（load为关键字，目前此功能只在HP-UX下有用）
7. unload 或 unload `<libname> `卸载共享库（动态链接库）时。（unload为关键字，目前此功能只在HP-UX下有用）

`tcatch <event> `
只设置一次捕捉点，当程序停住以后，应点被自动删除。

## 扩展插件



gcc 
 -g -Wall  -O
 -c -I -D -l
-I /wrok/inc/openssl.h 
-D 编译时传入宏定义

指定头文件的文件夹
-l 动态链接库
-lpthread
shell 脚本
./configure 
make 
make install 

printf  printk


	GDB
命令行调试器
gdb gdbserver



调试器  Linux  命令行的调试方法
四个方面的问题：
	1.启动程序，按照你的想法随心所欲的运行程序
	2.断点调试(条件断点)；
	3.当程序停止时，可以查看程序当前的一切
	4.动态改变程序的执行环境
内存 变量  reg    
地址 栈堆 函数调用栈

ps -A
pid 


gcc -g 
main.c display.c ...

b main.c:18
b display.c:func
info 

段错误--->core


三种GDB启动方式
	1.gdb  test 
	2.gdb  test core 
	3.gdb  test pid
	
	
	
A->B->C
A->C
变量值
寄存器
内存
stack

-g
gdb target


GDB
1.run
2.设置break 可以设置条件断点
3.任何时候停止，并查看当前进程所有的一切
4.动态改变执行环境

命令：
	list  l  查看代码
	break b  设置断点  b 行号/函数名
	info  b  查看断点
	run	  r  运行程序到第一个断点
	next  n  运行下一行 不进入函数
	continue c 跳到下一断点
	print  p  打印某个变量
	bt    函数调用栈
	finish 结束当前函数
	quit  q  退出gdb
	until 或 u 退出循环体
	gdb filename
	gdb filename pid
	examine  x
	gdb>set args 10 20 30 40 50
	  
	如何进行反编译
	disassemble
	disassemble /m _ZN5pointC1Eii（readelf  c++filter看出来的符号表）
	shell +命令
	
	 暂停/恢复程序的方法
	1 断点
		break   b 
		break function
		break offset
		break filename:function /offset
		查看设置的断点  info b
		break *address
		条件断点
		break ...if<condition>
		 int a ,b ,c;
		 funa(a);
		 funb(b);
		 func(c);
		 break func if<a==b>
		 eg: break 20 if i==89
		 
	 2 观察点
		watch  当变量被写入（变化）的时候 就停止程序
		rwatch 当该变量被读取的时候 就停止程序
		awatch  当该变量被访问时 就停止程序
		info watchpoint
		
	 捕捉点
	 信号
	 线程暂停
	 
	 3.捕捉点
		catch 
		1.catch throw
		2.catch exec  捕捉系统发生execve系统调用时 暂停程序
		3.catch fork 
		4.catch vfork
		5.catch load 
		6.catch unload
	
	### 讲义

man  在线帮助命令  退出用q
-help  --help 
gdb -help 
	

						Linux GDB调试
GDB linux 中的debug工具
VC VS 
断点调试   单步  步入  步出 
跳到下一断点
内存  寄存器  stack  反编译  内存断点 
变量   线程堆栈  

GDB 调试时修改内存 
flag =90
if(flag ==100)
  A
else 
  B

if(!strcmp(passwd,key))
a
else 
b

gdb 
命令行的调试工具
break 

如果你的程序想要用gdb调试 
gcc -g -o test-1  test-1.c

开启gdb的方法
gdb  test-1 
gdb  attach pid 
gdb  test-1 core   

list  l 
set listsize 20
l test-1.c:10 
l test-1.c:main 

focus 
layout

quit

break  b 
b 20     b test-1.c:20
b func  
info breakpoint 

run  r 
layout 

step  s 步入 
gdb支持命令重复 

next  n 步出 


能够一次跳出循环
until  u 

如果清除一个断点
disable breakpoint 1
clean 
enable breakpoint 1 


跳转到下一个断点
continue   c 

main
  fun1 
  fun2 


fun1 
	fun3 
	
fun3 
  fun4 

bt 

结束当前函数
finish  f 

查看变量值 
info local result 
::
info local file::result  全局
info local function::result  局部


查看寄存器值
info registers eax 
eax ebc 

GDB传入参数
set args 10 20 30 40 50
./test-1 10 20 30 40 50

设置运行路径
path /work 

gdb中如何运行shell命令
shell  +command

二进制指令跟踪 
setpi 
nexti
display/i $pc  自动化显示二进制运行的方式

查看某个地址的内存
x 格式  地址
/8ub
8:显示8个
u:无符号十进制显示
b:byte  h：half word 
w：word


如何查看数组的内容
int a[10];
char a[10]
p *array@len  
p *a@10 

x /10dw a
x /10cb a



查看栈信息的命令 
frame n 
info frame n  打印详细的栈信息
 info args	
  info locals 


GDB的特殊用法
watch 
monitor 
print 
catch