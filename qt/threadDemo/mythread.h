#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QObject>
#include <QThread>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void setThreadName(QString);

protected:
    virtual void run();


private:
    QString threadName;
};

#endif // MYTHREAD_H
