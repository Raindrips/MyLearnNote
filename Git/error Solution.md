# 错误解决方案
git add出现 "fatal: in unpopulated submodule XXX" 错误+
因为hexo-theme-matery是从另一个第三方的仓库克隆的，在执行git add的时候"fatal: in unpopulated submodule hexo-theme-matery" 错误

```sh
git rm -rf --cached [file]
git add [file]/*
```

status 和 commit乱码


```sh
git config --global core.quotepath false
```



# Git LF和CRLF问题解决记录

**问题**:`git add`时出现`warning: LF will be replaced by CRLF in ...`

```shell
git config –global core.autocrlf false; 
```



显示项目目录

```shell
git config –list
```

# Git恢复 git rm -rf 的文件

没有过commit，但用`git rm -rf`将所有代码全删了。。。

原因啊什么的就不说了，直接上解决办法：

首先用:

```shell
git prune -n
```

可以列出所有的二进制文件，使用git删除的文件还会缓存在`.git`中;
 类似：

```shell
efb488d1d1b6b29f1caaa5f087432a17ea9128fe blob
```

然后用：

```shell
git cat-file -p efb488d1d1b6b29f1caaa5f087432a17ea9128fe
```

可以将二进制文件内容输出为文本显示。看到文本内容后判断是什么文件，最后

```shell
git cat-file -p efb488d1d1b6b29f1caaa5f087432a17ea9128fe > filename.py
```

将文本存入文件中，恢复此文件。