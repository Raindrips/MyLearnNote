#include <QCoreApplication>
#include <QDebug>
#include  "dlldemo.h"
#include  <QThread>
#include  "staticlib.h"

/*  注意：由于dlldemo.dll没有加入到环境变量中，所以需要把这个dll放到程序运行目录下
如果是用qtcretor启动程序  放在build‐useDllDemo‐xxxx‐Debug目
录下
如果是直接启动程序 放在exe目录下
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //演示静态方法调用
    StaticLib libuser;
    int  number  =  libuser.numberAdd(10,  10);

    //演示普通方法DllDemo  mDllDemo;
    //QString  str  =  mDllDemo.strAdd("555",  "666");
    QThread::sleep(1);
    qDebug()  <<  "number  "  <<  number;
    //qDebug() << "str " /*<< str*/;
    return a.exec();
}
