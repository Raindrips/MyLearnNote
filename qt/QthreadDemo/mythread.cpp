#include "mythread.h"
MyThread::MyThread(QObject *parent) : QObject(parent)
{

}

void MyThread::threadSlot()
{
   qDebug() << "threadSlot run!";
}
