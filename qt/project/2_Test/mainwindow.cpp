#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QButtonGroup>
#include <QCheckBox>
#include <QCommandLinkButton>
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口大小
    setMinimumSize(500,400);
    setMaximumSize(500,400);
    test();
    redioTest();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test()
{
    //创建对象会自动在屏幕中显示
    QCheckBox *check=new QCheckBox(QString("记住密码"),this);
    //设置坐标位置
    check->setGeometry(20,50,80,50);
    //提示信息
    check->setToolTip(QString("点击之后密码就保存"));
    //设置三种状态
    check->setTristate(true);
}

void MainWindow::redioTest()
{
    //链接按钮
    QCommandLinkButton *plinkBtn=new QCommandLinkButton("下一章",this);
    plinkBtn->setGeometry(120,50,120,40);


    //单选框
    QRadioButton *preadi=new QRadioButton("苹果",this);
    preadi->setGeometry(120,100,120,20);
    QRadioButton *preadi2=new QRadioButton("梨子",this);
    preadi2->setGeometry(120,130,120,20);
    QRadioButton *preadi3=new QRadioButton("香蕉",this);
    preadi3->setGeometry(120,160,120,20);
    //按钮组
    QButtonGroup *group1=new QButtonGroup(this);
    group1->addButton(preadi);
    group1->addButton(preadi2);
    group1->addButton(preadi3);
}
