#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QHostAddress remoteAddress = QHostAddress(ui->lineEditSenderIpAddress->text());
    quint16 remotePort = ui->lineEditSenderPort->text().toInt();

    QString dataStr = ui->textEditSend->toPlainText();
    //QByteArray data = dataStr.toUtf8();          //发送UTF编码数据
    QByteArray dataBa = dataStr.toLocal8Bit();     //发送本地字符(GBK)

    udpSocket.writeDatagram(dataBa,
                            remoteAddress,
                            remotePort);
}
