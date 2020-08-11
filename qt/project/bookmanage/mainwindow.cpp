#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlRecord>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    if(model){
       delete model;
        model = nullptr;
    }
    delete ui;
}

bool MainWindow::connectdatabase()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.238.132");//连接数据库主机名，这里需要注意（若填的为”  127.0.0.1“，出现不能连接，则改为localhost)
    db.setPort(3306);                 //连接数据库端口号，与设置一致
    db.setDatabaseName("mysql");      //连接数据库名，与设置一致
    db.setUserName("root");          //数据库用户名，与设置一致
    db.setPassword("1");    //数据库密码，与设置一致

    //判断该数据是否已打开
    if(db.isOpen())
    {
        //返回true说明数据库已经打开
        qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
        return false;
    }else{
        //返回false数据库没被打开接下来打开数据库
        if(!db.open())
        {
            //打开数据库失败
            return false;
        }
    }
    //数据连接成功
    // 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
    QSqlQuery query(db);
    query.exec("SET NAMES 'Latin1'");//设置数据库字符集编码
//    //执行查询数据表的语法
//    query.exec("select * from student");
//    while(query.next()){
//        qDebug()<<query.value("ID").toString();
//    }
    // 创建 course 表
    query.exec("create table bookmanage (id int primary key,name varchar(20), book varchar(20))");

    query.exec("insert into bookmanage values(0, '计算机类', '计算机组')");//往当前数据库bookmanage表插入数据
    query.exec("insert into bookmanage values(1, '软件工程类', '数据结构')");
    query.exec("insert into bookmanage values(2, '电子修理类', '电工基础')");

    return true;
}

void MainWindow::on_pushButton_query_clicked()
{
    //设置模型
     model = new QSqlTableModel(this);

     //指定查哪张表
     model->setTable(ui->lineEdit->text());

     //设置tableview的model(这样还没有数据)
     ui->tableView->setModel(model);

     //显示查询的数据
     model->select();

     //修改列的属性名
     model->setHeaderData(1,Qt::Horizontal,"书籍类别");//设置第一列列名
     model->setHeaderData(2,Qt::Horizontal,"书名");//设置第二列列名

    //手动修改方式
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);

     //view 不让修改 权限 管理
     ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void MainWindow::on_pushButton_query_2_clicked()
{
    //首先要链接数据
    connectdatabase();
}

void MainWindow::on_pushButton_query_3_clicked()
{
    // 开始事务操作
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit(); //提交
     } else {
       model->database().rollback(); //回滚
       QMessageBox::warning(this, tr("tableModel"),
       tr("数据库错误: %1").arg(model->lastError().text()));
    }
}

//往指定表插入一条数据
void MainWindow::on_pushButton_query_4_clicked()
{
    //增加一行空记录
    QSqlRecord record = model->record();

    //设置行号
    int row = model->rowCount();//获取行号
    qDebug()<<"row:"<<row;
    model->insertRecord(row,record);
}

void MainWindow::on_pushButton_query_5_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();
    // 删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                 tr("你确定删除当前行吗？ "),QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    { // 如果不删除， 则撤销
      model->revertAll();
    } else { // 否则提交， 在数据库中删除该行
      model->submitAll();
    }
}

void MainWindow::on_pushButton_query_7_clicked()
{
    //id 属性， 即第 0 列， 升序排列
    model->setSort(0, Qt::DescendingOrder );
    model->select();
}

void MainWindow::on_pushButton_query_6_clicked()
{
    //id 属性， 即第 0 列， 降序排列
    model->setSort(0, Qt::AscendingOrder);
    model->select();
}
