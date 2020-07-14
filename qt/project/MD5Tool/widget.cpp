#include "widget.h"
#include "ui_widget.h"

#include <QCryptographicHash>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mMd5CheckSum.moveToThread(&md5Thread);
    md5Thread.start();
    //    parm5 = defalut : 槽函数在接收者所在的线程中执行
    //    而接受者又是一个单独的线程类 就和界面线程分开了
        connect(this, SIGNAL(checkMd5SumSignal(QString)),
                &mMd5CheckSum, SLOT(md5encodeslot(QString)));

        //显示结果
    //    connect(&mMd5CheckSum, SIGNAL(sendMd5CheckSumSignal(QByteArray)),
    //                  this, SLOT(recvMd5CheckSumSlot(QByteArray)));
        connect(&mMd5CheckSum, SIGNAL(sdgds(QByteArray)),
                this, SLOT(recvMd5CheckSumSlot(QByteArray)));

        //显示进度条
        connect(&mMd5CheckSum, SIGNAL(pressbarsignal(int,int)),
                this, SLOT(recvProgressBarSlot(int,int)));
}

Widget::~Widget()
{
    md5Thread.exit();
    md5Thread.wait(10*1000);
    delete ui;
}

void Widget::on_toolButton_clicked()
{
    QFileInfo md5FileInfo;

    fileName = QFileDialog::getOpenFileName(this,
          tr("Open File"),"F:\Qt31\lession11\MD5Tool",tr("Files (*.h *.c *.cpp *.txt "
                                                         "*.exe *.pro *.zip *.rar)"));

    md5FileInfo = QFileInfo(fileName);
    ui->plainTextEditfile->clear();
    if(md5FileInfo.exists())
    {
        ui->plainTextEditfile->insertPlainText(md5FileInfo.fileName());

//        //耗时操作放到线程中去
//        QFile file(fileName);
//        if(file.open(QIODevice::ReadOnly))
//        {
//            QCryptographicHash hash(QCryptographicHash::Md5);
//            while(!file.atEnd())
//            {
//                QByteArray content = file.read(1024*1024);//每循环一次读取1M字节
//                hash.addData(content);
//            }
//            QByteArray md5 = hash.result().toHex();
//            ui->plainTextEditMD5Passwd->insertPlainText(md5);
//            file.close();
//        }
            emit checkMd5SumSignal(fileName);
    }
}


void Widget::recvMd5CheckSumSlot(QByteArray baResult)
{
    qDebug() << "recvMd5CheckSumSlot" << baResult;
    ui->plainTextEditMD5Passwd->insertPlainText(QString(baResult));
}



void Widget::recvProgressBarSlot(int current, int total)
{
    ui->progressBar->setMaximum(total);
    ui->progressBar->setValue(current);    //顺序不能反
}
