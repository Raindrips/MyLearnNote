# 精灵



创建一个精灵对象,通过`addChild`来显示

```c++
//创建一个精灵对象
static Sprite* create();

//从文件中创建一个精灵对象
static Sprite* create(string& filename);

//从文件中创建一个精灵对象,指定纹理裁剪精灵
static Sprite* create(string& filename,Rect &rect);
```

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



### Texture2D

纹理图集

```cpp
//添加纹理图
Director::getInstance()->getTextureCache()->addImage(string& filename);
```

### 精灵帧缓存

`TextureCache`

能够从精灵表中创建缓存,可以节省内存消耗

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



# SpriteBatchNode

SpriteBatchNode类似于一个批处理节点:如果它包含子节点，它将在一个单独的OpenGL调用中绘制它们(通常称为“批处理绘制”)。

SpriteBatchNode只能引用一个纹理(一个图像文件，一个纹理图集)。只有包含在纹理中的精灵才能添加到SpriteBatchNode中。所有添加到SpriteBatchNode的精灵都是在一个OpenGL ES draw调用中绘制的。如果SpriteBatchNode中没有添加sprite，那么每个SpriteBatchNode都需要一个OpenGL ES draw调用，这样效率会降低。

限制:

唯一被接受为子对象(或孙子辈、孙子辈等等)的对象是Sprite或Sprite的任何子类。粒子、标签和图层不能添加到SpriteBatchNode中。

它的所有子元素不是别名就是反别名。不可能是混合的。这是因为“alias”是纹理的属性，所有精灵共享相同的纹理。





