git config 	--global user.name “wirelessqa”
git config 	--global user.email wirelessqa.me@gmail.com

#创建
git init 

#添加到版本库
git commit 
-m [注释]


#添加文件
git add [file]	#可以连续添加跟踪文件上

#移除文件
git rm [file] 
	--cached [file]  不删除物理文件，只将add进缓存的文件删除。
	-r 有目录的话加此参数
	-f 会删除物理文件

*检查状态 *
`git status`



#查看上传修改
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