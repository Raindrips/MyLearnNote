# Paint类

`QPainter`类,通过继承的`paintEvent()`中进行调用

```cpp
class Qpainter{
    //画线
    void drawLine();
    
};
```

坐标位置是从左上角开始绘制的(0,0)

## 画笔

`QPen`使用的线条,改变绘制的方式

```cpp
//创建画笔
QPen pen(Qt::green, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
//使用画笔
painter.setPen(pen);
```



