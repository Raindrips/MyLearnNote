# TypeScript 安装

使用`node.js`安装

```sh
npm install -g typescript
```

查看版本号

```sh
tsc -v
```

第一行代码,保存格式为`hello.ts`

```cpp
var message:string = "Hello World" 
console.log(message)
```

执行代码,该命令会将`ts`转换为`js`代码

```
tsc hello.ts
```

