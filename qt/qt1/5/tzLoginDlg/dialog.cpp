#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->pushButtonPhone->setChecked(true);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    this->hide();
}

void Dialog::on_pushButtonPhone_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButtonAccount_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
