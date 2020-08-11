#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
//    player(new QMediaPlayer),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //player = new QMediaPlayer;
    //player->setVideoOutput(ui->videoWidget);
    //createRightPopActions();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::openLocalVideoSlot()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open file"),
                                         QDir::homePath(),
                                         tr("Multimedia files(*)"));

    if (file.isEmpty())
        return;

    player->setMedia(QUrl::fromLocalFile(file));
    player->play();
}

void Widget::openUrlVideoSlot()
{

}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    Q_UNUSED(event); //未使用不警告
    popMenu->clear();

    popMenu->addAction(openLocalAction);
    popMenu->addAction(openUrlAction);
    popMenu->addAction(fullScreenAction);
    popMenu->addAction(normalScreenAction);
    popMenu->addAction(quitAction);

    popMenu->exec(QCursor::pos());//QAction *exec(const QPoint &pos, QAction *at = Q_NULLPTR);
}

void Widget::createRightPopActions()
{
    popMenu = new QMenu(this);
    popMenu->setStyleSheet("background-color: rgb(100, 100, 100);");

    openLocalAction = new QAction(this);
    openLocalAction->setText(QString::fromLocal8Bit("打开本地文件"));

    openUrlAction = new QAction(this);
    openUrlAction->setText(QString::fromLocal8Bit("打开本地文件"));

    fullScreenAction = new QAction(this);
    fullScreenAction->setText(QString::fromLocal8Bit("全屏"));

    normalScreenAction = new QAction(this);
    normalScreenAction->setText(QString::fromLocal8Bit("普通"));


    quitAction = new QAction(this);
    quitAction->setText(QString::fromLocal8Bit("退出"));

    connect(openLocalAction, SIGNAL(triggered(bool)), this, SLOT(openLocalVideoSlot()));
    connect(openUrlAction, SIGNAL(triggered(bool)), this, SLOT(openUrlVideoSlot()));
    connect(fullScreenAction, &QAction::triggered, this, &Widget::showFullScreen);
    connect(normalScreenAction, &QAction::triggered, this, &Widget::showNormal);
    connect(quitAction, &QAction::triggered, this, &Widget::close);
}
