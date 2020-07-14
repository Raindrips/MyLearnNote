#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->enumIpAddress();

    //分配空间，指定父对象
    udpSocket = new QUdpSocket(this);

}

void Widget::enumIpAddress()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    QStringList addrList;
    foreach (QHostAddress address, list)
    {
        if(address.isNull())
            continue;

        //网络层协议 过滤只剩下IPV4的地址
        QAbstractSocket::NetworkLayerProtocol protocol = address.protocol();
        if(protocol != QAbstractSocket::IPv4Protocol)
            continue;

       QHostAddress ipAddress =  address;
       qDebug() << ipAddress.toString();
        addrList.append(ipAddress.toString());
    }

    ui->comboBoxLocalAddress->addItems(addrList);
}

void Widget::processRecvGroupSlot()
{
    QHostAddress remoteIpAddress;
    quint16 remotePort;
    QByteArray recvData;

    qDebug() << "recv data in...";
    while (udpSocket->hasPendingDatagrams())
    {
        remoteIpAddress = udpSocket->peerAddress();
        remotePort = udpSocket->peerPort();
        ui->lineEditRemoteIpAddress->setText(remoteIpAddress.toString());
        ui->lineEditRemotePort->setText(QString::number(remotePort));
//        recvData = udpSocket->readAll();

        udpSocket->readDatagram(recvData.data(), recvData.size());
        qDebug() << recvData << recvData.size();
        ui->textBrowserRecv->append(recvData);
    }

//    while (udpSocket4.hasPendingDatagrams()) {
//        datagram.resize(int(udpSocket4.pendingDatagramSize()));
//        udpSocket4.readDatagram(datagram.data(), datagram.size());
//        statusLabel->setText(tr("Received IPv4 datagram: \"%1\"")
//                             .arg(datagram.constData()));
//    }

}


Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonBind_clicked()
{
    localAddress = QHostAddress(ui->comboBoxLocalAddress->currentText());
    localPort = ui->lineEditPort->text().toInt();

    if(!udpSocket->isOpen())
    {
        udpSocket->open(QIODevice::ReadWrite);
        udpSocket->bind(localAddress, localPort, QUdpSocket::ShareAddress);
        ui->pushButtonBind->setText(QString::fromLocal8Bit("解绑"));
        connect(udpSocket, SIGNAL(readyRead()),
                this, SLOT(processRecvGroupSlot()));
    }
    else
    {
        udpSocket->close();
        ui->pushButtonBind->setText(QString::fromLocal8Bit("绑定"));
    }
}

void Widget::on_pushButtonSend_clicked()
{

}
