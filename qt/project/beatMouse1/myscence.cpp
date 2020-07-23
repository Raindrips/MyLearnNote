#include "myscence.h"

myscence::myscence(QObject *parent) : QGraphicsScene(parent)
{
//    this->Item=new myitem;
//    this->Item->setPos(0,0);
//    this->addItem(this->Item);  //把图元放在场景

//    myitem *Item2=new myitem;
//    this->Item->setPos(140,0);
//    this->addItem(Item2);  //把图元放在场景


    int i=0;
    for(int i=0;i<16;i++){
        this->Item[i]=new myitem;
        this->Item[i]->setPos(i%4*this->Item[i]->
                              boundingRect().width(),i/4*this->Item[i]->
                              boundingRect().height());
        this->addItem(this->Item[i]);
    }
   // this->Item[4]->setpic(":/bg/pic/地鼠.jpg");
    this->ptimer=new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));
   // this->ptimer->start(2000);



}

myscence::~myscence()
{

}
void myscence::showMouse(){

    int count=rand()%3+1;
    int i=0;
    for(i=0;i<16;i++){
        this->Item[i]->setpic(":/bg/pic/map.jpg");
        this->Item[i]->setMouse(false);
    }

    for(i=0;i<count;i++){
        int index=rand()%16;
        this->Item[index]->setpic(":/bg/pic/mouse.jpg");
        this->Item[index]->setMouse(true);

    }

}
void myscence::startGame(){
    int i=0;
    //this->setStyle(true);
    for(i=0;i<16;i++){
        this->Item[i]->setStart(true);
    }

    //开启定时器
    this->ptimer->start(1000);

}

void myscence::pauseGame(){
    int i;
    //暂停
    this->ptimer->stop();
    for(i=0;i<16;i++){
        this->Item[i]->setStart(false);
    }
}


void myscence::stopGame(){
    int i;
    for(i=0;i<16;i++){
        this->Item[i]->setStart(false);
    }

    this->ptimer->stop();

    for(i=0;i<16;i++){
        this->Item[i]->setpic(":/bg/pic/map.jpg");
        this->Item[i]->setMouse(false);
    }

}
