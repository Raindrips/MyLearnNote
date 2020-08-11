#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QPen>
#include <QFont>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    static const QPoint hourHand[4];
    static const QPoint minuteHand[4];
    static const QPoint secondHand[4];
    QPen hourHandPen;
    QPen minuteHandPen;
    QFont font;
protected:
    void paintEvent(QPaintEvent *event);
    void drawHourHand(QPainter *painter);
    void drawMinuteHand(QPainter *painter);
    void drawsecondHand(QPainter *painter);
    void drawClockDial(QPainter *painter);

};

#endif // WIDGET_H
