#include "widget.h"
#include "ui_widget.h"

#include <QNetworkInterface>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    enumIpAddress();//枚举系统IP
    //创建tcp连接服务对象
    mTcpserver = new QTcpServer(this);
    //绑定有新tcp socket新连接处理槽函数
    connect(mTcpserver,&QTcpServer::newConnection,
            this,&Widget::newconnectionslot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::enumIpAddress()
{
    //获取系统所有网卡IP信息
    qDebug() << QNetworkInterface::allAddresses();
    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    QStringList addressStrList;//保存IP地址容器对象
    addressStrList.clear();

    //遍历list
    foreach(QHostAddress hostaddress,list)
    {
        //检查IP地址是否位空
        if(hostaddress.isNull())
            continue;
        //提取网卡协议类型
        QAbstractSocket::NetworkLayerProtocol protocol = hostaddress.protocol();
        //判断网卡协议类型是否是ipv4协议
        if(protocol != QAbstractSocket::IPv6Protocol)
        //将IP地址追加到qstring容器
        addressStrList.append(hostaddress.toString());
    }

    //将ip地址容器添加到列表控件
    ui->comboBox->addItems(addressStrList);
}

void Widget::on_btnlisten_clicked()
{
    //获取界面设置的监听IP地址和端口号
    QString serverip = ui->comboBox->currentText();
    hostaddress = QHostAddress(serverip);//构造地址对象
    quint16 servport = ui->lineEdit->text().toInt();
    //判断当前地址是否有被监听
    if(!mTcpserver->isListening())
    {
        //启动监听
        if(!mTcpserver->listen(hostaddress,servport)){

            qDebug() << "listen faile!!!";

        }
        else{
            qDebug() << "listen success!!!";
        }
    }else{
        //关闭当前监听
        mTcpserver->close();//关闭服务端
        qDebug() << "close  listen !!!";
    }

}
//客户端连接请求处理槽函数
void Widget::newconnectionslot()
{
    qDebug() << "new connection!!!";
}
