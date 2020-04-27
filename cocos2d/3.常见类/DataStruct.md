# 数据

## 常用的类

1. `Vec2` 坐标
2. `rect`矩形
3. `size`大小

```cpp
//坐标
Vec2 v1=Vec2(1.0,50);
v1.x;
v2.y;

//矩形
class Rect{
    //
    Rect(float x,float y,float wid,float hei);
	    
};
//大小
class Size{
    Size(float x,float y ){
        
    }
    float height;
    float width;
}


```

## 单例模式

### Director

导演类(单例对象)

```cpp
//获取导演类的单例对象
auto director= Director::getInstance();
```



