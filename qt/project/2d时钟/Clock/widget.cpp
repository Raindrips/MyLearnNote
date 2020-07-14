#include "Widget.h"
#include "ui_Widget.h"

const QPoint Widget::hourHand[4] = {
    QPoint(3, 5),
    QPoint(0, 13),
    QPoint(-3, 5),
    QPoint(0, -40)
};
const QPoint Widget::minuteHand[4] = {
    QPoint(3, 5),
    QPoint(0, 16),
    QPoint(-3, 5),
    QPoint(0, -70)
};
const QPoint Widget::secondHand[4] = {
    QPoint(3, 5),
    QPoint(0, 18),
    QPoint(-3, 5),
    QPoint(0, -90)
};
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //this->setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    hourHandPen = QPen(palette().foreground(), 2.0);//设置小时刻度线为粗黑
    minuteHandPen = QPen(palette().foreground(), 1.0);//设置分钟刻度线为灰
    font.setPointSize(10);//字体大小设置为10
    setFont(font);
    QTimer *timer = new QTimer(this);
    timer->start(1000);//一秒钟
    //connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    setWindowTitle("The Widget");
    resize(360, 360);

}
Widget::~Widget()
{
}
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    int side = qMin(width(), height());
    painter.setViewport((width() - side) / 2, (height() - side) / 2,
                        side, side);
    painter.setWindow(0, 0, 200, 200);
    painter.translate(100,100);//重新设定坐标原点
    drawClockDial(&painter);
    drawHourHand(&painter);
    drawMinuteHand(&painter);
    drawsecondHand(&painter);
    painter.setBrush(Qt::black);
    painter.drawEllipse(QPoint(0,0),3,3);
}
//绘制时针
void Widget::drawHourHand(QPainter *painter)
{
    QTime time = QTime::currentTime();
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->save();
    painter->rotate(30.0*(time.hour()+time.minute()/60.0));
    painter->drawConvexPolygon(hourHand,4);//绘制时针
    painter->restore();//绘制图形后复位坐标系
}
//绘制分针
void Widget::drawMinuteHand(QPainter *painter)
{
    QTime time = QTime::currentTime();
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    painter->save();
    painter->rotate(6.0*(time.minute()+time.second()/60.0));
    painter->drawConvexPolygon(minuteHand,4);//绘制分针
    painter->restore();//绘制图形后复位坐标系
}
//绘制秒针
void Widget::drawsecondHand(QPainter *painter)
{
    QTime time = QTime::currentTime();
    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    painter->save();//保存坐标系，防止坐标系跑偏了
    painter->rotate(6.0*time.second());//注意是6.0，不是6
    painter->drawConvexPolygon(secondHand,4);//绘制秒针
    painter->restore();//绘制图形后复位坐标系
}
//绘制表盘数字
void Widget::drawClockDial(QPainter *painter)
{
    //绘制钟表刻度盘和数字
    for (int i = 1; i <=60; ++i)
    {
        painter->save();
        painter->rotate(6*i);//坐标轴旋转6度
        if (i % 5 == 0)
        {
            painter->setPen(hourHandPen);
            painter->drawLine(0, -98, 0, -82);
            painter->drawText(-20, -82, 40, 40,
                              Qt::AlignHCenter | Qt::AlignTop,
                              QString::number(i/5));
        }
        else
        {
            painter->setPen(minuteHandPen);
            painter->drawLine(0, -98, 0, -88);
        }
        painter->restore();//绘制图形后复位坐标系
    }
}
