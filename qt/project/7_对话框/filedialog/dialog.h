#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QColorDialog>
#include <QFontDialog>

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
    //标准文件对话框
    QPushButton *filebtn;
    QLineEdit *filelineedit;
    QGridLayout *layout;

    //标准颜色对话框
    QPushButton *colorBtn;
    QFrame *colorFrame;


    //标准字体对话框
    QPushButton *fontbtn;
    QLineEdit *fontlineedit;



public slots:
    void FileDlg();
    void colorDia();
    void fontDia();


};

#endif // DIALOG_H
