#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //标准文件对话框
    filebtn=new QPushButton(this);
    filebtn->setText("打开标准文件对话框");
    filelineedit=new QLineEdit(this);

    layout=new QGridLayout(this);
    layout->addWidget(filebtn,0,0);
    layout->addWidget(filelineedit,0,1);
    connect(filebtn,SIGNAL(clicked()),this,SLOT(FileDlg()));

    //标准颜色对话框
    colorBtn=new QPushButton(this);
    colorBtn->setText("打开标准颜色对话框");
    colorFrame=new QFrame(this);
    colorFrame->setFrameShape(QFrame::Box);  //设置外形
    colorFrame->setAutoFillBackground(true);//设置背景色  自动填充

    layout->addWidget(colorBtn,1,0);
    layout->addWidget(colorFrame,1,1);
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(colorDia()));

    //标准字体对话框
    fontbtn=new QPushButton(this);
    fontbtn->setText("打开标准字体对话框");
    fontlineedit=new QLineEdit(this);
    fontlineedit->setText("yingtao");
    layout->addWidget(fontbtn,2,0);
    layout->addWidget(fontlineedit,2,1);
    connect(fontbtn,SIGNAL(clicked()),this,SLOT(fontDia()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::FileDlg(){
    QString str=QFileDialog::getOpenFileName
            (this,"标准文件对话框","./","文件(*.txt *.h *.cpp)");
    filelineedit->setText(str);

}

void Dialog::colorDia(){

    QColor qc=QColorDialog::getColor(Qt::white,this);

    if(qc.isValid()){ //判断是否有值，当前颜色是否符合条件
        colorFrame->setPalette(qc); //把选择的颜色填充在窗体上

    }

}

void Dialog::fontDia(){
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok){
        fontlineedit->setFont(font);
    }

}
