#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include<QCommandLinkButton>
#include<QRadioButton>
#include<QButtonGroup>
#include <QComboBox>
#include <QLineEdit>
#include <QDate>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDial>
#include<QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置窗口大小
    setMinimumSize(500,400);
    setMaximumSize(500,400);
    //setFixedSize(500,300);
    //useCheck();
    //useComboBox();
    //useLine();
    useDial();
    useSpinBox();
    useLcd();
    useProgressBar();

}

Widget::~Widget()
{
    delete ui;
}
void Widget::useCheck(){
    check=new QCheckBox(QString("记住密码"),this);
    check->setGeometry(20,50,80,50);
    //提示信息
    check->setToolTip(QString("点击之后密码就保存"));
    //设置三种状态
    check->setTristate(true);
    //槽函数 判断当前复选框的状态  选中(Qt::Checked)  未选中(Qt::UnChecked)
    //半选中(Qt::PartiallyChecked)

    //信号槽函数处理
    connect(check,SIGNAL(stateChanged(int)),this,SLOT(onChange(int)));

    QCommandLinkButton *plinkBtn=new QCommandLinkButton("下一章",this);
    plinkBtn->setGeometry(120,50,120,40);

    //单选框
    QRadioButton *preadi=new QRadioButton("苹果",this);
    preadi->setGeometry(120,100,120,20);
    QRadioButton *preadi2=new QRadioButton("梨子",this);
    preadi2->setGeometry(120,130,120,20);
    QRadioButton *preadi3=new QRadioButton("香蕉",this);
    preadi3->setGeometry(120,160,120,20);


    QRadioButton *preadi4=new QRadioButton("女",this);
    preadi4->setGeometry(120,190,120,20);
    QRadioButton *preadi5=new QRadioButton("男",this);
    preadi5->setGeometry(120,220,120,20);
    //按钮组
    QButtonGroup *group1=new QButtonGroup(this);
    group1->addButton(preadi);
    group1->addButton(preadi2);
    group1->addButton(preadi3);

    QButtonGroup *group2=new QButtonGroup(this);
    group2->addButton(preadi4);
    group2->addButton(preadi5);
}

void Widget::onChange(int sta){
    if(sta==Qt::Checked){
        qDebug()<<"现在是勾选";

    }else if(sta==Qt::Unchecked){
        qDebug()<<"现在是 非 勾选";

    }else /*if(sta==Qt::PartiallyChecked)*/{

        qDebug()<<"现在 填充 勾选";
    }

}

void Widget::useComboBox(){
    QComboBox *combobox=new QComboBox(this);
    //添加字符串
    combobox->addItem("菜单");
    combobox->addItem("文件");
    combobox->setGeometry(120,50,130,30);
    //插入数据
    combobox->insertItem(2,"yingtao");
    combobox->insertItem(1,"yingtao3");
    //设置选择项
    combobox->setCurrentIndex(1);
    //得到当前选择内容
    qDebug()<< combobox->currentText();

    //获取数目
    qDebug()<< combobox->count();

    //设置最多项目数目
    combobox->setMaxVisibleItems(4);
}


void Widget:: useLine(){
    QLineEdit *lineedit=new QLineEdit(this);
    lineedit->setGeometry(10,10,100,50);
    //在输入之前提示
    lineedit->setPlaceholderText(QString("数字，字母，$"));
    //密码框
   // lineedit->setEchoMode(QLineEdit::Password);
    lineedit->setText(QString("yingtao"));
    //设置只读
    lineedit->setReadOnly(true);

    //设置最大的长度
    lineedit->setMaxLength(5);
    //lineedit->text();
    //QTextEdit   toPlainText();

    QDate da=QDate(2017,07,25);

    // QDateEdit *detaedit=new QDateEdit(da.addYears(2),this);
    //设置日期
    QDateEdit *detaedit=new QDateEdit(QDate::currentDate(),this);

    detaedit->setGeometry(10,70,200,30);

    //设置显示格式
    detaedit->setDisplayFormat("yyyy-MM-dd");

    //弹出日期框
    detaedit->setCalendarPopup(true);

    connect(detaedit,SIGNAL(dateChanged(QDate)),this,SLOT(dtDate(QDate)));


    QTimeEdit *timeedit=new QTimeEdit(QTime::currentTime(),this);
    timeedit->setGeometry(10,120,200,30);


}
void Widget::dtDate(QDate da){
    qDebug("日期处理函数%s\n",
           da.currentDate().toString().toStdString().data());
}

void Widget:: useDial(){
    pdial=new QDial(this);
    pdial->setGeometry(10,20,200,200);
    //设置刻度
    pdial->setNotchesVisible(true);
    //设置范围
    pdial->setRange(0,200);
    //设置循环
    pdial->setWrapping(true);
    //设置位置
    pdial->setValue(100);

    connect(pdial,SIGNAL(valueChanged(int)),this,SLOT(ondialChange(int)));
}

void Widget::useSpinBox(){
    pspinbox=new QSpinBox(this);
    pspinbox->setGeometry(260,20,200,20);
    pspinbox->setRange(0,200);
    pspinbox->setValue(100);
    //加前缀
    pspinbox->setPrefix("@");
    //设置文本居中
    pspinbox->setAlignment(Qt::AlignCenter);

    connect(pdial,SIGNAL(valueChanged(int)),this,SLOT(ondialChange(int)));

}
void Widget::ondialChange(int va)
{
    qDebug()<<va;
    pspinbox->setValue(va);
}

void Widget::useLcd(){
    LcdNuber=new QLCDNumber(this);
    LcdNuber->setGeometry(260,60,200,50);
    //显示数据
    LcdNuber->display("12343");
    //设置位数
    LcdNuber->setDigitCount(10);

    //定时器
    QTimer *pt=new QTimer(this);
    pt->setInterval(1000);  //设置间隔
    connect(pt,SIGNAL(timeout()),this,SLOT(ontimeout()));
    pt->start();
}
 void Widget::ontimeout(){
     QTime p=QTime::currentTime();
     LcdNuber->display(p.toString("HH:mm:ss"));
 }

 void Widget::useProgressBar(){
     ProgressBar=new QProgressBar(this);

     ProgressBar->setGeometry(10,240,350,30);
     ProgressBar->setRange(0,200);
     ProgressBar->setValue(10);

     ProgressBar->setFormat(QString("下载安装进度条"));
     //设置反方向
     ProgressBar->setInvertedAppearance(true);

     ScrollBar=new QScrollBar(this);
     ScrollBar->setGeometry(10,280,40,300);
 }

