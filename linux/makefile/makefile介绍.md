# MakeFile

会不会写makefile，从一个侧面说明了一个人是否具备完成大型工程的能力

## 关于程序的编译和链接
无论是C、C++首先要把源文件编译成中间代码文件，在Windows下也就是 .obj 文件，UNIX下是 .o 文件，动作叫做编译（compile）。然后再把大量的Object File合成执行文件，这个动作叫作链接（link）。   
     
编译时，编译器需要的是语法的正确，

链接时，主要是链接函数和全局变量，

要给中间目标文件打个包，在Windows下这种包叫“库文件”（Library File)，也就是 .lib 文件，在UNIX下，是Archive File，也就是 .a 文件。

​       

## Makefile 介绍
make命令执行时，需要一个 Makefile 文件，以告诉make命令需要怎么样的去编译和链接程序。

Makefile的书写规则。
我们的工程有8个C文件，和3个头文件，我们要写一个Makefile来告诉make命令如何编译和链接这几个文件。我们的规则是：
          
1. 如果这个工程没有编译过，那么我们的所有C文件都要编译并被链接。
2. 如果这个工程的某几个C文件被修改，那么我们只编译被修改的C文件，并链接目标程序。
3. 如果这个工程的头文件被改变了，那么我们需要编译引用了这几个头文件的C文件，并链接目标程序。

只要我们的Makefile写得够好，所有的这一切，我们只用一个make命令就可以完成，make命令会自动智能地根据当前的文件修改的情况来确定哪些文件需要重编译，从而自己编译所需要的文件和链接目标程序。
###  Makefile的规则
   在讲述这个Makefile之前，还是让我们先来粗略地看一看Makefile的规则。

```
target... : prerequisites ...
    command
    ...
```

target也就是一个目标文件，可以是Object File，也可以是执行文件。还可以是一个标签(Label)

prerequisites就是，要生成那个target所需要的文件或是目标。

command也就是make需要执行的命令。（任意的Shell命令）

###  一个示例
正如前面所说的，如果一个工程有3个头文件，和8个C文件，我们为了完成前面所述的那三个规则，我们的Makefile应该是下面的这个样子的。

```makefile
edit : main.o kbd.o command.o display.o \
insert.o search.o files.o utils.o
cc -o edit main.o kbd.o command.o display.o \
insert.o search.o files.o utils.o

main.o : main.c defs.h
cc -c main.c
kbd.o : kbd.c defs.h command.h
cc -c kbd.c
command.o : command.c defs.h command.h
cc -c command.c
display.o : display.c defs.h buffer.h
cc -c display.c
insert.o : insert.c defs.h buffer.h
cc -c insert.c
search.o : search.c defs.h buffer.h
cc -c search.c
files.o : files.c defs.h buffer.h command.h
cc -c files.c
utils.o : utils.c defs.h
cc -c utils.c
clean :
rm edit main.o kbd.o command.o display.o \
insert.o search.o files.o utils.o
```

反斜杠（\）是换行符的意思。这样比较便于Makefile的易读。

如果要删除执行文件和所有的中间目标文件，执行一下“make clean”        

在这个makefile中，目标文件（target）包含：

+ 执行文件edit和中间目标文件（*.o）
+ 依赖文件（prerequisites）就是的那些 .c 文件和 .h文件。
每一个 .o 文件都有一组依赖文件，而这些 .o 文件又是执行文件 edit 的依赖文件。依赖关系表示目标文件是哪些文件更新的。


### make是如何工作的

在默认的方式下，也就是我们只输入make命令。那么，
1. make在当前目录下寻找“Makefile”或“makefile”
2. 如果找到，它会找文件中的第一个目标文件（target），在上面的例子中，他会找到“edit”这个文件，并把这个文件作为最终的目标文件。
3. 如果edit文件不存在，或是edit所依赖的后面的 .o 文件的文件修改时间要比edit这个文件新，那么，他就会执行后面所定义的命令来生成edit这个文件。
4. 如果edit所依赖的.o文件也存在，那么make会在当前文件中找目标为.o文件的依赖性，如果找到则再根据那一个规则生成.o文件。（这有点像一个堆栈的过程）
5. 当然，你的C文件和H文件是存在的啦，于是make会生成 .o 文件，然后再用 .o 文件声明make的终极任务，也就是执行文件edit了。

出现问题就停止工作

没有被第一个目标文件直接或间接关联，那么它后面所定义的命令将不会被自动执行，

可以显示执行。“make clean”，


###  makefile中使用变量
在上面的例子中，先让我们看看edit的规则：
```makefile
edit : main.o kbd.o command.o display.o \
 insert.o search.o files.o utils.o
 
cc -o edit main.o kbd.o command.o display.o \
insert.o search.o files.o utils.o
```
makefile中使用变量

```makefile
objects = main.o kbd.o command.o display.o \
 insert.o search.o files.o utils.o
```
然后以“$(objects)”的方式来使用变量
```makefile
objects = main.o kbd.o command.o display.o \
insert.osearch.o files.o utils.o 
edit : $(objects)
cc -o edit $(objects)
main.o : main.c defs.h
cc -c main.c
kbd.o : kbd.c defs.h command.h
cc -c kbd.c
command.o : command.c defs.h command.h
cc -c command.c
display.o : display.c defs.h buffer.h
cc -c display.c
insert.o : insert.c defs.h buffer.h
cc -c insert.c
search.o : search.c defs.h buffer.h
cc -c search.c
files.o : files.c defs.h buffer.h command.h
cc -c files.c
utils.o : utils.c defs.h
cc -c utils.c
clean :
rm edit $(objects)
```
于是如果有新的 .o 文件加入，只需简单地修改一下 objects 变量就可以了。

### 让make自动推导

```makefile
   objects = main.o kbd.o command.o display.o \
             insert.o search.o files.o utils.o

   edit : $(objects)
           cc -o edit $(objects)

   main.o : defs.h
   kbd.o : defs.h command.h
   command.o : defs.h command.h
   display.o : defs.h buffer.h
   insert.o : defs.h buffer.h
   search.o : defs.h buffer.h
   files.o : defs.h buffer.h command.h
   utils.o : defs.h

   .PHONY : clean
   clean :
           rm edit $(objects)
```

这种方法，也就是make的“隐晦规则”。上面文件内容中，“.PHONY”表示，clean是个伪目标文件。
关于更为详细的“隐晦规则”和“伪目标文件”，我会在后续给你一一道来。
### 另类风格的makefile
```makefile
objects = main.o kbd.o command.o display.o \
insert.o search.o files.o utils.o

edit : $(objects)
cc -o edit $(objects)

$(objects) : defs.h
kbd.o command.o files.o : command.h
display.o insert.o search.o files.o : buffer.h

.PHONY : clean
clean :
rm edit $(objects)
```
这种风格，让我们的makefile变得很简单，但我们的文件依赖关系就显得有点凌乱。
### 清空目标文件的规则

  每个Makefile中都应该写一个清空目标文件（.o和执行文件）的规则，

```makefile
.PHONY : clean
clean :
-rm edit $(objects)
```



## Makefile 总述

###  Makefile里有什么？
<!-- Makefile里主要包含了五个东西：显式规则、隐晦规则、变量定义、文件指示和注释。 -->

1. 显式规则
显式规则说明了，如何生成一个或多的的目标文件。这是由Makefile的书写者明显指出，要生成的文件，文件的依赖文件，生成的命令。
2. 隐晦规则
由于我们的make有自动推导的功能，所以隐晦的规则可以让我们比较粗糙地简略地书写Makefile，这是由make所支持的。
3. 变量的定义
在Makefile中我们要定义一系列的变量，变量一般都是字符串，这个有点你C语言中的宏，当Makefile被执行时，其中的变量都会被扩展到相应的引用位置上。
4.文件指示
其包括了三个部分，一个是在一个Makefile中引用另一个Makefile，就像C语言中的include一样；另一个是指根据某些情况指定Makefile中的有效部分，就像C语言中的预编译#if一样；还有就是定义一个多行的命令。有关这一部分的内容，我会在后续的部分中讲述。
5. 注释
Makefile中只有行注释，和UNIX的Shell脚本一样，其注释是用“#”字符，这个就像C/C++中的“//”一样。如果你要在你的Makefile中使用“#”字符，可以用反斜框进行转义，如：“\#”。
最后，还值得一提的是，在Makefile中的命令，必须要以[Tab]键开始。

### Makefile的文件名

默认的情况下顺序找寻文件名为“GNUmakefile”、“makefile”、“Makefile”最好使用“Makefile”这个文件名

当然，你可以使用别的文件名来书写Makefile，如果要指定特定的Makefile，你可以使用make的`-f`或`--file`参数
### 引用其它的Makefile

语法规则

```makefile
include filename
## 使用通配符
include  *.mk

#无论include过程中出现什么错误
-include filename
```





1.        读入所有的Makefile。
2.        读入被include的其它Makefile。
3.        初始化文件中的变量。
4.        推导隐晦规则，并分析所有规则。
5.        为所有的目标文件创建依赖关系链。
6.        根据依赖关系，决定哪些目标要重新生成。
7.        执行生成命令。
1-5步为第一个阶段，6-7为第二个阶段。
1.        文件的依赖关系

