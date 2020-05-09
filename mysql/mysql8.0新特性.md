# mysql8.0新特性

	1. 账户安全
 	2. 优化索引
 	3. 通用表达式
 	4. 窗口函数
 	5. InnoDB增强
 	6. JSON增强

## 账户安全

1. 用户创建和授权
2. 认真插件更新
3. 密码管理
4. 角色管理

### 用户创建和授权

mysql 8.0 创建用户和授权用户命令需要分开执行

```mysql
create user 'user1'@ '%' identified by 'passwd';
```

