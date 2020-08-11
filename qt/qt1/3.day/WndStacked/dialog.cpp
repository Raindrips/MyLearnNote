#include "dialog.h"
#include <QStackedWidget>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //创建堆栈窗口
    QStackedWidget *stack = new QStackedWidget(this);
    //创建控件
    QLabel *plabel1 = new QLabel("第一个窗口内容.....");
    QLabel *plabel2 = new QLabel("第2个窗口内容.....");
    QLabel *plabel3 = new QLabel("第3个窗口内容.........");

    //把基本控件添加到堆栈窗口中
    stack->addWidget(plabel1);
    stack->addWidget(plabel2);
    stack->addWidget(plabel3);

    //创建一个list控件
    QListWidget * ls = new QListWidget(this);
    ls->insertItem(0,"显示第一个窗口");
    ls->insertItem(1,"显示第2个窗口");
    ls->insertItem(2,"显示第3个窗口");

    QHBoxLayout * main = new QHBoxLayout(this);
    main->addWidget(ls);
    main->addWidget(stack);

    connect(ls,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));

}

Dialog::~Dialog()
{

}
