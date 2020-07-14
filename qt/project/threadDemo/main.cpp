#include <QCoreApplication>
#include <QThread>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"main a.exec() :"<<QThread::currentThreadId();
    MyThread thread1;
    thread1.setThreadName("thread1");
    thread1.start();

    MyThread thread2;
    thread2.setThreadName("thread2");
    thread2.start();

    MyThread thread3;
    thread3.setThreadName("thread3");
    thread3.start();

    MyThread thread4;
    thread4.setThreadName("thread4");
    thread4.start();

    return a.exec();
}
