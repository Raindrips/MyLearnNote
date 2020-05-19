#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mServer = new QTcpServer;
    enumIpAddress();

    connect(mServer, SIGNAL(newConnection()),
            this, SLOT(newConnectionSlot()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonListen_clicked()
{
    QString serverAddressStr = ui->comboBoxAddress->currentText();
    quint16 port = ui->lineEditPort->text().toInt();
    QHostAddress serverAddress = QHostAddress(serverAddressStr);

    if(!mServer->isListening())
    {
        if(!mServer->listen(serverAddress, port))
        {
            qDebug() << mServer->errorString();
            QMessageBox::warning(this, "Tcp Server Listen Error", mServer->errorString());
        }
        else
        {
            qDebug() << "Listen Ok!!";
            ui->pushButtonListen->setText(QString::fromLocal8Bit("停止监听"));
        }
    }
    else
    {
        mServer->close();
        ui->pushButtonListen->setText(QString::fromLocal8Bit("监听"));
        mServer = nullptr;
    }
}


void Widget::enumIpAddress()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();     //获取本机所有网卡的IP地址
    QStringList addressStrList;
    addressStrList.clear();

    foreach (QHostAddress address, list) {
        if(address.isNull())
            continue;                                                 //如果地址为空,则去掉

        QAbstractSocket::NetworkLayerProtocol protocol = address.protocol();
        if(protocol != QAbstractSocket::IPv4Protocol)                 //只取IPV4的地址
            continue;

        addressStrList.append(address.toString());
    }
    ui->comboBoxAddress->addItems(addressStrList);
}


void Widget::newConnectionSlot()
{
    QString clientInfo;
    mSocket = mServer->nextPendingConnection();
     //窥视Client 信息
    clientInfo = "Address:" + mSocket->peerAddress().toString()
                + "  "
                + "Port:" +  QString::number(mSocket->peerPort());
    ui->lineEditClintInfo->setText(clientInfo);

    connect(mSocket, SIGNAL(readyRead()),
            this, SLOT(readyReadSlot()));

    connect(mSocket, SIGNAL(disconnected()),
            this, SLOT(disconnectedSlot()));
}

void Widget::readyReadSlot()
{
    if(mSocket != nullptr)
    {
        if(mSocket->isReadable())
        {
            QByteArray recvArray = mSocket->readAll();         //适合小数据的全部读取
            QString str = str.fromLocal8Bit(recvArray.data()); //本地GBK转Unicode 解决乱码
            ui->textBrowserRecv->append(str);                  //送显示
        }
    }
}

void Widget::disconnectedSlot()
{
    QMessageBox::information(this, "client close Signal", "client over");
}


void Widget::on_pushButtonSend_clicked()
{
    if(mSocket != nullptr)
    {
        if(mSocket->isWritable())
        {
            QString sendStr = ui->plainTextEditSendData->toPlainText();
            QByteArray sendArray = sendStr.toLocal8Bit();  //Local8Bit : 本地字符集GB与Unicode的转换
            mSocket->write(sendArray);
        }
    }
}


