```sh
npm install socket.io
```

安装后再创建服务端

```js
var io = require('socket.io');
//连接
io.on('connection', function (socket) {
  socket.emit('news', { hello: 'world' });
  socket.on('my other event', function (data) {
    console.log(data);
  });
});
```

