#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&rtTimer, SIGNAL(timeout()), this, SLOT(rtTimerOutSlot()));//设置转盘自动旋转速度
    connect(this, SIGNAL(luckStartSignal()), this, SLOT(luckStartSlot()));//启动
    //rtTimer.start(1000);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::rtTimerOutSlot()
{
    rtAngle++;
    //设置4档速度  4AT
    if((rtAngle - randNumber) == 90)
    {   //if(randNumber = 427 )  rtAngle = 427 + 90
        rtTimer.setInterval(10);   //第一次降低速度
        qDebug() << "rtAngle90 :" << rtAngle;
    }
    else if((rtAngle - randNumber) == 180)
    {   //427 + 180
        rtTimer.setInterval(15);  //第二次降速
        qDebug() << "rtAngle180 :" << rtAngle;

    }
    else if((rtAngle - randNumber) == 270)
    {
        rtTimer.setInterval(30);  //第三次降速
        qDebug() << "rtAngle270 :" << rtAngle;

    }
    else if((rtAngle - randNumber) == 360)
    {
        rtAngle-- ;      //让速度慢慢降为0  rtAngle = 0时就转不动了
        rtTimer.stop();  //停止计时 界面更新事件
        qDebug() << "rtAngle360 :" << rtAngle;
    }
	update(true);//产生一个绘图事件paintevent对窗口重绘
}

void Widget::paintEvent(QPaintEvent *event)
{
    //图片
    rotaionPainter.begin(this);
    rotaionPainter.translate(200, 200);//将绘图坐标系从窗口左上角转到窗口中心（200，200）为原点
    rotaionPainter.rotate(rtAngle); //设置旋转转盘

    rotaionPainter.drawPixmap(-200, -200,
                              400, 400,
                              QPixmap(":/image/png/luck.png"));
    rotaionPainter.end();

    //指针
    pointPainter.begin(this);
    pointPainter.translate(200, 200);
    static const QPoint point[4] = {QPoint(0, 18), QPoint(20, 0),
                                   QPoint(0, -100), QPoint(-20, 0)};
    pointPainter.setBrush(QColor(Qt::blue));
    pointPainter.drawPolygon(point, 4);

    //铆钉
    static const QRect rectanle(-7, -7, 14, 18);
    pointPainter.setBrush(QColor(Qt::darkYellow));
    pointPainter.drawEllipse(rectanle);
    //结束绘图
    pointPainter.end();
	
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
		//限定鼠标点中区域为转盘指针有效，启动转盘 
		//注意鼠标位置坐标系原点,是窗口左上角	而钉子坐标系已转换到窗口中心
        if(event->pos().x() > 180 && event->pos().x() < 220
           &&event->pos().y() > 130 && event->pos().y() < 216)
        {
            qDebug() << "point event";
            emit luckStartSignal();
        }

    }
}

void Widget::luckStartSlot()
{
    /* 撒一把随机数 */
    rtAngle = 1;
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    randNumber = qrand()%360 + 180;//幸运数不能小于180
    qDebug() << "randNumber :" << randNumber;
    rtTimer.start(5);
}
