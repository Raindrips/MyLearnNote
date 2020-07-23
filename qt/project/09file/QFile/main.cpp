#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include <QDataStream>
#include <QDate>
#include<QDir>
#include<QFileInfoList>
#include <QFileInfo>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("yingtao.txt");
    //1.判断文件是否存在
    if(!file.exists()){
        qDebug()<<"文件不存在";

    }
    else{

        qDebug()<<"文件存在";
    }
    //2.删除文件
   // file.remove();
    //3.重命名
    file.rename("yingtao1.txt");
    //4.拷贝文件
    QFile::copy("yingtao1.txt","yingtao2.txt");
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text)){
        qDebug()<<"文件打开失败";
        return 0;
    }
    //关闭文件
    //file.close();

    //QTextStrem文本文件流
    QTextStream str(&file);

    //1.写文件
    QString st="hello";
    QString ss="world";

//    //从内存输入到文件中
//    str<<st<<" "<<ss;
//    //设置文件偏移量
//    str.seek(0);
//    str>>st>>ss;
//    qDebug()<<st;
//    qDebug()<<ss;

//    while(!str.atEnd()){ //判断文件是否读完
//        QString temp=str.readLine();  //一行一行的读取
//        qDebug()<<temp;

//    }

    //二进制文件流
    QDataStream ds(&file);
    ds<<QString("yingtao");
    ds<<QDate::fromString("2018-08-02","yyyy-MM-dd");

    //关闭文件
    file.close();
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text)){
        qDebug()<<"文件打开失败";
        return 0;
    }
    QDataStream dtemp(&file);
    QString name;
    QDate dt;
    dtemp>>name;
    dtemp>>dt;
    qDebug()<<name <<":"<<dt;
    //关闭文件
    file.close();

    QDir d1/*("./test12/yingtao")*/;
    QDir d2("./test/yingtao");
    QDir dir=QDir::current();
    if(d1==d2){
        qDebug()<<"两个目录一样";

    }
    if(d1!=d2){
        qDebug()<<"两个目录不一样";

    }
    d1.mkdir(QString("./test1")); //创建路径
    qDebug()<<dir;
    qDebug()<<dir.dirName();  //获取当前路径的名字
    if(!d1.exists()){
        qDebug()<<"目录不存在";
    }
    //设置过滤器
    dir.setFilter(QDir::Files);
    QFileInfoList list=dir.entryInfoList();
    for(int i=0;i<list.size();i++){
        QFileInfo f1=list.at(i);
        qDebug()<<QString("%1:%2").arg(f1.fileName()).
                arg(f1.size());
    }
    dir.cd("test1");  //跳转到指定路径
     qDebug()<<dir.dirName();  //获取当前路径的名字
    return a.exec();
}
