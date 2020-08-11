#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    createRightPopActions();
    ui->avFrame->installEventFilter(this); //安装Event过滤器

    _instance = new VlcInstance(VlcCommon::args(), this);  //实例化vlc
    _player = new VlcMediaPlayer(_instance);               //new一个player 传送一个 vlc进去

    _player->setVideoWidget(ui->avFrame);      //给播放器绑定一个widget(播放视频的显示窗口)
    ui->avFrame->setMediaPlayer(_player);      //反过来

    ui->seekWidget->setMediaPlayer(_player);    //进度条
    ui->volumeSlider->setMediaPlayer(_player);  //声音


}


Widget::~Widget()
{
    delete ui;
}


void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    Q_UNUSED(event);

    popMenu->clear();
    popMenu->addAction(openLocalAction);
    popMenu->addAction(openUrlAction);
    popMenu->addAction(quitAction);

    popMenu->exec(QCursor::pos());
}


void Widget::createRightPopActions()
{
    popMenu = new QMenu(this);
    popMenu->setStyleSheet("background-color: rgb(66, 66, 66);");

    openLocalAction = new QAction(this);
    openLocalAction->setText(QString::fromLocal8Bit("打开本地文件"));

    openUrlAction = new QAction(this);
    openUrlAction->setText(QString::fromLocal8Bit("打开网络视频"));



    quitAction = new QAction(this);
    quitAction->setText(QString::fromLocal8Bit("退出"));

    connect(openLocalAction, SIGNAL(triggered(bool)),
            this, SLOT(openLocalVideoSlot()));

    connect(openUrlAction, SIGNAL(triggered(bool)),
            this, SLOT(openUrlVideoSlot()));

    connect(quitAction, &QAction::triggered,
            this, &QWidget::close);
}


bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->avFrame)
    {
        if (event->type() == QEvent::MouseButtonDblClick)
        {
            if(!ui->avFrame->isFullScreen())
            {
                ui->avFrame->setWindowFlags(Qt::Window);
                ui->avFrame->showFullScreen();
                qDebug() << "show full screen";
            }
            else
            {
                ui->avFrame->setWindowFlags(Qt::SubWindow);
                ui->avFrame->showNormal();
                qDebug() << "show normal screen";
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return Widget::eventFilter(watched, event);
    }
}


void Widget::openLocalVideoSlot()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open file"),
                                         QDir::homePath(),
                                         tr("Multimedia files(*)"));

    if (file.isEmpty())
        return;

    //本地文件 true
    _media = new VlcMedia(file, true, _instance); //准备多媒体文件
    _player->open(_media);                        //打开多媒体文件
    _player->play();                              //开始播放
}

void Widget::openUrlVideoSlot()
{
    QString url = QInputDialog::getText(this, QString::fromLocal8Bit("打开Url"),
                                        QString::fromLocal8Bit("输入网络视频地址"));
    if (url.isEmpty())
        return;

    _media = new VlcMedia(url, _instance); //准备多媒体文件
    _player->open(_media);                        //打开多媒体文件
    _player->play();                              //开始播放
}

