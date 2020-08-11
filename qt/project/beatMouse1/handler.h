#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>

class handler : public QObject
{
    Q_OBJECT
public:
    static handler *getInstance();//  只能操作类里面的静态成员函数
    void addSoure();//加分
private:
    explicit handler(QObject *parent = 0);
    ~handler();

signals:
   void beatMouse();

public slots:
private:
    static handler *hand;
};

#endif // HANDLER_H
