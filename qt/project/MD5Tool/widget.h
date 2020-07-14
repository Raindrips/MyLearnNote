#ifndef WIDGET_H
#define WIDGET_H

#include <QThread>
#include <QWidget>
#include "md5encode.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void checkMd5SumSignal(const QString &filePath);
private slots:
    void on_toolButton_clicked();
    void recvMd5CheckSumSlot(QByteArray baResult);
    void recvProgressBarSlot(int current, int total);
private:
    Ui::Widget *ui;
    QString fileName;
    md5Encode mMd5CheckSum;
    QThread md5Thread;
};

#endif // WIDGET_H
