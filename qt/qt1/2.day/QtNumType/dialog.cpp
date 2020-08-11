#include "dialog.h"
#include "ui_dialog.h"
#include <time.h>
#include <QString>
#include <QDateTime>
#include <QTimer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_type,
                     SIGNAL(clicked(bool)),
                     this,SLOT(TestNumType()));

    QObject::connect(ui->pushButton_string,
                     SIGNAL(clicked(bool)),
                     this,SLOT(TestString()));

    QObject::connect(ui->pushButton_dateTime,
                     SIGNAL(clicked(bool)),
                     this,SLOT(TestDateTime()));

    QObject::connect(ui->pushButton_timer,
                     SIGNAL(clicked(bool)),
                     this,SLOT(TestTimer()));

}

Dialog::~Dialog()
{
    delete ui;
}
void  Dialog::TestNumType()
{
    qint8 sig_char = 'a';
    uchar u_char = 'a';
    quint8 unsig_char = 'a';

    qint16 sig_short = 123;
    qint32 sig_int = -123;
    int    sig_i =17;

    float f_float1 = 123.123;
    float f_float2 = 123.321;
    double d_double1 = 123.123456789;
    double d_double2 = 123.123;

    //比较绝对值
    int res_int= qAbs(sig_int);
    qDebug("绝对值:%d",res_int);

    //比较doubole类型
    bool b_res =  qFuzzyCompare(d_double1, d_double2);
    qDebug("%lf 和%lf 的结果:%d",d_double1,d_double2,b_res);

    //找到两个数中最大值
     float res_max = qMax(f_float1,f_float2);
     qDebug("%f 和%f 中:%f 大",f_float1,f_float2,res_max);

     //随机数.qsrand() / rand()
     qsrand(time(NULL));
     sig_i =qrand();

     //限定某个数据在某一个范围之内
     int res_qb= qBound(8,sig_i,18);
     qDebug("最小值8最大值18,我的值%d,范围值%d",sig_i, res_qb);


}


void  Dialog::TestString()
{
    QString temp1 = "tanzhou";
    temp1 += " danny";
    temp1.append(" shuai shuai shuai");
    temp1.insert(7,"EDU");
    qDebug("%s",temp1.toStdString().data());

    temp1.clear();
     qDebug("清空后%s",temp1.toStdString().data());

     //格式化处理
    temp1.sprintf("danny 帅帅%d岁",17);
    qDebug("%s",temp1.toStdString().data());

    temp1= QString("age of %2 is %1").arg(17).arg("danny");
    qDebug("%s",temp1.toStdString().data());

    temp1.clear();
    temp1.sprintf("%d",17);
    bool ok = 0;
    int ok_res = temp1.toInt(&ok,10);
     qDebug("%d",ok_res);

}

void Dialog::TestDateTime()
{

    //获取系统时间
    QDateTime * dateAndTime = new QDateTime(
                QDateTime::currentDateTime());
    //得到日期时间中的日期和时间
    QString d= dateAndTime->date().toString();
    QString t =dateAndTime->time().toString();
     qDebug("日期是:%s,时间是%s",
            d.toStdString().data(),
            t.toStdString().data());
   //把字符串转换成时间
   QDateTime strDate =  QDateTime::fromString("2011-11-11 11:11:11",
                           "yyyy-MM-dd hh:mm:ss" );
    d = strDate.date().toString();
    qDebug("日期是:%s", d.toStdString().data());
}


void Dialog::TestTimer()
{
    QTimer * pTimer = new QTimer(this);
    connect(pTimer,SIGNAL(timeout()),this,SLOT(TimeProc()));
    pTimer->start(3000);
}

 void  Dialog::TimeProc()
 {
    qDebug("定时器又到了,3秒结束了,赚了100块钱");
 }
