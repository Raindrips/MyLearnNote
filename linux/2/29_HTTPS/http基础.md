## Http基础

HTTP URI 格式

```js
"http:" "//" host [ ":" port ] [ abs_path [ "?" query ]]
host: 主机名
port: 端口号，默认为80
abs_path: 路径
query: 查询串
```

判断HTTP URI是否匹配时必须按照大小写敏感的原则逐一字节地进行比较

+ 端口号为空或者未给出的默认为80
+ host不区分大小写
+ 协议需要区分大小写，http与HTTP不同(不过IE会转换成小写的)
+ abs_path为空相当于 ”/”
+ 不属于“保留”或者“不安全”的字符相当于 “%HEX HEX”格式的编码

### 使用http uri访问的过程




1. 浏览器分析uri，向DNS请求解析URL的IP地址
1. DNS返回IP为1.2.3.4
1. 浏览器与服务器(1.2.3.4)建立TCP连接
1. 浏览器发取文件命令： 
            GET /index.html
            Host: www.chinanetcenter.com
1. 服务器给出响应
1. 释放TCP连接

### HTTP 的请求报文结构

![image-20200806230027581](http%E5%9F%BA%E7%A1%80.assets/image-20200806230027581.png)

1. 请求行
1. 头部行
1. 实体主体

例子

```json
GET /js/an.js HTTP/1.1               #请求行
Accept: */*
Accept-Encoding: gzip, deflate
Accept-Language: zh-cn             #请求头部行
Connection: Keep-Alive
Host: cache.soso.com
Referer: http://help.soso.com/
User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727; InfoPath.2)

```











| 方法（操作） | 意义                             |
| ------------ | -------------------------------- |
| OPTION       | 请求一些选项的信息               |
| GET          | 请求读取由 URL所标志的信息       |
| HEAD         | 请求读取由 URL所标志的信息的首部 |
| POST         | 给服务器添加信息（例如，注释）   |
| PUT          | 在指明的 URL下存储一个文档       |
| DELETE       | 删除指明的 URL所标志的资源       |
| TRACE        | 用来进行环回测试的请求报文       |
| CONNECT      | 用于代理服务器                   |

### 其他请求域

If-Modified-Since： 判断是否修改
Range                ： 部分请求
Cookie                ： Cookie



### 响应报文结构

响应报文的开始行是状态行。
状态行包括三项内容，即 HTTP 的版本，状态码，以及解释状态码的简单短语。 

```
HTTP/1.1 200 OK                                #状态行
Accept-Ranges: bytes
Cache-Control: max-age=86400
Content-Encoding: gzip                            #响应头部行
Content-Length: 1088
Content-Type: text/javascript
Date: Thu, 18 Jun 2009 15:47:14 GMT
ETag: “1902284250“                             
Expires: Fri, 19 Jun 2009 15:47:14 GMT
Last-Modified: Fri, 10 Oct 2008 04:13:19 GMT
Server: WS CDN Server
Vary: Accept-Encoding

```

状态码,都是3个数字

```
1xx 表示通知信息的，如请求收到了或正在进行处理。
2xx 表示成功，如接受或知道了。
3xx 表示重定向，表示要完成请求还必须采取进一步的行动。
4xx 表示客户的差错，如请求中有错误的语法或不能完成。
5xx 表示服务器的差错，如服务器失效无法完成请求。
```

常见的状态码

```
200 OK
206 Partial Content
301 Moved Permanently
302 Found
304 Not Modified
400 Bad Request
403 Forbidden
404 Not Found
502 Bad Gateway
503 Service Unavailable
504 Gateway Timeout 
```

响应头

```json
HTTP/1.1 200 OK                                #状态行
Accept-Ranges: bytes                         #表示服务器端可以接受range请求
Cache-Control: max-age=86400         #缓存控制时间
Content-Encoding: gzip                       #内容编码格式
Content-Length: 1088                          #内容长度
Content-Type: text/javascript               #内容类型
Date: Thu, 18 Jun 2009 15:47:14 GMT #时间
ETag: “1902284250“                             #实体标签
Expires: Fri, 19 Jun 2009 15:47:14 GMT  #过期时间
Last-Modified: Fri, 10 Oct 2008 04:13:19 GMT #最后修改日期
Server: WS CDN Server                           #Server名称
Vary: Accept-Encoding  #告知该响应缓存时取决的方式
```

