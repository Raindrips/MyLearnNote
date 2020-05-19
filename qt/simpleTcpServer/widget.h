#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkInterface>
#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
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

private slots:
    void on_pushButtonListen_clicked();
    void newConnectionSlot();
    void readyReadSlot();
    void disconnectedSlot();
    void on_pushButtonSend_clicked();

private:
    void enumIpAddress();

private:
    Ui::Widget *ui;

    QTcpServer *mServer;
    QTcpSocket *mSocket = nullptr;
};

#endif // WIDGET_H
