#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
       popMenu = new QMenu(this);
       popMenu->setStyleSheet("background-color: rgb(100, 100, 100);");

       openLocalAction = new QAction(this);
       openLocalAction->setText(QString::fromLocal8Bit("打开本地文件"));

       openUrlAction = new QAction(this);
       openUrlAction->setText(QString::fromLocal8Bit("打开本地文件"));

       fullScreenAction = new QAction(this);
       fullScreenAction->setText(QString::fromLocal8Bit("全屏"));

       normalScreenAction = new QAction(this);
       normalScreenAction->setText(QString::fromLocal8Bit("普通"));


       quitAction = new QAction(this);
       quitAction->setText(QString::fromLocal8Bit("退出"));
}
