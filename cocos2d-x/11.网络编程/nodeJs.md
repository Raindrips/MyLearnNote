## Node.js

Node.js是一个以JavaScript驱动的服务端,可以搭建一个简单的服务器

[下载地址](https://nodejs.org/zh-cn/)

## 启动node.js

创建`app.js`文件

```js
var http=require('http');
http.createServer(
	function(req,res){
        res.writeHead(200,{'content-Type':'text/plain'});
        res.end('Hello World');
    }
    
).listen(3000,'127.0.0.1');
```

该程序创建了一个`http`服务,然后监听`3000`端口,注意代码用`utf-8`的编码保存

然后启动服务器

```sh
node app.js
```

启动之后就可以在浏览器中访问了,在浏览器中输入地址

```
http://127.0.0.1:3000/
```

## 使用Socket.io

如果要使用`socket.io`需要安装该模块

```sh
npm install socket.io
```

通过socket.io启动服务器

```js
//引入socket.io模块并监听3000端口
var io=require('socket.io').listen(3000);
console.log('Server on port 3000');
io.sockets.on('connection',function(socket)
{
    //向客户端发送消息
	socket.send('Hello');
    //注册message事件
    socket.on('message',function(data){
        console.log(data)
    });
    //连接事件
    socket.on('connect',function(){
        console.log("connect client");
    })
    //注册callServerEvent事件,便于客户端调用
    socket.emit('callServerEvent',{message:'hello client'});
});
```

### Sock.io事件功能

```
connect		连接事件
disconnect	断开连接事件
reconnect	重新连接事件
close	连接关闭事件
error	错误发生事件
retry	重新尝试连接
message	接收消息事件
```

## cocos2d中的Socket.io客户端

使用步骤如下

1. 在解决方案中添加`libNetWork`库工程
2. 添加`libNetWork`引用
3. 配置头文件搜索路径
4. 配置附件依赖项

### 使用SocketIO

导入头文件

```cpp
#include <network/SocketIo.h>
using namespace cocos2d::network;
```

虚基类`SocketIO::SIODelegate`,可以进行重写并使用

```cpp
//this 是继承SIODelegate`的对象
SIOClient *sioClient=SocketIO::connect("http://localhost:3000/",*this);

//注册事件
sioClient->on("callClientEvent",CC_CALLBACK_2(HelloWorld::callClientEvent,this));

//向服务器发送消息
sioClient->send("sioClient");

//触发服务器事件
sioClient->emit("callServerEvent","{'message':'hello Server'}");
```



### Socket.io服务器端开发

```js
var io=require('socket.io').listen(3000);

//设置监听事件
io.sockets.on(function(socket){
    socket.on('findAll',function(data){

    });
    socket.on('create',function(data){

    });
    socket.on('remove',function(data){

    });
    socket.on('motifiy',function(data){

    });
});
```

## Node.js访问数据库

安装`sqlite3`

```sh
npm install sqlite3
```

初始化数据库

```js
var sqlite3=require('sqlite3');
//初始化数据库
var db=new sqlite3.Database('data.sqlite3');
db.run("create table Note_tb(n_id int,cdata text)");
db.close();
```



