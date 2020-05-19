#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void luckStartSignal();

public slots:
    void rtTimerOutSlot();
    void luckStartSlot();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);


private:
    Ui::Widget *ui;
    QPainter rotaionPainter;
    QPainter pointPainter;
    QTimer rtTimer;   //旋转定时器
    qreal rtAngle;    //旋转因子
    int randNumber;   //目标转多少(随机数)

};

#endif // WIDGET_H
