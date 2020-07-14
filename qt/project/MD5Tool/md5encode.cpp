#include "md5encode.h"

md5Encode::md5Encode(QObject *parent) : QObject(parent)
{

}

void md5Encode::md5encodeslot(const QString &filePath)
{
    QFile file(filePath);
    QByteArray md5Result;
    QFileInfo md5FileInfo;
    md5FileInfo = QFileInfo(filePath);
//    int totalSize = md5FileInfo.size(); //Byte单位的大小
    int totalSize = md5FileInfo.size() / (1024*1024);  //把Byte转换成M
    if(md5FileInfo.size() % (1024*1024) > 0)
        totalSize = totalSize + 1;                     //解决

    int currentSize = 0;
    qDebug() << "Md5Check::getMd5CheckSumSlot " << QThread::currentThreadId();
    if(file.open(QIODevice::ReadOnly))
    {
        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd())  //文件不读完 死不退出
        {
            QByteArray content = file.read(1024*1024);
            hash.addData(content);                               //分段进行 MD5 然后累加
            currentSize++;
            emit pressbarsignal(currentSize, totalSize);  //传送百分比
        }
        md5Result = hash.result().toHex();                       //MD5值一般都为16进制
        qDebug() << "Md5Resut:" << md5Result;
        emit md5encodepasswdsiagnal(md5Result);                   //发送MD5结果
        file.close();                                            //要记得关闭文件
    }else
    {
        return;
    }
}
