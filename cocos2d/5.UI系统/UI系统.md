## UI系统



+ labelTTF
+ menu
+ tableview

# cocos2d-x开发常用控件



## 文字标签

1. Label   文字标签
2. ~~LabelTTF~~  系统字体文字(已弃用)
3. ~~BMFont~~ 位图字体文字(已弃用)

## label

label 是文字属性标签,使用createTTF 来创建

```cpp
auto labelttf=LabelTTF::create();	
labelttf->setString("设置文字");
labelttf->setFontSize(36);		//设置字体大小
labelttf->setPosition(20,20);	//设置窗口大小

auto Label=Label::createTTF(); 		//
```

Label类常用的函数

```cpp
class Label{
    //LabelTTF 文字类
    static Label* createWithTTF(String& text,string& font,int size);
    
    //创建一个BMfont 文字对象
    static Label* createWithBMFont("bitmapRed.fnt", "Your Text");
    // 阴影效果
    void enableShadow();
    //描边效果 颜色 粗细
    enableOutline(Color4B& color,int line));
    //发光效果
    void enableGlow();
}
```

配置文字对象,使用`LabelConfig`来进行配置.

```cpp
// create a TTFConfig files for labels to share
TTFConfig labelConfig;
labelConfig.fontFilePath = "myFont.ttf";
labelConfig.fontSize = 16;
labelConfig.glyphs = GlyphCollection::DYNAMIC;
labelConfig.outlineSize = 0;
labelConfig.customGlyphs = nullptr;
labelConfig.distanceFieldEnabled = false;

// 通过LabelConfig来创建Label
auto myLabel = Label::createWithTTF(labelConfig, "My Label Text");
```

### 

### TextFeidTTF

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



### LabelTTF

```cpp
class LabelTTF{
	createWithString(String& text,string& font);
}
```

### BMFont

位图字体文字,通过位图创建字体

### 文本框(TextFaield)

文本框对象

```cpp
#include "ui/CocosGUI.h"
//创建一个文本框
auto textField = TextField::create("","Arial",30);
//文本框设置监听事件
textField->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
                std::cout << "editing a TextField" << std::endl;
});
//添加文本对象
this->addChild(textField);

// make this TextField password enabled
textField->setPasswordEnabled(true);

// set the maximum number of characters the user can enter for this TextField
textField->setMaxLength(10);

```



## 菜单(Menu)

```cpp
class Menu{
    //创建
    Menu* static create(); 

    //创建一个菜单键
    Menu* create(string normal, string close, schedule_selector schedule);
}
```

菜单组建,创建一个图片按钮,需要两张图片,一个是按下的状态,一个是没按下的,并需要要回调函数,来表示被按下的状态

```cpp
auto m=MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(ListScene::menuCloseCallback, this));
auto menu = Menu::create();
//添加入菜单
menu->addChild(m);
```

创建多个菜单

```cpp
// creating a Menu from a Vector of items
Vector<MenuItem*> MenuItems;

/* repeat for as many menu items as needed */
for(auto& e:MenuItems){
    MenuItems.pushBack(menuitem);
}

//菜单
auto menu = Menu::createWithArray(MenuItems);
this->addChild(menu, 1);
```



## 按钮(Button)

头文件

```cpp
#include "ui/CocosGUI.h"
```

创建三个按钮按钮

```cpp
//普通样式,选择样式,关闭样式
auto button = Button::create("normal_image.png", "selected_image.png", "disabled_image.png");
//设置按钮样式
button->setTitleText("Button Text");

//添加点击事件
button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            std::cout << "Button 1 clicked" << std::endl;
            break;
    }
});
this->addChild(button);
```

## 复选框(checkbox)

```cpp
//普通 被点击 不可用 被选中 选中不可用 
auto checkbox = CheckBox::create("check_box_normal.png",
                                 "check_box_normal_press.png",
                                 "check_box_active.png",
                                 "check_box_normal_disable.png",
                                 "check_box_active_disable.png");

checkbox->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            std::cout << "checkbox 1 clicked" << std::endl;
            break;
    }
});

this->addChild(checkbox);
```







## 进度条(LoadingBar)

设置一个进度条,向右填充

```cpp
auto loadingBar = LoadingBar::create("LoadingBarFile.png");

// set the direction of the loading bars progress
loadingBar->setDirection(LoadingBar::Direction::RIGHT);

this->addChild(loadingBar);

// something happened, change the percentage of the loading bar
loadingBar->setPercent(25);

// more things happened, change the percentage again.
loadingBar->setPercent(35);
```

## 滑动条(Slider)

```c++
auto slider = Slider::create();
slider->loadBarTexture("Slider_Back.png");
slider->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
slider->loadProgressBarTexture("Slider_PressBar.png");

slider->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            std::cout << "slider moved" << std::endl;
            break;
    }
});

this->addChild(slider);
```



## 计时器

### schedule

```cpp
//每帧执行代码
schedule(schedule_selector(&类名::函数名));
```

## MessageBox

消息显示框

```cpp
MessageBox("消息内容","消息框");
```



