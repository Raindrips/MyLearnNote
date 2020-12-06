# Git的使用

## 什么是Git

Git是一个**版本控制**的工具,版本控制是一种记录一个或若干文件内容变化，以便将来查阅特定版本修订情况的系统。

## 使用Git的好处

1. 代码可以进行版本管理,如果代码写错了,可以退回到上次正确的版本
2. 分布式版本控制系统.可以让代码有多个分支,比如在不同操作系统上运行
3. 监测版本的变化,每次修改的地方都可以被找到,随时知道自己添加了哪些文件,删除了哪些文件,修改了哪些地方
4. 代码备份,随时远程备份自己的代码,本地代码丢失可以找回
5. 多人合作,集中管理

--------------------------------------------------------------------------------
[git官方网站]:https://git-scm.com/



## git的使用

### 下载Git

 第一步,要下载git工具,git的原型也是一个只有控制台界面的程序,可以额外下载有图形界面的工具

默认下载的自带一个图形界面,和一个仿Linux的终端程序

-----------------------------------------------

[git下载地址]:https://git-scm.com/downloads



# 创建自己的一个git项目

### git的配置

**全局设置:**首先要设置一个用户名和邮箱,才能使用,格式如下

```sh
git config --global user.name "用户名"
git config --global user.email "邮箱账号@qq.com"
```

开始创建git仓库的命令,讲会在本地文件夹,创建一个`.git`的隐藏文件夹

```shell
git init			#初始话git仓库
```

添加要进行跟踪的文件到暂存区里

```shell
git add [file]	#可以连续添加跟踪文件上
```

添加代码到版本库,已经将该内存进行保存了

```shell
git commit -m [提交的内容注释]
```

移除文件

```sh
git rm [file] 
	--cached [file]  #不删除物理文件，只将add进缓存的文件删除。
	-r #有目录的话加此参数
	-f #会删除物理文件
```



```sh
# 检查状态
git status

# 查看跟踪文件的的修改
git diff
git diff HEAD -- [file]		#查看上次修改
```



```sh
#上传最近的记录 从最近到最远的提交日志，我们可以看到3次提
git log
	 --pretty=oneline		#减少输出信息

#命令历史，以便确定要回到未来的哪个版本
git reflog	 

# 回到上一次版本
git reset				 
	--soft  				#不会修改文件,只会改变指针
	--mixed  				#改变暂存区,不改变工作区
		HEAD				#暂存区的地方撤销	
	--hard commit_id		#回退到指定的版本,内容也会全部更变
	
	
#HEAD表示当前版本
#上一个版本就是HEAD^
#上上一个版本就是HEAD^^
#100个版本可以写成HEAD~100
```

```sh
#修改分支
git checkout
	--[file] 撤销工作区的修改
```


### 工作区和暂存区			

Working Directory


工作区（Working Directory）

版本库（Repository）

git add 把文件添加进去，实际上就是把文件修改添加到暂存区

git commit提交更改，实际上就是把暂存区的所有内容提交到当前分支

Git自动为我们创建了唯一一个master分支，所以，现在，git commit就是往master分支上提交更改

## 远程仓库

常见的远程仓库

+ [码云]: https://gitee.com/

+ [github]: https://github.com/

  

## 创建密钥

能够识别计算机,让远程仓库可以识别这个电脑用户,没有密钥,每次远程推送都需要用户密码才行

```sh
##创建秘钥
ssh-keygen -t rsa -C "youremail@example.com"

#id_rsa是私钥，不能泄露出去，
#id_rsa.pub是公钥可以放心地告诉任何人
#Add SSH Key	id_rsa.pub
```

创建成功之后就会出现在 [C:\Users\用户名]

```sh
# 远程仓库添加
git remote add origin [远程仓库]

#所有内容添加到远程仓库上
git push -u origin

##推送到主分支
git push -u origin master

git push [origin] [branch]
	-u origin master		第一次推送加上 -u	
```

通过`pull` 更新远程仓库的内容

```sh
#将远程仓库上的更新的内容,推送到本地,然后同步
git pull 

## 将远程仓库内容拉取过来,但是不改变本地工作区的内容
git fetch
```



## 克隆一个仓库

将远程仓库上的内容下载到本地,成功之后,就会在本地生成一个文件夹

> git clone [远程域名]

```sh
git clone https://gitee.com/Raindrips/git_learning.git
```

### git分支管理

#### 创建分支

git branch [分支名称]

 -d <name>  删除分支

```sh
## 查看所有分支和当前所在的分支
git branch

## 创建一个新分支  -b 表示创建完成并自动切换
git branch test

## 删除分支
git branch -d test
```

#### 切换分支

git checkout [分支名称]

​	-b [branch]		创建并切换

```sh
## 切换分支
git checkout test

## 创建分支并切换
git checkout -b test2
```

#### 合并分支

合并分支应该先切换到主目录下,再合并新建的分支

> git merge [branch]		 指定分支到当前分支
> --abort 		撤销合并

```sh
## 合并分支命令
git merge test

## 撤销合并分支
git merge --abort
```

 switch  切换分支  替换checkout

 设置git push和pull的默认远程分支

```sh
 git branch --set-upstream-to=origin/master master
```

## git 日志

Git 删除具体某个提交`commit`的方法

1. `git log`获取`commit`信息 
2. git rebase -i (commit-id) 
   commit-id 为要删除的commit的下一个commit号 
   3. 编辑文件，将要删除的commit之前的单词改为drop 
   4. 保存文件退出大功告成 

删除已经commit的大文件

```bash
git filter-branch --force --index-filter 'git rm --cached --ignore-unmatch *.gz' --prune-empty --tag-name-filter cat -- --all
```