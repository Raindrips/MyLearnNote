# SDL概述

一个开源多媒体开发库,支持

+ 视频
+ 音频
+ I/O交换
+ 计时器
+ 线程

## SQL2新功能

+ 硬件加速绘图
+ 多窗口

## 使用SQL

头文件

```c
#include <SDL2/SDL.h>
```

声明窗口变量

```cpp
//窗口
SDL_Windows* windows=NULL;
//窗口表面
SDL_Surface* surface=NULL;
```

初始化

```cpp
//初始化
SDL_Init(SDL_INIT_VIDEO);
```

初始化方法

| 初始化事件              | 操作           |
| ----------------------- | -------------- |
| SDL_INIT_TIMER          | 计时子系统     |
| SDL_INIT_AUDIO          | 音频系统       |
| SDL_INIT_VIDEO          | 视频系统       |
| SDL_INIT_JOYSTICK       | 控制杆系统     |
| SDL_INIT_GAMECONTROLLER | 控制器子系统   |
| SQL_INIT_EVENTS         | 事件子系统     |
| SQL_INIT_ECERYTHING     | 所有的子系统   |
| SQL_INIT_NOPAPRACHUTE   | 不捕获致命信息 |

创建窗口

```c
//窗口名称
//中心位置
//窗口大小
//窗口模式
windows=SDL_CreateWindow("SDL_Window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,240,400,SDL_WINDOWS_SHOW);
if(windows==NULL) return -1;
surface=SDL_GetWindowsSurface(Window);
if(surface==NULL)return -2;

```

清理窗口

```c
SDL_FreeSurface(surface);
SDL_DestoyWindows(windows);
SDL_Quit();
```

使用一个简单的例子

```c
//填充颜色
SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format),0xFF,0xcc,0x99));
```

使用结构体

```c
struct SDL_Rect{
    int x,y;
    int w,h;
};
```

更新窗口

```c
SDL_UpdateWindowsSurface(window);
SDL_Delay(200);

Destroy();
```





