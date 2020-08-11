#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include <QMenu>
#include <QFileDialog>
#include <QFile>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


public slots:
    void openLocalVideoSlot();
    void openUrlVideoSlot();
protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);


private:
    void createRightPopActions();

private:
    Ui::Widget *ui;

    QMenu *popMenu; //右键弹出式菜单
    QAction *openLocalAction; //打开本地文件
    QAction *openUrlAction; //打开网络文件
    QAction *fullScreenAction; //全屏显示
    QAction *normalScreenAction; //普通显示
    QAction *quitAction; //退出

    QMediaPlayer *player;
//    QVideoWidget *vw;
};

#endif // WIDGET_H
