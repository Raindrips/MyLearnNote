# cocos2d中lua与C交互

## Lua 中间栈

调用lua脚本

```c
#include "lua.hpp"

//实例化对象
lua_State* luaState = LuaL_newstate();
luaL_openlibs(luaState);
//读取lua文件
string path=Director::getInstance()->fullPathForFilename("my.lua");
//执行lua文件
LuaL_dofile(luaState,path.c_str());
//调用lua代码
lua_pcall(luaState,0,0,0);
```

### 集成Lua在C项目中

```cpp
class LuaEngine{
    //实现一个单例
    LuaEngine* getInstance();
    luaState;
    //lua初始化
    void init(){
        //创建一个新的状态
        luaState=LuaL_newstate();
        //打开所有系统调用的库
        luaL_openlibs(luaState);
        //打开路径
        string path=Director::getInstance()->fullPathForFilename("config.lua");
        //读取文件
        LuaL_dofile(luaState,path.c_str());
        //启动调用文件
        lua_pcall(luaState,0,0,0);
    }
    void readVar(){
        //读取全局变量
        lua_getglobal(luaState,"var");
        //是否能转换成数值类型 -1 栈顶
        if(lua_isnumber(luaState,-1)){
            //获取变量的值
            int var=lua_tonumber(luaState,-1);
        }
        lua_getglobal(luaState,"str");
        if(lua_isnumber(luaState,-1)){
            //获取变量的值
            int var=lua_tostring(luaState,-1);
        }
    }
    //调用lua函数
    void runFn(){
        //获取变量
        lua_getglobal(luaState,"fn");
        //调用函数
        int err=lua_pcall(luaState,0,0,-1);
        if(err!=-1){
            //DO ERROR   
        }
    }
    
    void get_table(){
        const char* rlt=lua_gettable(luaState,-1);
        //获取表格属性
        getFiled(luaState,"var1");
        lua_pop(L,1);
    }
};
```

## 访问lua中的数据和函数

```cpp
//初始化
lua_State* lua_state=lua_newstate();
luaL_openlibs(lua_state);

//读取全局变量
lua_getglobal(lua_state,"username");

//获取栈中的元素
const char* str=(char*)lua_tostring(lua_state,-1);

//修改读取的变量  12 number
lua_pushnumber(lua_state,12);

//传入c语言的函数
push_cfunction(lua_state,fn)

//调用lua函数
//err -1 表示出错  或返回值的数量
int err=lua_pacll(lua_state,1,1,0);

//出栈
lua_pop(lua_state,2);

lua_Lcheck_int(lua_state,1);
```

## 调用lua函数

```c
 
//调用无参函数
lua_getglobal(lua_state,"fn1");
lua_pcall(lua_state,0,0,-1);

//调用有参函数
lua_getglobal(lua_state,"fn2");
lua_pcall(lua_state,1,0,-1);

//调用无参有返回值的函数
lua_getglobal(lua_state,"fn3");
lua_pcall(lua_state,0,1,-1);

```



## lua调用c

```c

```

lua文件

```lua

```



## 利用lua制作插件

```cpp

```

  