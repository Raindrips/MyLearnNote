#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "handler.h"
//图元类
class myitem : public QGraphicsPixmapItem
{
public:
    myitem();
    ~myitem();
    //设置图片的函数
    void setpic(QString path);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void setMouse(bool mouse);  //设置老鼠
    bool isMouse();   //判断是否是老鼠

    void setStart(bool start);  //设置开始
    bool isStart();   //判断是否是开始
private:
    bool mouse;  //true   false
    bool start;
};

#endif // MYITEM_H
