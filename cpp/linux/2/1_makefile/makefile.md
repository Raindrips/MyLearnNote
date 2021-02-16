## makefile命令

### Makefile 的作用

​		告诉make维护一个大型程序，
该做什么。Makefile说明了组成程序的各模块间的相互
关系及更新模块时必须进行的动作，
make按照这些说明自动地维护这些模块。

执行make命令时，需要一个 Makefile 文件，以告诉make命令需要怎么样的去编译和链接程序。
Makefile是一个文本形式的数据库文件，其中包含一些规则来告诉make处理哪些文件以及如何处理这些文件。这些规则主要是描述哪些文件（称为target目标文件，不要和编译时产生的目标文件相混淆）是从哪些别的文件（称为dependency依赖文件）中产生的，以及用什么命令（command）来执行这个过程。



### makefile内容

1. 显式规则。显式规则说明了如何生成一个或多个目标文件。这是由Makefile的书写者明显指出，要生成的文件，文件的依赖文件，生成的命令。
1. 隐晦规则。由于make有自动推导的功能，所以隐式规则可以让我们比较粗糙地简略地书写Makefile，这是由make支持的。
1. 变量的定义。在Makefile中我们要定义一系列的变量，变量一般都是字符串，这个有点你C语言中的宏，当Makefile被执行时，其中的变量都会被扩展到相应的引用位置上
1. 文件指示。其包括了三个部分，一个是在一个Makefile中引用另一个Makefile，就像C语言中的include一样；另一个是指根据某些情况指定Makefile中的有效部分，就像C语言中的预编译#if一样。
1. 注释。和UNIX的Shell脚本一样Makefile中只有行注释， 其注释是用“#”字符，这个就像C/C++中的“//”或者“ /*”。

> **在Makefile中的命令，必须要以[Tab]键开始！！！**

### 引用其它的Makefile 

在Makefile使用include关键字可以把别的Makefile包含进来，这很像C语言的#include，被包含的文件会原模原样的放在当前文件的包含位置。include的语法是：

#include <filename>

filename可以是当前操作系统Shell的文件模式（可以保含路径和通配符）
Make支持三种通配符： “*”、“？”、“[…]”



```makefile
include foo.make *.mk $(bar)
#等价于:
include foo.make a.mk b.mk c.mk e.mk f.mk
```



