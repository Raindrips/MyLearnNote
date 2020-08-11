#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <ctime>
#include<QString>
#include <QDateTime>
#include<QTimer>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->btntestnum,SIGNAL(clicked()),this,SLOT(TestNumType()));
    connect(ui->btnteststring,SIGNAL(clicked()),this,SLOT(TestStringType()));
    connect(ui->btntestdata,SIGNAL(clicked()),this,SLOT(TestDateTimeType()));
    connect(ui->btnTestTimer,SIGNAL(clicked()),this,SLOT(TestTimerType()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::TestNumType(){
    //char
    qint8 sig_char ='a';
    uchar u_char='a';


    qint32 sig_int=-123;
    //绝对值
    int res_int=qAbs(sig_int);
    int sig_i=4;
    // 0    11   8
   // int res_qb=qBound(5,sig_i,100);
    qsrand(time(NULL));
    sig_i=qrand();
     int res_qb=qBound(5,sig_i,100);
    qDebug("hello");
    qDebug()<<res_int;
    qDebug()<<res_qb;
    qDebug()<<sig_i;

}

void Dialog::TestStringType(){
    //s3=s1 + s2   hellowold
    QString temp1="hello";
    temp1.append("wold");//temp1+wold  //追加
    temp1.insert(6,"123");  //插入

    qDebug("%s",temp1.toStdString().data());
    temp1.clear();  //清空
    qDebug("清空后%s",temp1.toStdString().data());
    temp1.sprintf("%s","90");
    qDebug("%s",temp1.toStdString().data());
    bool ok;
    int ok_res=temp1.toInt(&ok,10);
    //int ok_res=temp1.toInt();
    qDebug("%d",ok_res);
    QString str;
    str = QString("%4 %2 (%3-%1)").arg("ying")
            .arg("tao").arg(10).arg(11);
    qDebug("%s",str.toStdString().data());
}

void  Dialog::TestDateTimeType(){
    //构造一个对象，保存当前的日期和时间
    QDateTime *dataTime=new QDateTime(QDateTime::currentDateTime());
    QString d=dataTime->date().toString();
    QString t=dataTime->time().toString();
    qDebug("日期是：%s,时间是：%s",d.toStdString()
           .data(),t.toStdString().data());
    //字符串类型转换成时间日期类型
    QDateTime strDate=QDateTime::fromString("2018-7-20 22:14:50","yyyy-MM-dd hh:mm:ss");
    d=strDate.date().toString();
    qDebug("日期是：%s",d.toStdString().data());

}

void Dialog::TestTimerType(){
    QTimer *pTimer=new QTimer(this);
    connect(pTimer,SIGNAL(timeout()),this,SLOT(TimerProc()));
    pTimer->start(1000);
    pTimer->setSingleShot(true);

    pTimer->setInterval(10);

}

void Dialog::TimerProc(){
    qDebug("定时器时间到了！");
}
