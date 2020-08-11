#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
//视图类
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc=new myscence;
    this->ui->graphicsView->setScene(sc); //场景放在视图
    connect(this->ui->btn_start,SIGNAL(clicked()),this->sc,SLOT(startGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked()),this->sc,SLOT(pauseGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked()),this->sc,SLOT(stopGame()));
    this->score=0;
    handler *hand=handler::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(updateScore()));
    connect(this->ui->btn_stop,SIGNAL(clicked()),this,SLOT(stopGame1()));

    //connet
}

MainWindow::~MainWindow()
{
    delete ui;
}

//定时器 QTimer  1-3

/*
事件驱动

function(){
    发送信号 emit
}
绑定信号

*/
//关闭事件
void MainWindow::closeEvent(QCloseEvent * event){
    int res=QMessageBox::question(this,"确定","你真的关闭吗？","是","否");
    if(res==1){
        event->ignore();//忽略
    }

}

void MainWindow::updateScore(){
    this->score +=10;
    this->ui->lcdNumber->display(this->score);

}

void MainWindow::stopGame1(){
    this->score =0;
    this->ui->lcdNumber->display(this->score);

}
