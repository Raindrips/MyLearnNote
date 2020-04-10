TMXTiledMap类
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

关卡层级

```cpp
//层级
class TMXLayer;

//获得层名
string& getLayerSize();

//获得层尺寸,单位瓦片
Size& getMapLayerSize();
//获得瓦片尺寸,单位像素
Size& getMapTileSize();
//通过瓦片坐标获取像素坐标,瓦片坐标y轴是相反的
Vec2 getPositionAt(Vec2& tileCorrdinate);
```

