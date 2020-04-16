## 鼠标点击事件

```c++
//创建鼠标点击类
cocos2d::EventListenerMouse* _lis;
_lis = EventListenerMouse::create();

```

添加点击事件

```c++
//添加鼠标按下信息
_lis->onMouseDown = [this](Event* e){
        _cursor = (_cursor + 1) % 3;
        switch (_cursor) {
            case 1:		//左键按下
                Director::getInstance()->getOpenGLView()->setCursor("InputTest/cursor1.png");
                break;
            case 2:		//右键按下,将锚点设置到中间
                Director::getInstance()->getOpenGLView()->setCursor("InputTest/cursor2.png", Point::ANCHOR_MIDDLE);	
                break;
            default:
                Director::getInstance()->getOpenGLView()->setDefaultCursor();
                break;
        }
    };
//添加鼠标点击事件
_eventDispatcher->addEventListenerWithSceneGraphPriority(_lis, this);


//记得在析构函数上写上停止事件
 _eventDispatcher->removeEventListener(_lis);
```



鼠标的操作消息事件

```cpp
//鼠标消息事件
std::function<void(EventMouse* event)> onMouseDown;

std::function<void(EventMouse* event)> onMouseUp;

std::function<void(EventMouse* event)> onMouseMove;

std::function<void(EventMouse* event)> onMouseScroll;
```



给鼠标设置指定样式

```cpp
Director::getInstance()->getOpenGLView()->setCursor("InputTest/cursor1.png");

//修改成默认的样式
Director::getInstance()->getOpenGLView()->setDefaultCursor();
```

隐藏鼠标和显示鼠标

```cpp
_lis = EventListenerMouse::create();
_lis->onMouseDown = [](Event* e){
    //隐藏鼠标
    Director::getInstance()->getOpenGLView()->setCursorVisible(false);
};

_lis->onMouseUp = [](Event* e){
    //显示鼠标
    Director::getInstance()->getOpenGLView()->setCursorVisible(true);
};
```



