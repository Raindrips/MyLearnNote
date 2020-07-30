# TMX瓦片地图

## TMXTiledMap类

创建TMXTiledMap对象,从txm文件中读取

```cpp
//从一个文件中创建 tmxFile 文件路径
static TMXTiledMap* create(string path);
```

要将地图文件显示在屏幕中，使用addChild 添加节点就可以了

```cpp
//示例
auto map = TMXTiledMap::create("TileMaps/iso-test-zorder.tmx");
addChild(map, 0, kTagTileMap);
```

TMXTiledMap类的一些成员变量和常用方法

```cpp
class TMXTiledMap{
    static TMXTiledMap* create();
    //获取地图的属性
    Value getProPerties();

    //通过对象层名获取对象组合
    TXMObjectGroup *getObjectGroup(string& groupName);

    //获取图层属性,层对象
    TMXlayer* getLayer(string layer);

    //获取地图尺寸
    Size& getMapSize();

    //获取瓦片尺寸
    Size& getTileSize();

    //获取指定位置的精灵图层
    Sprite* getTileAt(Vec& vec);
}
```



## 图层属性

关卡层级`TMXLayer`,通常从`TMXTiledMap`对象中获取,

```cpp
//通过层名获取层级对象
auto layer=tileMap->getLayer("LayerName");
```

图层的一些常用方法

```cpp
//层级
class TMXLayer{
    //获得层名
    string& getLayerName();
    //获得层尺寸,单位瓦片
    Size& getMapLayerSize();
    //获得瓦片尺寸,单位像素
    Size& getMapTileSize();
    //通过瓦片坐标获取像素坐标,瓦片坐标y轴是相反的,在工具中可以进行修改
    Vec2 getPositionAt(Vec2& tileCorrdinate);
    //通过瓦片坐标获取GID值
    int getProPertiesForGID(Vec2& tileCorrdinate)
}
```

加载地图层级

```cpp
//获取图层属性
auto layer=txmMap->getLayer("Scene");
//获取图层属性
auto value=layer->getProPerties();

//通过GID获取图块属性
auto tilePro=txmMap->getProPertiesForGID(1).asValueMap();

//获取对象属性
auto objectGroup=map->getObjectGroup("object");
auto obj=objectGroup->getObject("player");
```



## 组属性

字段名:`TMXObjectGroup`

从地图对象中获取获取对象层,组层通常存储对象

```cpp
TMXObjectGroup* group = tmxTiledMap->objectGroupNamed("object");
```

遍历所有对象

```cpp
for (auto it = objects.begin();it != objects.end(); it++)
{
    //从每个对象中获取map数据
	const ValueMap& dict = (*it).asValueMap();
}
```

组的常见属性

```cpp
class TMXObjectGroup{
    //通过属性名获取组属性
    Value getProperty(string name);
    
    //通过对象名,获取对象信息
    ValueMap getObject();
    
    //获取所有对象属性
    ValueVector GetObjects();
    
    //获取所有对象
    ValueMap getProperties();
    
    
}
```



## 常见操作

根据地图对象操作地图

```cpp
auto color=objectGroup->getObject("color");
auto X=color["x"].asInt()/32;
auto Y=color["y"].asInt()/32;
```



### 实现鼠标拖动效果

```cpp
auto diff = touch->getDelta();
auto node = getChildByTag(kTagTileMap);
auto currentPos = node->getPosition();
node->setPosition(currentPos + diff);
```



### 读取TMX对象

```cpp
auto map = TMXTiledMap::create("res/1.tmx");
auto size = Director::getInstance()->getVisibleSize();
auto layer = map->getLayer("1");
addChild(map, 0, 1); // with a tag of '99'

//创建节点
Node *node = Node::create();
node->setContentSize(Size(10, 10));
//添加节点
this->addChild(node, 0, 123);  //123 是 tag
//查找节点
Node *temp_node = this->getChildByTag(123);
//移除节点，并停止节点的一切动作
this->removeChildByTag(123, true);
```

## 地图编辑器

[tilemap](http://mapeditor.org)编辑器,是一个免费开源的软件,里面提供了地图编辑功能

### 新建地图

+ 地图方向
+ 渲染格式
+ 图块顺序

### 导入图片

选择源文件

新建->图块集

### 图层

属性图层的创建和地图编辑,多张图层可以在同一个坐标位置上显示,也可以很好的给地图分类

### 对象

对象的创建和编辑,对象是不受地图限制的,通常是玩家,敌人等动态物体



