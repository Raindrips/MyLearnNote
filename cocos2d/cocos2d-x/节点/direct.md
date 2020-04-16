# Direct类

```cpp
//获取实例对象
auto director = Director::getInstance();

//设置glview
director->setOpenGLView(glview);

 // 显示 FPS
  director->setDisplayStats(true);

// 设置帧率
  director->setAnimationInterval(1.0 / 60);

//
director->setContentScaleFactor();
```



## Glview



```cpp
//设置分辨率
glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
```

