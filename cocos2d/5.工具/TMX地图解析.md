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



### 图层属性

```cpp
 class TXMLayer{
 	
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

