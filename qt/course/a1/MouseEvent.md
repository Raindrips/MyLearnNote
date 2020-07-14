## 鼠标事件

头文件 <QMouseEvent>



### 获取坐标位置

```cpp
globalPos() //获取全局位置
this*->frameGeometry().topLeft();//获取窗口左上角坐标
```



### 鼠标事件

```cpp
protected:
virtual void mousePressEvent(QMouseEvent *event);				//鼠标按下事件
virtual void mouseReleaseEvent(QMouseEvent *event);				//鼠标释放事件
virtual void mouseDoubleClickEvent(QMouseEvent *event);			//鼠标双击事件
virtual void wheelEvent(QWheelEvent *event);					//滚轮事件
```

鼠标重写事件

```cpp 
public:
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    //event鼠标按下记录x坐标y坐标
    int x=event->x();
    int y=event->y();
    qDebug()<<x<<" "<<y<<endl;
}
```

**设置鼠标穿透**

```cpp
label->setAttribute(Qt::WA_TransparentForMouseEvents);
```

**打印窗口坐标位置**

```cpp
qDebug()<<e->pos();
```

### 鼠标点击按钮

```cpp
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