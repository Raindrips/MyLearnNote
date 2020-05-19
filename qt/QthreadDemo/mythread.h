#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include "QDebug"

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

signals:
    void startThread1singnal();

public slots:
    void threadSlot();
private:
};

#endif // MYTHREAD_H
