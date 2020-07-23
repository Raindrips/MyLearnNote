#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void enumIpAddress(void);//获取本地主机的所有ip
private slots:
    void on_btnlisten_clicked();
public slots:
    void newconnectionslot();//客户端连接请求处理槽函数
private:
    Ui::Widget *ui;
    QTcpServer *mTcpserver;
    QHostAddress hostaddress;
};

#endif // WIDGET_H
