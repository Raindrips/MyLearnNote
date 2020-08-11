﻿#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonInsertLine_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    ui->tableWidget->insertRow(currentRow + 1);
}

void Widget::on_pushButtonDeleteLine_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(currentRow);
}

/* 写ini文件 */
void Widget::on_pushButtonExport_clicked()
{
//    QFileInfo iniFileInfo;
//    iniFileInfo = QFileInfo("teacher.ini");

    QSettings *config = new QSettings("teacher.ini", QSettings::IniFormat);
    config->setIniCodec(QTextCodec::codecForName("utf-8"));


    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        QString section = QString("teacher%1/").arg(i);
        config->beginGroup(section);
        config->setValue("name", ui->tableWidget->item(i, 0)->text());
        config->setValue("course", ui->tableWidget->item(i, 1)->text());
        config->setValue("time", ui->tableWidget->item(i, 2)->text());
        config->setValue("read", ui->tableWidget->item(i, 3)->text());
        config->endGroup();
    }
    delete config;
}

/* 读ini文件 */
void Widget::on_pushButtonImport_clicked()
{
    int currentRow;
    int currentCoumn;
    QString itemName;
    QString itemCourse;
    QString itemTime;
    QString itemRead;

    QSettings *config = new QSettings("teacher.ini", QSettings::IniFormat);
    config->setIniCodec(QTextCodec::codecForName("utf-8"));

    //不知道文件里有多少个section 假设最多有20个section
    for(int i = 0; i < 20; i++)
    {
        QString section = QString("teacher%1/").arg(i);
        if(config->value(section + "name").toString().isEmpty())
        {
            //break; //可能有空值(有section 无value)
            continue;
        }

        ui->tableWidget->insertRow(i);

        currentRow = i;
        currentCoumn = 0;
        itemName = config->value(section + "name").toString();
        ui->tableWidget->setItem(currentRow, currentCoumn,
                                 new QTableWidgetItem(itemName));


        itemCourse = config->value(section + "course").toString(); //key 得到value
        currentCoumn = 1;
        ui->tableWidget->setItem(currentRow, currentCoumn,
                                 new QTableWidgetItem(itemCourse));

        itemTime = config->value(section + "time").toString(); //key 得到value
        currentCoumn = 2;
        ui->tableWidget->setItem(currentRow, currentCoumn,
                                 new QTableWidgetItem(itemTime));

        itemRead = config->value(section + "read").toString(); //key 得到value
        currentCoumn = 3;
        ui->tableWidget->setItem(currentRow, currentCoumn,
                                 new QTableWidgetItem(itemRead));
    }

    delete config;
}
