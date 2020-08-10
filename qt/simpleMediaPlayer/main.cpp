#include "widget.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    QMediaPlayer *player = new QMediaPlayer;
    QVideoWidget *vw = new QVideoWidget;

    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("F:/Qt31/lession13/big_buck_bunny_1080p.MP4"));
    vw->setGeometry(100, 100, 640, 480);
    vw->show();

    player->play();
    return a.exec();
}
