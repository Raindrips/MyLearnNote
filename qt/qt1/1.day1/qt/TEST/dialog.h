#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

 signals:
    //添加信号
    //xxxxx
public slots:
    //xxxxxxx添加槽函数

};

#endif // DIALOG_H
