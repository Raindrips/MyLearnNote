#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QInputDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //右键弹出菜单
    createRightPopActions();

    player = new QMediaPlayer;
    player->setVideoOutput(ui->avwidget);

    ui->avwidget->installEventFilter(this); //安装Event过滤器
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
    qDebug()<<  file;

    player->play();

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

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->avwidget)
    {
        if (event->type() == QEvent::MouseButtonDblClick)
        {
            if(!ui->avwidget->isFullScreen())
            {
                ui->avwidget->setWindowFlags(Qt::Window);
                ui->avwidget->showFullScreen();
                qDebug() << "show full screen";
            }
            else
            {
                ui->avwidget->setWindowFlags(Qt::SubWindow);
                ui->avwidget->showNormal();
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

void Widget::openUrlVideoSlot()
{
    QString url = QInputDialog::getText(this, QString("打开Url"),
                                        QString("输入网络视频地址"));
    if (url.isEmpty())
        return;

    player->setMedia(QUrl::fromLocalFile(url));
    qDebug()<<  url;

    player->play();

}

void Widget::createRightPopActions()
{
    popMenu = new QMenu(this);
    popMenu->setStyleSheet("background-color: rgb(100, 100, 100);");

    openLocalAction = new QAction(this);
    openLocalAction->setText(QString("打开本地文件"));

    openUrlAction = new QAction(this);
    openUrlAction->setText(QString("打开网络直播"));

    fullScreenAction = new QAction(this);
    fullScreenAction->setText(QString("全屏"));

    normalScreenAction = new QAction(this);
    normalScreenAction->setText(QString("普通"));


    quitAction = new QAction(this);
    quitAction->setText(QString("退出"));

    connect(openLocalAction, SIGNAL(triggered(bool)), this, SLOT(openLocalVideoSlot()));
    connect(openUrlAction, SIGNAL(triggered(bool)), this, SLOT(openUrlVideoSlot()));
    connect(fullScreenAction, &QAction::triggered, this, &Widget::showFullScreen);
    connect(normalScreenAction, &QAction::triggered, this, &Widget::showNormal);
    connect(quitAction, &QAction::triggered, this, &Widget::close);
}
