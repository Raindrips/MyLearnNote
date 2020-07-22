**绘图**

1.   rotate//旋转
2. 增加反锯齿
3. load//增加图片

```
rotationPainter.setRenderHint(QPainter::SmoothPixmapTransform);
```

​    

```
#include  <QPainter>//画家头文件
public:
    void paintEvent(QPaintEvent*);//主窗口绘图事件
--------------------------------------------------
void MainWindow::paintEvent(QPaintEvent *)重写事**件方法1
{
     QPainter painter(this);//创建画家，指定绘图设备
     QPixmap pix;//创建QPixmap对象
     pix.load(":/new/prefix1/src/PlayLevelSceneBg.png");//加载图片
    painter.drawPixmap(0,0,this->width(),this->height(),pix); //绘制背景图
}
************************************************************
void Widget::paintEvent(QPaintEvent *)重写事件**件方法2
{//this->rect()自由伸缩，压扁图片
    QPainter painter(this);//创建画家，指定绘图设备
    painter.drawPixmap(this->rect(),QPixmap(":/1.jpg"));//画背景图
}
***************************************************************
private:
    QPainter* painter;
void Widget::paintEvent(QPaintEvent *)重写事件**件方法3
{
    painter.begin(this);
    painter.drawPixmap(0,0,1024,1024,QPixmap(":/3.png"));
    painter.end();
}
**********************************************************
    //设置图片的固定尺寸
    this->setFixedSize( pixmap.width(), pixmap.height() );
    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pixmap);
    //设置图标大小
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
```

**制一个指针**

```
 painter.begin(this);
        qDebug()<<"123";
        painter.translate(200, 200);
        static const QPoint point[4] = {QPoint(0, 18), QPoint(20, 0),
                                       QPoint(0, -100), QPoint(-20, 0)};
        painter.setBrush(QColor(Qt::darkBlue));//设置颜色
        painter.drawPolygon(point, 4);//多边形
        QRect rectanle(-7, -7, 14, 18); //注意现在widget坐标系已经移动了
        painter.setBrush(QColor(Qt::yellow));//设置颜色
       painter.drawEllipse(rectanle);
       painter.end();

```

  给labeil贴图

```
QPixmap img;
```