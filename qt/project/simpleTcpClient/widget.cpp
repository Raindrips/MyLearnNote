#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket;
    socketState = false;

    connect(socket, SIGNAL(connected()),
                    this, SLOT(connectedSlot()));

    connect(socket, SIGNAL(disconnected()),
            this, SLOT(disconnectedSlot()));

    connect(socket, SIGNAL(readyRead()),
            this, SLOT(readyReadSlot()));

    connect(socket, SIGNAL(bytesWritten(qint64)),
            this, SLOT(bytesWrittenSlot(qint64)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonConnect_clicked()
{
    QString ipAddressStr = ui->lineEditAddress->text();
    qint16 port = ui->lineEditPort->text().toInt();

    if(!socketState)
    {
        socket->connectToHost(ipAddressStr, port);
        if(socket->waitForConnected(3000))
        {
            qDebug() << "Connect2Server OK";
            ui->pushButtonConnect->setText(QString::fromLocal8Bit("断开连接"));
            socketState = true;
        }
        else
        {
            qDebug() << socket->errorString();
            return;
        }
    }
    else
    {
        socket->close();
        ui->pushButtonConnect->setText(QString::fromLocal8Bit("连接"));
    }
}

void Widget::on_pushButtonSendData_clicked()
{
    QString dataStr = ui->textEditSend->toPlainText();
    //QByteArray data = dataStr.toUtf8();        //发送UTF编码数据
    QByteArray data = dataStr.toLocal8Bit();     //发送本地字符(GBK)

    if(socket->isOpen() && socket->isValid())
    {
        socket->write(data);
    }
}


void Widget::connectedSlot()
{
    qDebug()<<"connectedSlot";

}

void Widget::disconnectedSlot()
{
    qDebug()<<"disconnectedSlot";
    ui->pushButtonConnect->setText(QStringLiteral("连接服务器"));
    socketState = false;
}

void Widget::readyReadSlot()
{
    qDebug()<<"readyReadSlot";

    //if(socket->isReadable())
    QByteArray dataBa = socket->readAll();
    int recvNum = dataBa.size();

    QString str = str.fromLocal8Bit(dataBa.data()); //本地GBK转Unicode 解决乱码
    ui->textBrowserRecv->append(QString(str));          //送显示
    ui->lineEditRecvTotal->setText(QString::number(recvNum));
}

/* 统计写了多少数据 */
void Widget::bytesWrittenSlot(qint64 bytes)
{
    qDebug()<<"bytesWrittenSlot";

    ui->lineEditSendTotal->setText(QString::number(bytes));
}

