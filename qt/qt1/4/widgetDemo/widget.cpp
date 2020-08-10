#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QMovie>

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //用qlabel控件加载图片
    ui->label_2->setPixmap(QPixmap(":/ico/resouce/logo.ico"));
    //图片尺寸适配
    ui->label_2->setScaledContents(true);

    //加载.gif图
    QMovie *pMove = new QMovie(":/resouce/hBo9CPjbL6vcAWcQyGc9jtEEPgs2Nz3v.gif_s400x0");
    ui->label_3->setMovie(pMove);
    ui->label_3->setFixedSize(510,   215);
    pMove->start();
    //自定义信号和槽关联
    connect(this, SIGNAL(setWindowTitleSignal()),this, SLOT(on_setWindowTitle()));
}

Widget::~Widget()
{
    delete ui;
}

bool buttonfl=false;
void Widget::on_pushButton_clicked()
{
    qDebug() << "on_pushButton_clicked";
    if(!buttonfl){

        ui->pushButton->setText(QStringLiteral("连接设备"));
        buttonfl = true;
    }
    else{
        ui->pushButton->setText(QStringLiteral("断开设备"));
        buttonfl=false;
    }
}

void Widget::on_setWindowTitle()
{
    qDebug() << "on_setWindowTitle";
    //设置界面标题
    setWindowTitle("signal and slot");
}

void Widget::on_pushButton_2_clicked()
{
    qDebug() << "on_pushButton_2_clicked";
    //发射信号
    emit setWindowTitleSignal();
    //槽函数可以直接调用
    //on_setWindowTitle();
}
