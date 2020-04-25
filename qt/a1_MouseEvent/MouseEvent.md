## 鼠标事件

头文件 <QMouseEvent>

globalPos() ：获取全局位置

*this*->frameGeometry().topLeft();//获取窗口左上角坐标

- **鼠标事件**

```
protected:
    virtual void mousePressEvent(QMouseEvent *event);//鼠标按下事件
    virtual void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    virtual void mouseDoubleClickEvent(QMouseEvent *event)//鼠标双击事件
    virtual void wheelEvent(QWheelEvent *event)//滚轮事件
```

- **鼠标事件**

```
protected:
    virtual void mousePressEvent(QMouseEvent *event);//鼠标按下事件
    virtual void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    virtual void mouseDoubleClickEvent(QMouseEvent *event)//鼠标双击事件
    virtual void wheelEvent(QWheelEvent *event)//滚轮事件
```

鼠标重写事件

```
public:
    void mouseMoveEvent(QMouseEvent *event);
 ***********************************************************
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    //event鼠标按下记录x坐标y坐标
    int x=event->x();
    int y=event->y();
    m_hero.setPosition(x,y);
}
//飞机大战的越界判断
if(x<=0)
    {
       x=0;
    }
    if(x>=窗口宽度-图片宽度)
    {
        x=窗口宽度-图片宽度;
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=窗口高度-图片高度)
    {
        y=窗口高度-图片高度;
    }
```

**设置鼠标穿透**

```
label->setAttribute(Qt::WA_TransparentForMouseEvents);
```

**打印窗口坐标位置**

```
qDebug()<<e->pos();
```

**鼠标点击事件**

```
protected:
    virtual void mousePressEvent(QMouseEvent *event);//鼠标按下事件
    virtual void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    virtual void mouseDoubleClickEvent(QMouseEvent *event)//鼠标双击事件
    virtual void wheelEvent(QWheelEvent *event)//滚轮事件
void Widget::mousePressEvent(QMouseEvent *event)
{
     if(event‐>button() == Qt::LeftButton)
     {
         qDebug() << QStringLiteral("鼠标左键按下");
     }
     else if(event‐>button() == Qt::RightButton)
     {
         qDebug() << QStringLiteral("鼠标右键键按下");
     }
     else if(event‐>button() == Qt::MiddleButton)
     {
         qDebug() << QStringLiteral("鼠标中键键按下");
     }
 }
 ***************************************************************
  void Widget::mouseReleaseEvent(QMouseEvent *event)
 {
    if(event‐>button() == Qt::LeftButton)
     {
         qDebug() << QStringLiteral("鼠标左键释放");
     }
     else if(event‐>button() == Qt::RightButton)
     {
         qDebug() << QStringLiteral("鼠标右键释放");
     }
     else if(event‐>button() == Qt::MiddleButton)
     {
         qDebug() << QStringLiteral("鼠标中键释放");
     }
 }
 *****************************************************************
 void Widget::mouseDoubleClickEvent(QMouseEvent *event)
 {
     if(event‐>button() == Qt::LeftButton)
     {
         qDebug() << QStringLiteral("鼠标左键双击事件");
     }
     else if(event‐>button() == Qt::RightButton)
     {
         qDebug() << QStringLiteral("鼠标右键双击事件");
     }
    else if(event‐>button() == Qt::MiddleButton)
     { 
         qDebug() << QStringLiteral("鼠标中键双击事件"); 
     }
 }
 **************************************************************
 void Widget::wheelEvent(QWheelEvent *event)
 {
     if(event‐>delta() > 0)
     {
         qDebug()<<QStringLiteral("滚轮往前推...");
     }
     else
     {
         qDebug()<<QStringLiteral("滚轮往后推...");
     }
}
```