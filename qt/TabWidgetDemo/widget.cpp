#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->insertColumn(2);
    ui->tableWidget->insertRow(1);



}

Widget::~Widget()
{
    delete ui;
}

//插入一行
void Widget::on_pushButtonInsertLine_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    ui->tableWidget->insertRow(currentRow + 1);
}

//删除一行
void Widget::on_pushButtonDeleteLine_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(currentRow);
}

//修改某一行
void Widget::on_pushButtonRemakeItem_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    int currentColumn = ui->tableWidget->currentColumn();
    QString itemStr = ui->lineEdit->text();
    ui->tableWidget->setItem(currentRow, currentColumn,
                             new QTableWidgetItem(itemStr));
}

void Widget::on_pushButtonQueryItem_clicked()
{
    qDebug()<< ui->tableWidget->currentItem();
}
