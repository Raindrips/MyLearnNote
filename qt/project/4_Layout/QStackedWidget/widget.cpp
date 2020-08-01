#include "widget.h"
#include "ui_widget.h"
#include <QStackedWidget>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建堆栈窗口
    QStackedWidget *stack=new QStackedWidget(this);
    //创建控件
    QLabel *plabel1=new QLabel("1 QStackedWidget");
    QLabel *plabel2=new QLabel("2 QStackedWidget");//
    QLabel *plabel3=new QLabel("3 QStackedWidget");//第三个窗口内容

    stack->addWidget(plabel1);
    stack->addWidget(plabel2);
    stack->addWidget(plabel3);

    QListWidget *ls=new QListWidget(this);
    ls->insertItem(0,"show 1QListWidget");
    ls->insertItem(1,"show 2QListWidget");
    ls->insertItem(2,"show 3QListWidget");

    QHBoxLayout *main=new QHBoxLayout(this);//
    main->addWidget(ls);
    main->addWidget(stack);

    connect(ls,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));


}

Widget::~Widget()
{
    delete ui;
}
