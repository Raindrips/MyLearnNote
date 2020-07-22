#include "myitem.h"
#include <QPixmap>
#include <QDebug>
#include <QCursor>
//图元类
myitem::myitem()
{
  //  this->setPixmap(QPixmap(":/bg/pic/地图.jpg"));
     this->setPixmap( QPixmap(":/bg/pic/map.jpg"));
    this->mouse=false;
    this->start=false;
    this->setCursor(QCursor(QPixmap(":/mouser/pic/onUp.png")));

}

myitem::~myitem()
{

}

void myitem::setpic(QString path){
    this->setPixmap( QPixmap(path));
}

//单例模式


void myitem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    this->setCursor(QCursor(QPixmap(":/mouser/pic/onDown.png")));
    if(this->isStart()){  //加 判断游戏是否开始
         handler *hand=handler::getInstance();
        if(this->isMouse()){
           hand->addSoure();
            this->setPixmap(QPixmap(":/mouser/pic/aMouse.jpg"));
            this->mouse=false;
        }

    }
//    //qDebug()<<"鼠标按下";
//    if(this->isMouse()){
//        qDebug()<<"打的是老鼠";
//    }
//    else{
//        qDebug()<<"打的不是老鼠";
//    }


}
void myitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    this->setCursor(QCursor(QPixmap(":/mouser/pic/onUp.png")));

}

void myitem::setMouse(bool mouse){
    this->mouse=mouse;
}
bool myitem::isMouse(){
    return this->mouse;

}

void myitem::setStart(bool start){
    this->start=start;

}
bool myitem::isStart(){
    return start;
}
