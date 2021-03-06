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



### git的配置

**全局设置:**首先要设置一个用户名和邮箱,才能使用,格式如下

```shell
git config --global user.name "用户名"
git config --global user.email "邮箱账号@qq.com"
```

开始创建git仓库的命令

```shell
git init			#初始话git仓库
```

添加要进行跟踪的文件

```shell
git add [file]	#可以连续添加跟踪文件上
```



添加代码到版本库

```shell
git commit -m [提交的内容注释]
```

移除文件

```shell
git rm [file] 
	--cached [file]  #不删除物理文件，只将add进缓存的文件删除。
	-r #有目录的话加此参数
	-f #会删除物理文件

```



*检查状态*
`git status`



#查看跟踪文件的的修改
`git diff`

git diff HEAD -- [file]		#查看上次修改

#上传最近的记录 从最近到最远的提交日志，我们可以看到3次提
git log
	 --pretty=oneline		#减少输出信息

#命令历史，以便确定要回到未来的哪个版本
git reflog	 
	 
#回到上一次版本
`git reset`   				 
	--soft  				不会修改文件,只会改变指针
	--mixed  				改变暂存区,不改变工作区
		HEAD				#暂存区的地方撤销	
	--hard commit_id		#回退到指定的版本,内容也会全部更变
		

#修改分支
git checkout
	-- [file] 撤销工作区的修改	

#HEAD表示当前版本
#上一个版本就是HEAD^
#上上一个版本就是HEAD^^
#100个版本可以写成HEAD~100



### 工作区和暂存区			

Working Directory


工作区（Working Directory）

版本库（Repository）

git add把文件添加进去，实际上就是把文件修改添加到暂存区

git commit提交更改，实际上就是把暂存区的所有内容提交到当前分支

Git自动为我们创建了唯一一个master分支，所以，现在，git commit就是往master分支上提交更改


#远程仓库

##创建秘钥
ssh-keygen -t rsa -C "youremail@example.com"

id_rsa是私钥，不能泄露出去，
id_rsa.pub是公钥可以放心地告诉任何人
Add SSH Key	id_rsa.pub



#远程仓库添加
git remote add origin git@github.com:michaelliao/learngit.git


所有内容添加到远程仓库上
git push [origin] [branch]
	-u origin master		第一次推送加上 -u

克隆一个仓库
git clone [url]

# git分支管理

+ 创建分支
  git branch [branch]

+ 切换分支
  git checkout [branch]
  -b [branch]		创建并切换

+ 合并分支 指定分支到当前分支
  git merge [branch]		
  --abort 		撤销合并

 switch  切换分支 替换checkout

 删除分支：git branch -d <name>

 设置git push和pull的默认远程分支
    git branch --set-upstream-to=origin/master master
	

Git 删除具体某个提交commit的方法

1. git log获取commit信息 
2. git rebase -i (commit-id) 
   commit-id 为要删除的commit的下一个commit号 
   3.编辑文件，将要删除的commit之前的单词改为drop 
   4.保存文件退出大功告成 
   5.git log查看



删除已经commit的大文件

```bash
git filter-branch --force --index-filter 'git rm --cached --ignore-unmatch *.gz' --prune-empty --tag-name-filter cat -- --all
```