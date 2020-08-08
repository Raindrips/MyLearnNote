#ifndef WIDGET_H
#define WIDGET_H

#include <QContextMenuEvent>
#include <QMediaPlayer>
#include <QMenu>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void openLocalVideoSlot();
    void openUrlVideoSlot();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

    virtual bool eventFilter(QObject *watched, QEvent *event);
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
    //播放器对象指针
    QMediaPlayer *player;
};

#endif // WIDGET_H
