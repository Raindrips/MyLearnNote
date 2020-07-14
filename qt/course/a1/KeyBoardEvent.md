## 按键点击事件

### 声明

```cpp
virtual void keyPressEvent(QKeyEvent *event);//按键按下事件

virtual void keyReleaseEvent(QKeyEvent *event);//按键释放
```

### 实现

```cpp
//按键按下事件
void Widget::keyPressEvent(QKeyEvent *event)
{
    //当键盘按下T进入
    if(event‐>key() == Qt::Key_T)
    {
        qDebug() << "Key_T is pressed";
    }
    //当键盘按下Z进入
    else if(event‐>key() == Qt::Key_Z)
    {
        qDebug() << "Key_Z is pressed";
    }
	//组合键盘	
    if(event->modifiers()==Qt::ControlModifier)//第一次判断是否按下CTRL
    {   
        if(event->key()==Qt::Key_A)//判断是否按下T
        {
            qDebug() << "Ctrl + A is pressed";
        }
    }
}
```



### 字符串格化

```cpp
a=QString("%1 : %2").arg(p.x()).arg(p.y());
```

