#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QNetworkAccessManager>  //找网卡
#include <QNetworkInterface> //找网卡
#include <QHostAddress>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void enumIpAddress();

public slots:
    void processRecvGroupSlot();
private slots:
    void on_pushButtonBind_clicked();

    void on_pushButtonSend_clicked();

private:
    Ui::Widget *ui;

    QUdpSocket *udpSocket;
    QHostAddress localAddress;
    quint16 localPort;
};

#endif // WIDGET_H
