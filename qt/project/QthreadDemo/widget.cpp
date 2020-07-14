#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mythread.moveToThread(&md5Thread);
    md5Thread.start();//启动线程

    //
    connect(this,SIGNAL(startmytreadsignal()),&mythread,SLOT(threadSlot()));

}

Widget::~Widget()
{
    md5Thread.exit();

    qDebug() << "threadSlot exit!";

    delete ui;
}

void Widget::on_pushButton_clicked()
{
    emit startmytreadsignal();

    qDebug() << "threadSlot run over!";
}
