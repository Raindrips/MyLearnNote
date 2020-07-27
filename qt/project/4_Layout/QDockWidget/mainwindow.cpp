#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextEdit>
#include <QDockWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextEdit *tLeft=new QTextEdit(QString("MainWindow"),this);
    setCentralWidget(tLeft); //设置居中
    QDockWidget *dock=new QDockWidget("停靠窗口1",this);
    //设置窗口的属性
    dock->setFeatures(QDockWidget::DockWidgetMovable/*移动*/|QDockWidget::DockWidgetFloatable/*漂浮*/);
    //设置停靠区域
    dock->setAllowedAreas(Qt::LeftDockWidgetArea/*左侧*/);  //设置停靠区域
    QTextEdit *tskt=new QTextEdit();
    tskt->setText("MainWindow1");
    dock->setWidget(tskt);
    addDockWidget(Qt::RightDockWidgetArea,dock);//默认停靠位置

    QDockWidget *dock2=new QDockWidget("停靠窗口2",this);
    QTextEdit *tskt2=new QTextEdit();
    tskt2->setText("MainWindow2");
    dock2->setWidget(tskt2);
    addDockWidget(Qt::LeftDockWidgetArea,dock2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
