

# TypeScript 入门



## 安装

1. 安装[nodejs](https://nodejs.org/zh-cn/)

1. 使用`node.js`安装,输入cmd命令

   ```sh
   npm install -g typescript
   ```

1. 测试是否安装成功

   ```sh
   # typescript命令
   tsc  
   ```

1. 编译成`javascript`

   ```sh
   #将ts 编译成js
   tsc demo.ts
   ```

## 使用

查看版本号

```sh
tsc -v
```

第一行代码,保存格式为`hello.ts`

```ts
let message:string = "Hello World" 
console.log(message);
```

执行代码,该命令会将`ts`转换为`js`代码

```
tsc hello.ts
```




