# Lua

## 环境搭建

[官方下载网站](http://www.lua.org/download.html)

下载后解压压缩文件,`src`目录下就是源代码

+ `lua.c`文件	启动命令窗口
+ `luac.c`文件  命令执行文件

编译时报错，原因，`lua.c`文件和`luac.c`文件有两个main方法，需要注释一个才能运行

 ## C语言调用代码

```c

/*执行lua代码
@s 要执行的代码
@name 名字
*/
void dostring(L,const char *s, const char *name)
//执行lua文件
int dofile(L, const char *name);
```

## 获取LUA的全局变量

```c
//获取全局变量
int lua_getglobal (lua_State *L, const char *name);

//判断是否是字符串
int lua_isstring (lua_State *L, int idx);
    
//判断是否是数字    
int lua_isnumber (lua_State *L, int idx);

/*获取属性名
idx 元素栈
k 属性名
*/
int lua_getfield(lua_State *L, int idx, const char *k);
/*调用函数
n 参数
r 返回参数
*/
int lua_call(L,n,r);

//添加参数
const char *lua_pushstring (lua_State *L, const char *s);
```



## LUA语言调用C语言代码

```cpp
lua_register("函数名",函数);
lua_register(L, "HelloC",HelloC);	//注册函数
```



## 交互机制

```
参数用栈的形式存储
索引从1开始
反向从-1开始
```

