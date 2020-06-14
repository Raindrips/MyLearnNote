# Sprite 精灵类

**精灵(Sprite)** 是一个能通过改变自身的属性：角度，位置，缩放，颜色等，变成可控制动画的 2D 图像。

```c++
class Sprite{
    //创建一个精灵对象
    static Sprite* create();
   
    //从文件中创建一个精灵对象
    static Sprite* create(string& filename);

    //从文件中创建一个精灵对象,指定纹理裁剪精灵
    static Sprite* create(string& filename,Rect &rect);
    
     //指定创建的裁剪区域 rotated 是否旋转纹理
    static Sprite *create(string &filename,Rect &rect,bool rotated=false);
};
```

创建一个精灵对象,通过`addChild`来显示

**纹理:**按照特定的贴图映射到物体,使精灵看起来更加真实

```cpp
//指定纹理创建精灵
static Sprite* createWithTexture(Texture2D *texture);

//指定纹理裁剪精灵,默认不旋转
static Sprite* createWithTexture(Texture2D *texture,Rect &rect,bool rotated=false);

//通过精灵帧创建精灵对象
static Sprite* createWithFrame(SpritehFrame *sf);

//通过帧缓存创建精灵帧对象
static Sprite* createWithFrameName(string& sf);
```



### 纹理图(Texture2D)

纹理图集,可以提前加载图片,在使用的时候在通过精灵创建,可以提高程序的运行效率,如果有许多重复的精灵被创建,也可以使用纹理图集来节省内存空间

```cpp
//添加纹理图
auto direct = Director::getInstance();
auto texture2d = direct->getTextureCache()->addImage(string& filename);
```

例:

```cpp
//创建texture
auto t2d = Director::getInstance()->getTextureCache()->addImage("");
```



### 精灵帧缓存(TextureCache)

`TextureCache`,

能够从精灵表中创建精灵帧缓存,可以节省内存消耗,缓存文件的格式通常是`plist`文件,

```cpp
//从.plist 文件中创建精灵帧缓存
SpriteFrameCatche::getInstance()->addSpriteWithFile(string& filename);
```

精灵帧不用的时候就要移除

```cpp
//移除所有精灵帧缓存
void removeSpriteFream();

//移除指定的精灵帧缓存
void removeSpriteFreamByName(string &Name);

//移除plist精灵帧
void removeSpriteFramesFromFile(string& name);

//移除没有使用的精灵帧
void removeSpriteUnusedSpriteFrame(string& plist);
```

#### 图集

**图集(Sprite Sheet)** 是通过专门的工具将多张图片合并成一张大图,并通过 plist 等格式的文件索引的资源，使用图集比使用多个独立图像占用的磁盘空间更少，还会有更好的性能。

将所有图集(.plist文件)加入到精灵帧缓存,缓存了添加到其中的 `SpriteFrame` 对象，提高了精灵的访问速度

```cpp
// 获取到 SpriteFrameCache 的实例
auto spritecache = SpriteFrameCache::getInstance();
// 把图集添加到实例中。
spritecache->addSpriteFramesWithFile("sprites.plist");
```

#### 图层打包工具:

+ Texture Packer(部分收费)
+ Zwoptex(MAC)
+ ShoeBox
+ [bigshear](https://www.fancynode.com.cn/bigshear)
+ Sprite Sheet Packer(免费)

##### Sprite Sheet Packer

一个在线的编辑工具,可以直接在网站上编辑,使用简单,免费

[网站地址](https://www.codeandweb.com/free-sprite-sheet-packer)

##### Texture Packer

图层打包工具,有免费和专业两个版本

## 批量绘制(SpriteBatchNode)

SpriteBatchNode 批处理绘制,可以将相同的精灵文件共享一个图片对象,这样可以节省绘制的调用时间

类似于一个批处理节点:如果它包含子节点，它将在一个单独的OpenGL调用中绘制它们。

```cpp
class SpriteBatchNode{
    
};
```

## 

## 精灵的使用

创建精灵：

```cpp
auto mySprite = Sprite::create("mysprite.png");
```

### 锚点

锚点是距离中心点的一个相对位置

默认情况下，所有的节点对象锚点是 (0.5, 0.5),

设置锚点：

```cpp
//默认锚点,中心位置
mySprite->setAnchorPoint(0.5, 0.5);

//左下
mySprite->setAnchorPoint(0, 0);

// 左上
mySprite->setAnchorPoint(0, 1);

//右下
mySprite->setAnchorPoint(1, 0);

// 右上
mySprite->setAnchorPoint(1, 1);
```

### 位置

每个精灵节点都有各自的位置,坐标位置从左下角开始,向右上角延伸

通常想改变一个精灵的位置是,应该使用的是`setPosition()`函数,只有在改变精灵与基准坐标点的相对位置时，才考虑使用 `setAnchorPoint()` 设置锚点	

```cpp
//给一个精灵设置坐标,位置为x=100 y=200
mySprite->setPosition(Vec2(100, 200));
```

### 旋转

通过 `setRotation()` 方法，设置一个角度值可以控制精灵的旋转，正值精灵顺时针旋转，负值精灵逆时针旋转，默认位置的角度值是 0.0。

```cpp
// 顺时针旋转 +60 degrees
mySprite->setRotation(60.0f);

//逆时针旋转 by -60 degrees
mySprite->setRotation(-60.0f);
```

### 缩放

通过 `setScale()` 方法控制精灵的缩放。可以控制精灵水平缩放，垂直缩放，也可以整体缩放。默认水平和竖直的缩放值都是 1.0。

```cpp
//放大1倍
mySprite->setScale(2.0);

// x轴拉伸1倍
mySprite->setScaleX(2.0);

// Y轴拉伸1倍
mySprite->setScaleY(2.0);
```

### 倾斜

通过 `setSkewX()` 控制精灵的倾斜度，可以控制精灵水平倾斜，竖直倾斜，或者水平竖直同时倾斜，默认水平和竖直的倾斜值都是 0.0。

```cpp
// adjusts the X skew by 20.0
mySprite->setSkewX(20.0f);

// adjusts the Y skew by 20.0
mySprite->setSkewY(20.0f);
```

### 颜色

通过 `setColor()` 控制精灵的颜色。将一个 *RGB* 值设置到 `Color3B` 对象，调用精灵的 `setColor()` ，就能完成精灵颜色的设置。*RGB* 是三个从 0-255 的值，三个值分别代表红绿蓝的颜色深度，数值越大，颜色越深。特别的 RGB(255, 255, 255) 是白色。如果你不想自己指定 *RGB* 的三个值，也可以使用 Cocos2d-x 提供的预定义颜色，比如: `Color3B::White`，`Color3B::Red`。

```cpp
// set the color by passing in a pre-defined Color3B object.
mySprite->setColor(Color3B::WHITE);

// Set the color by passing in a Color3B object.
mySprite->setColor(Color3B(255, 255, 255)); // Same as Color3B::WHITE
```

### 透明度

精灵的透明度可以通过 `setOpacity()` 传入一个特定的值来设置，这个值的范围是 0-255，数值越大透明度越低，255 代表完全不透明，0 代表完全透明。

```cpp
// Set the opacity to 30, which makes this sprite 11.7% opaque.
// (30 divided by 256 equals 0.1171875...)
mySprite->setOpacity(30);
```

# 多边形精灵

**多边形精灵(Polygon Sprite)** 也是一个精灵，同样是为了展示一个可以被控制的图像，但是和普通精灵的区别是，普通精灵在绘图处理中被分为了两个三角形，多边形精灵则是被分为了一系列三角形。

## 为什么要使用多边形精灵

**提高性能**!

要深入分析这个是如何提高性能的，会需要很多和像素填充率有关的技术术语。幸好本节是入门性质的文档，能让大家理解多边形精灵比普通精灵性能好就可以了，不用讨论特定宽高矩形绘制时的性能问题。

## AutoPolygon

**`AutoPolygon`** 是一个工具类，它可以在程序运行时，通过跟踪关键点和三角测量，将一个矩形图像划分成一系列小三角形块。

首先将图像资源传入 `AutoPolygon` 进行处理，然后我们使用它生成的对象进行精灵的创建就能得到多边形精灵。

```cpp
// Generate polygon info automatically.
auto pinfo = AutoPolygon::generatePolygon("filename.png");

// Create a sprite with polygon info.
auto sprite = Sprite::create(pinfo);
```