#include "mythread.h"


extern int globlIndex;
extern QMutex globlMutex;


MyThread::MyThread()
{
    qDebug()<<"MyThread::MyThread:"<<QThread::currentThreadId();
}

void MyThread::setThreadName(QString name)
{
    qDebug()<<"MyThread::setThreadName:"<<QThread::currentThreadId();
    threadName = name;
}


void MyThread::run()
{
    qDebug()<<"MyThread::run:"<<QThread::currentThreadId();
    while(1)
    {
        globlMutex.lock();
        globlIndex++;
        qDebug() << threadName << globlIndex;
        globlMutex.unlock();
        QThread::sleep(1);
    }
}
