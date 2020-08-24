# http 模块

### 使用

```js
//导入该模块
const http = require('http');

//创建服务
let server = http.createServer((req, res)=>{
    res.end('hello, world!');
});

//监听服务
server.listen(3000, '127.0.0.1', ()=>{
    console.log('服务器已经启动!');
    // 5秒后关闭服务器
    setTimeout(()=>{
        // server.close();
    }, 5000);
});

// 监听服务器的关闭
server.on('close', ()=>{
    console.log('服务器已经关闭!');
});

// 监听服务器发生错误
server.on('error', (e)=>{
    if(e.code === 'EADDRINUSE'){
        console.log('端口号被调用!');
    }else {
        console.log('其它的错误', e.code);
    }
});

// 设置超时时间
server.setTimeout(1000, ()=>{
    console.log('设置超时时间为1s');
});

server.on('timeout', ()=>{
    // 超时要做什么操作
    console.log('连接已经超时');
});
```

### http 请求方式

+ GET（完整请求一个资源）
+ POST(提交表单)
+ PUT(上传文件)
+ DELETE(删除)
+ PATCH HEAD(请求响应首部)
+ OPTION 返回请求的资源所支持的方法
+ TRACE 追求一个资源请求中间所经过的代理

### URL

```
<协议>://<主机>:<端口>/<路径>?<数据=数据值>&<...>
```

