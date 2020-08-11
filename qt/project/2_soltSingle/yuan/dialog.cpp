#include "dialog.h"
#include "ui_dialog.h"
#include<QGridLayout>
const static double PI=3.14;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    label1=new QLabel(this);
    //label1->setText(tr("半径"));
    label1->setText("半径");
    label2=new QLabel(this);
    lineEdit=new QLineEdit(this);
    button=new QPushButton(this);
    button->setText(tr("面积"));

    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(lineEdit,1,0);
    mainLayout->addWidget(label2,0,1);
    mainLayout->addWidget(button,1,1);

    //connect(button,SIGNAL(clicked()),this,SLOT(showArea()));
    connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(showArea()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showArea(){
    QString tempStr;
    //lineEdit的值赋值给valueStr
    QString valueStr=lineEdit->text();
    //把QString转换成int
    int valueInt=valueStr.toInt();
    double area=valueInt*valueInt*PI;
    label2->setText(tempStr.setNum(area));

}
