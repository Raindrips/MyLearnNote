# cocos2d-x开发常用控件

本节课教大家知道如何操作和了解cocos2d-x的常用控件

主要介绍内容

+ director
+ sprite
+ scene
+ layer
+ labelTTF
+ menu
+ tableview

## cocos2d环境搭建

[源码网站]:github.com/plter



## 项目

模板文件

>class  导演类
>
>层级类
>



## Sprite 精灵类 



## Direct 导演类

导演类是一个单例对象,通过 `getInstance` 获取

```cpp
auto direct = Director::getInstance();
```

第一次运行,程序用`runWithScene`启动

```cpp
auto scene = Scene::create();		//创建一个场景
director->runWithScene(scene);
```

### Scene 场景类

```cpp
Scene scene=Scene::create();	//场景的创建
auto layer = Layer::create();	//
```



## log

输出日志

使用  `CCLOG` 宏来输出



## MessageBox

```cpp
MessageBox("消息内容","消息框");
```



## Label

label 是文字属性标签,使用createTTF 来创建

```cpp
auto labelttf=LabelTTF::create();	
labelttf->setString("设置文字");
labelttf->setFontSize(36);		//设置字体大小
labelttf->setPosition(20,20);	//设置窗口大小

auto Label=Label::createTTF(); 		//
```

### LabelTTF

## TextFeidTTF

本文输入框,可以输入文字

```cpp
class TextFeidTTF{
    //创建文本
	static TextFeidTTF* textFieldWithPlaceHolder(string input,string font,int size);
    Vec2 getBoundingBox();
    //添加焦点,使文本可以输入
    void attachWithME();
    //移除焦点
    void detachWithME();
    
};
```



## Menu

菜单组建,需要两张图片,一个是按下的状态,一个是没按下的,并需要要回调函数,来表示被按下的状态

```

```







