#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLabel>
#include<QPushButton>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT  //宏的作用是启动qt5元对象的一些特性

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QLabel *label;

private:
    Ui::Dialog *ui;

#endif // DIALOG_H

};
