#ifndef DIALOG_H
#define DIALOG_H
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
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
//signals:  //信号函数标签
//    void sigfun();

public slots:  //槽函数标签
    void showArea();

private:
    Ui::Dialog *ui;
    QLabel *label1,*label2;
    QLineEdit *lineEdit;
    QPushButton* button;
};

#endif // DIALOG_H
