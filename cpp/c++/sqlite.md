# sqlite

​	

## SQLite 局限性

在 SQLite 中，SQL92 不支持的特性如下所示：

| 特性             | 描述                                                         |
| ---------------- | ------------------------------------------------------------ |
| RIGHT OUTER JOIN | 只实现了 LEFT OUTER JOIN。                                   |
| FULL OUTER JOIN  | 只实现了 LEFT OUTER JOIN。                                   |
| ALTER TABLE      | 支持 RENAME TABLE 和 ALTER TABLE 的 ADD COLUMN variants 命令，不支持 DROP COLUMN、ALTER COLUMN、ADD CONSTRAINT。 |
| Trigger 支持     | 支持 FOR EACH ROW 触发器，但不支持 FOR EACH STATEMENT 触发器。 |
| VIEWs            | 在 SQLite 中，视图是只读的。您不可以在视图上执行 DELETE、INSERT 或 UPDATE 语句。 |
| GRANT 和 REVOKE  | 可以应用的唯一的访问权限是底层操作系统的正常文件访问权限。   |

## Sql安装

请访问 [SQLite 下载页面](http://www.sqlite.org/download.html),下载对应版本即可



## 使用sqlite

```sqlite
.exit	#退出
```



