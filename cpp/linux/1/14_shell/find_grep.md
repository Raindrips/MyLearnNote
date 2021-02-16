# find命令

Linux find命令用来在指定目录下查找文件,不设置任何参数，则find命令将在当前目录下查找子目录与文件

### 语法



```sh
find   path   -option   [   -print ]   [ -exec   -ok   command ]   {} \;
```



-mount, -xdev : 只检查和指定目录在同一个文件系统下的文件，避免列出其它文件系统中的文件



列:找到c文件

```sh
# find . -name "*.c"
```

将目前目录其其下子目录中所有一般文件列出



```sh
#文件类型是 c 的文件。
find -type c:

#文件类型是文件。
find . -type f:

find . -type d:
```

