#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QTextCodec>
#include <QDebug>
#include <QXmlStreamWriter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //设置各行变色
    ui->tableWidget->setAlternatingRowColors(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    quint16 currentrow = ui->tableWidget->currentRow();//获取当前行索引

    ui->tableWidget->insertRow(currentrow + 1);
}

void MainWindow::on_pushButton_3_clicked()
{
     quint16 currentrow = ui->tableWidget->currentRow();//获取当前行索引
     ui->tableWidget->removeRow(currentrow);//删除当前行
}

void MainWindow::on_pushButton_4_clicked()
{

    QTableWidgetItem  *item  =  new  QTableWidgetItem();
    int  currentRow  =  ui->tableWidget->currentRow();
    int  currentColumn  =  ui->tableWidget->currentColumn();
    item->setText("我是新的item");
    ui->tableWidget->setItem(currentRow,  currentColumn,  item);
}

void MainWindow::on_pushButton_5_clicked()
{
     QDir  iniDir;
     QString  iniPathString;
     QFileInfo  iniFileInfo;
     QString  itemName;
     int  currentRow;
     int  currentColumn;
     iniPathString = QString("F:/Qt10006/lession10/tablewidgetdemo/teacher.ini");
     iniFileInfo  =  QFileInfo(iniPathString);
     if(iniFileInfo.exists()) //如果ini文件存在22
     {
         QSettings  *config  =  new  QSettings(iniPathString, QSettings::IniFormat);
         config->setIniCodec(QTextCodec::codecForName("utf‐8"));  //告诉Qt  i 25
         //qDebug()<<iniPathString;
         //读ini文件
         for(int i = 0; i < 10; i++) //假设最大十个section
         {
             QString  section  =  QString("teacher%1/").arg(i);
             //判断文件是否为空
             if(config->value(section + "name").toString().isEmpty()) {

                 continue;//空数据不做处理
               }
         qDebug()<< config->value(section  +  "name").toString()
                     << config->value(section  +  "course").toString()
                     << config->value(section  +  "time").toString();

             currentRow = 0;
             //ui->tableWidget->insertRow(i);
             itemName  =  config->value(section  +  "name").toString();
             currentColumn  =  0;
             ui->tableWidget->setItem(currentRow,  currentColumn,
                                      new  QTableWidgetItem(itemName));//把读到ini文件属性设置到表格控件
             currentRow = i;
             //ui->tableWidget->insertRow(i);
             itemName  =  config->value(section  +  "course").toString();
             currentColumn  =  1;
             ui->tableWidget->setItem(currentRow,  currentColumn,
                                      new  QTableWidgetItem(itemName));//把读到ini文件属性设置到表格控件
             //ui->tableWidget->insertRow(i);
             itemName  =  config->value(section  +  "time").toString();
             currentColumn  =  2;
             ui->tableWidget->setItem(currentRow,  currentColumn,
                                      new  QTableWidgetItem(itemName));//把读到ini文件属性设置到表格控件
         }

     }

}

void MainWindow::on_pushButton_6_clicked()
{
    QFile  file("./testWrite.xml");
    if (!file.open(QFile::WriteOnly  |  QFile::Text))
    {
        return ;
    }
    QXmlStreamWriter  stream(&file);
    stream.setCodec(QTextCodec::codecForName("utf‐8"));  //设置为utf‐8编码
    stream.setAutoFormatting(true);
    stream.writeStartDocument();  //文档开始
    stream.writeStartElement("teachers");  //teachers

    /* 老 王 */
    stream.writeStartElement("teacher");
    stream.writeAttribute("id",  "01");
    stream.writeAttribute("time",  "12:00");
    stream.writeTextElement("name",  QString("老王"));
    stream.writeTextElement("book",  QString("金瓶梅"));
    stream.writeEndElement();

    /* 夏 七 */
    stream.writeStartElement("teacher");
    stream.writeAttribute("id",  "03");
    stream.writeAttribute("time",  "19:00");
    stream.writeTextElement("name",  QString("夏七"));
    stream.writeTextElement("book",  QString("红楼梦"));
    stream.writeEndElement();

    stream.writeEndElement();
    stream.writeEndDocument();
    file.close();
}
