#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;


//    w.show();
    QWidget * window=new QWidget();
    QPushButton *button1=new QPushButton("1button");
    QPushButton *button2=new QPushButton("2button");
    QPushButton *button3=new QPushButton("3button");
    QPushButton *button4=new QPushButton("4button");
    QPushButton *button5=new QPushButton("5button");

    QHBoxLayout*playout=new QHBoxLayout();
    playout->addWidget(button1);
    playout->addWidget(button2);
    playout->addWidget(button3);
    playout->addWidget(button4);
    playout->addWidget(button5);
    playout->setAlignment()
    //playout->setMargin(40);  //上下左右都会设置
    playout->setContentsMargins(50,15,40,50);//左上右下
    playout->setSpacing(20); //设置控件之间的位置


    window->setLayout(playout);
    window->show();
    return a.exec();
}
