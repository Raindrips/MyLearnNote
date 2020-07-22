# JSP 内置对象

什么是session
+ session 表示客户端与服务器的一次恢复
+ web中的session指定是用户浏览某个网站时，从进入网站到浏览器关闭所经过的这段时间
+ 每个用户对应一个session

## session对象

+ 内置JSP对象
+ 第一个JSP页面被装载时被创建
+ 一个客户打开到关闭页面称为一个对象
+ HttpSession类


## 内部成员
```
long getCreationTime(); //返回创建时间

String getId();					//返回session唯一ID号

Object setAttribute(String name,Object value);  //使用指定名称绑定此会话

Object getAttribute(String name);			 					//返回与此会话中指定的名称绑定在以前，没有则返回null

String[] getValueNames()  //返回一个SESSION所有可用属性的数组（弃用的）

Enumeration<String> getAttributeNames(); //返回一个SESSION所有可用属性的数组

int getMaxInactiveInterval() //返回两次请求间隔时长此Session,超时就会被取消

HttpSession
```

## 生命周期
活动：

+ 某次通过超链接打开新页面属于同一次会话
+ 只要没有全部关闭，打开新页面属于同一次会话
+ 默认超时时间是30分钟

销毁
1. 调用session,invalidata()方法
2. Session过期（超时）
3. 服务器重启

配置过期时间(单位是分钟)
```xml
<session-config>
<session-timeout>10</session-timeout>
</session-config>		
```

