#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked(bool)),
                     this,SLOT(add_num()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::add_num()
{
    int a = ui->lineEdit->text().toInt() ;//获取第一个框内容QString
    int b = ui->lineEdit_2->text().toInt();
    int c = a+b;
    ui->lineEdit_3->setText(QString::number(c));
}

