#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
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
    void on_pushButtonConnect_clicked();

    void on_pushButtonSendData_clicked();

    void connectedSlot();

    void disconnectedSlot();
    void readyReadSlot();
    void bytesWrittenSlot(qint64 bytes);

private:
    Ui::Widget *ui;
    QTcpSocket *socket;

    bool socketState;
};

#endif // WIDGET_H
