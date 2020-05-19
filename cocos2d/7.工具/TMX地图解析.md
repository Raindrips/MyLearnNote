# TMXTiledMap类

```cpp
//1.tmx文件,从一个文件中创建
static TMXTiledMap* create(string path);
```

常用方法

```cpp
//1.获取层对象
TMXlayer* getLayer(string layer);

//获取地图尺寸
Size& getMapSize();
//获取瓦片尺寸
Size& getTileSize();
//通过对象层名获取对象组合
TXMObjectGroup *getObjectGroup(string& groupName);
```



### 图层属性

关卡层级

```cpp
//层级
class TMXLayer{
    //获得层名
    string& getLayerSize();
    //获得层尺寸,单位瓦片
    Size& getMapLayerSize();
    //获得瓦片尺寸,单位像素
    Size& getMapTileSize();
    //通过瓦片坐标获取像素坐标,瓦片坐标y轴是相反的
    Vec2 getPositionAt(Vec2& tileCorrdinate);
}
```



# TMXTiledMap

```cpp
//创建TMXTiledMap
//tmxFile 文件路径
TMXTiledMap * TMXTiledMap::create(const std::string& tmxFile);
```

TMXTiledMap类的一些成员变量

```cpp
class TMXTiledMap{
    //获取类型
    Sprite* getTileAt(Vec& vec);
}
```





将地图文件显示在屏幕中，使用addChild 添加节点就可以了

```cpp
//示例
auto map = TMXTiledMap::create("TileMaps/iso-test-zorder.tmx");
addChild(map, 0, kTagTileMap);

```



## 实现鼠标拖动效果

```cpp
auto diff = touch->getDelta();
auto node = getChildByTag(kTagTileMap);
auto currentPos = node->getPosition();
node->setPosition(currentPos + diff);
```



# TMX地图解析

## TMXTiledMap

```cpp
class TMXTiledMap{
	static TMXTiledMap* create();
    //获取地图的属性
    Value getProPerties();
    
    //获取图层属性
    TXMLayer* getLayer(const char*);
}
```



### 组属性



## 加载地图

```cpp
//获取图层属性
auto layer=txmMap->getLayer("Scene");
auto value=layer->getProPerties();

//获取图块属性
auto tilePro=txmMap->getProPertiesForGID(1).asValueMap();

//获取对象属性
auto objectGroup=map->getObjectGroup("object");
auto obj=objectGroup->getObject("player");
```

## 根据地图对象操作地图

```cpp

auto color=objectGroup->getObject("color");
auto X=color["x"].asInt()/32;
auto Y=
```

