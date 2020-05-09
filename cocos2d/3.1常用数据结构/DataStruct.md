# 数据

Cocos2d-x 是一个游戏引擎,内部封装了游戏的常用引擎接口,代码风格充分的利用了面向对象编程的特性,使用户在使用的过程非常方便和轻松

## 常用的类

1. `Vec2` 坐标
2. `rect`矩形
3. `size`大小

```cpp

//大小

```

# 坐标系统

cocos2d-x 的坐标系统

## 屏幕坐标系

X轴是从左向右的

Y轴从上往下

 `````````````
------------------------------>X
|
|
|
|
|
v
Y
 `````````````



## 坐标函数

```c++
//获取坐标锚点  默认是0.5
Vec2 getAnchorPoint();


//获取坐标位置,默认0,0;
Vec2 getPosition();
```



### 二维向量

类名:`Vec2`

里面实现了二维坐标系常用函数,使得使用起来非常轻松

```cpp
//坐标
class Vec2{
    float x;
    float y;
	Vec2();
	Vec2(float x,float y);   
}
```

### 矩形

类名:Rect

```



//矩形
class Rect{
    Rect(float x,float y,float wid,float hei);
};
```

###  大小

类型:Size

```cpp
//大小
class Size{
    float height;
    float width;
	Size(float wid,float hei );
};
```


