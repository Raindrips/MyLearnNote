# windows 软链接的建立及删除

```shell
#建立连接目录指向远程链接目录
mklink /d [file]  [toFile]

#建立硬链接
mklink /d /h [file]  [toFile]
```

 

​	删除虚拟的链接目录，并不会删除远程文件夹真实文件，注意千万不能用`del`，`del`会删除远程的真实文件。

```shell
rmdir [file]
```

