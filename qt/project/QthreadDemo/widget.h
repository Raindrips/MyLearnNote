#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"

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
    void startmytreadsignal();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    MyThread mythread;
    QThread  md5Thread;

};

#endif // WIDGET_H
