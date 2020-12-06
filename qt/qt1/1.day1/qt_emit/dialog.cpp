#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
   // QObject::connect(ui->pushButton_fp,SIGNAL(clicked(bool)),
   // ui->label_fp,SLOT(setText(QString)));

    //点击按钮后相应当前对话框的槽函数
    connect(ui->pushButton_fp,SIGNAL(clicked(bool)),
        this,SLOT(caonima()));
    //建立信号和label的槽关系
    QObject::connect(this,SIGNAL(xxxxooo(QString)),
        ui->label_fp,SLOT(setText(QString)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::caonima()
{
    //可以直接修改值
    //发送一个信号
    emit xxxxooo("danny");
}
