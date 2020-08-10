# Mysql用户管理

### 8.0以上版本版本

### 修改密码

```mysql
#修改密码为1234
ALTER user 'root'@'localhost' identified by '1234';

#刷新权限
flush privileges;
```

### 创建其他用户

#### 创建一个用户

```mysql
# 创建账号密码
CREATE USER `用户名`@`loaclhost` IDENTIFIED BY 'passowrd';
```

用户的使用

```mysql
# 授予权限
GRANT ALL ON *.* TO `用户名`@`127.0.0.1` WITH GRANT OPTION;

# 删除权限
REVOKE all privileges ON databasename.tablename FROM 'username'@'host';

# 修改密码
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '你的密码';  
```

### 权限分类





| 语句                    | 功能                             |
| ----------------------- | -------------------------------- |
| CREATE ROLE并 DROP ROLE | 角色创建和删除；                 |
| GRANT  REVOKE           | 用户和角色分配和撤销权限         |
| SHOW GRANTS             | 显示用户和角色的权限和角色分配   |
| SET DEFAULT ROLE        | 指定哪些帐户角色默认处于活动状态 |
| SET ROLE                | 更改当前会话中的活动角色         |
| CURRENT_ROLE()          | 功能显示当前会话中的活动角色     |



要验证分配给用户的权限

```mysql
SHOW GRANTS FOR 'user1'@'localhost';
```



验证其他类型的用户：

```mysql
SHOW GRANTS FOR 'read_user1'@'localhost' USING 'app_read';
```

