 # UI

## 视频播放组件(VideoPlayer)

需要导入命名空间

```cpp
using cocos2d::experimental::ui;
```

创建视频播放器组件

```cpp
//创建
auto vp=VideoPlayer::create();
//设置屏幕大小
vp->setContentSize(vsize);
//设置播放文件
vp->setFileName("vidio.mp4");

//不要忘记添加到场景中了
addChild(vp);

//播放
vp->play();


```



## 网络组建(WebView)

需要导入命名空间

```cpp
using cocos2d::experimental::ui;
```

使用网络组建

```cpp
auto wv=WebView::create();
//设置大小
wv->setConentSize();
//设置网页
wv->loadURI("http://www.baidu.com");
```

