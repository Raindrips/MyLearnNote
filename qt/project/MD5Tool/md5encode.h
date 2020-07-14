#ifndef MD5ENCODE_H
#define MD5ENCODE_H

#include <QObject>
#include <QCryptographicHash>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QThread>
class md5Encode : public QObject
{
    Q_OBJECT
public:
    explicit md5Encode(QObject *parent = nullptr);

signals:
    void pressbarsignal(int, int);
    void md5encodepasswdsiagnal(QByteArray);
public slots:
    void md5encodeslot(const QString &filePath);
};

#endif // MD5ENCODE_H
