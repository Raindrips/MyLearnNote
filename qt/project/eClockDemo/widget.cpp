#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    rtTimer = new QTimer;

    setWindowFlags(Qt::FramelessWindowHint | windowFlags()); //不要标题栏 不影响之前的flags
    setMouseTracking(true);
    createRightPopActions();

    connect(rtTimer, SIGNAL(timeout()),
            this, SLOT(update()));           //rtTimer超时后会直接调用paintEvent进行重绘
    rtTimer->start(1000);
    // 两个相等
//    rtTimer->setInterval(1000);
//    rtTimer->start();
}

Widget::~Widget()
{
    delete ui;
}

/* 创建右键菜单 */
void Widget::createRightPopActions()
{
    popMenu = new QMenu(this);
    popMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 66, 66);"));

    adjustTimeAction = new QAction(this);
    adjustTimeAction->setText(QString::fromLocal8Bit("修改时间")); //gbk -> Unicode

    adjustDateAction = new QAction(this);
    adjustDateAction->setText(QString::fromLocal8Bit("修改日期"));

    quitAction = new QAction(this);
    quitAction->setText(QString::fromLocal8Bit("退出"));

    connect(quitAction, SIGNAL(triggered(bool)),
            this, SLOT(close()));                  //关联退出的Action
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QString posStr = QString("%1, %2").arg(event->pos().x()).arg(event->pos().y());

    QToolTip::showText(QCursor::pos(), posStr, this); //QCursor::pos()光标所在的坐标

    if(event->buttons() & Qt::LeftButton)
    {
        mouseDeskTopLeft = event->globalPos();
        windowDeskTopLeft = mouseDeskTopLeft - mouseWindowTopLeft;
        this->move(windowDeskTopLeft);
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    mouseWindowTopLeft = event->pos();
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(this->isFullScreen())
    {
        this->showNormal();
    }
    else
    {
        this->showFullScreen();
    }
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "contextMenuEvent ing ...";

    popMenu->clear();
    popMenu->addAction(adjustTimeAction);
    popMenu->addAction(adjustDateAction);
    popMenu->addSeparator();
    popMenu->addAction(quitAction);

    //popMenu->exec(); //堵住
    popMenu->exec(QCursor::pos()); //堵住   光标当前的位置
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // 时针、分针、秒针位置 - 多边形
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -30)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -65)
    };

    static const QPoint secondHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -80)
    };


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(this->width() / 2, this->height() / 2);
    painter.setPen(Qt::white);
    //painter.drawLine(QPoint(88, 0), QPoint(96, 0));

    int side = qMin(width(), height()); //定义一个边界,保证是圆形的
    painter.scale(side / 200.0, side / 200.0);

    {//绘制表盘
        //绘制小时线
        for(int i = 0; i < 12; ++i)
        {
            painter.drawLine(QPoint(88, 0), QPoint(96, 0));
            painter.rotate(30);
        }

        //painter.drawLine(92, 0, 96, 0);                  //先画一根分钟

        // 绘制分钟线 （360度 / 60 = 6度）
        for (int j = 0; j < 60; ++j) {
            if ((j % 5) != 0)                             //碰到小时就不画
                painter.drawLine(92, 0, 96, 0);
            painter.rotate(6.0);
        }
    }

    {//绘制指针


        QTime time = QTime::currentTime();  //获取当前时间

        painter.save();
        painter.setPen(Qt::NoPen);  //默认情况下时有一个像素的边框,所以我这里用NoPen = 不要边框
        painter.setBrush(Qt::white);
        painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0))); //时钟不一定对准时钟线 需要考虑分的感受
        painter.drawConvexPolygon(hourHand, 3);
        painter.restore();                //还原画笔

        painter.save();
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(130, 130, 130));
        painter.rotate(6.0 * (time.minute() + time.second() / 60.0)); //考虑秒
        painter.drawConvexPolygon(minuteHand, 3);
        painter.restore();                //还原画笔


        painter.save();
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(50, 50, 50));
        painter.rotate(6.0 * time.second());
        painter.drawConvexPolygon(secondHand, 3);
        painter.restore();                //还原画笔
    }
}



