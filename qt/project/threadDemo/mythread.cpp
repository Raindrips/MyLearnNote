#include "mythread.h"

#include <QMutex>
int indexid=0;
QMutex  globleMutex;
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
        globleMutex.lock();
        qDebug() << threadName << "I'am A thread";
        indexid++;
        qDebug() << threadName << "I'am A thread" << indexid;
        globleMutex.unlock();
        QThread::sleep(1);//线程保活
    }
}
