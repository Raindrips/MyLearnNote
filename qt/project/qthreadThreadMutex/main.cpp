#include <QCoreApplication>
#include "mythread.h"

int globlIndex;
QMutex globlMutex;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyThread thread1;
    thread1.setThreadName("thread1");
    thread1.start();


    MyThread thread2;
    thread2.setThreadName("thread2");
    thread2.start();


    MyThread thread3;
    thread3.setThreadName("thread3");
    thread3.start();

    return a.exec();
}
