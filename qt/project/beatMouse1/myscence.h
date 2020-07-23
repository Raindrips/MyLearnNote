#ifndef MYSCENCE_H
#define MYSCENCE_H

#include <QObject>
#include <QGraphicsScene>
#include "myitem.h"
#include <QTimer>
//场景类
class myscence : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myscence(QObject *parent = 0);
    ~myscence();

signals:

public slots:
    void showMouse();
    void startGame();
    void pauseGame();
    void stopGame();
private:
    //myitem *Item;
    //myitem *Item[4][4];
    myitem *Item[16];
    QTimer*ptimer;
};

#endif // MYSCENCE_H
