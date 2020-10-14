## 安装

```sh	
## 安装并显示控制台
mysqld --install --show --console

##如果成功了,
mysqld -install
```

然后执行初始化命令

```sh
#初始化数据库
mysqld --initialize --console

mysqld --initialize-insecure --console
```



```sh

```



## 修改密码

```mysql
## 修改root用户密码
use mysql;
ALTER USER 'root'@'localhost' IDENTIFIED BY '1234';

## 将密码初始化为空
alter 

FLUSH PRIVILEGES;
flush privileges;
```

### 忘记密码

```sh
## 先关闭mysql服务
net stop mysql

## 然后通过特定方式启动服务
mysqld -console -skip-grant-tables

## 然后启动一个新的cmd界面,原来的不要关
mysql -uroot -p
```

## 操作步骤

```sh
##管理员的方式打开cmd
##删除mysql服务
sc stop mysql

## 安装mysql
mysqld --install --show --console
mysqld -install
mysqld --initialize --console
## 然后会产生一个随机密码,找到随机密码复制然后记事本保存一下

sc start mysql
mysql -uroot -p保存的随机密码

#进入了mysql服务页面
use mysql;
alter user 'root'@'localhost' IDENTIFIED by '新密码';
```

