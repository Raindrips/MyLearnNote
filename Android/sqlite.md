# 使用sqlite



## 文件


```java
 openFileOutPut();
```



 创建的文件保存在 `/data/data/<package name>/files` 目录

类型 Context.MODE_PRIVATE

权限配置

```xml
 Android权限 
 <!--文件SD卡创建权限-->
	android.permission.MOUNT_UNMOUNT_FILESYSTEMS
 <!--SD卡写入数据权限--> 
 android.permission.WRITE_EXTERNAL
```



##  XML解析
```java
SAXParserFactory spf;
```