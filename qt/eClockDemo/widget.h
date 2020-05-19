#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QToolTip>
#include <QDebug>
#include <QMenu>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QSystemTrayIcon>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void contextMenuEvent(QContextMenuEvent *event);
    virtual void paintEvent(QPaintEvent *event);

private:
    void createRightPopActions();

private:
    Ui::Widget *ui;
    QPoint mouseWindowTopLeft; //鼠标相对窗口左上角的坐标         在mousePressEvent 得到
    QPoint mouseDeskTopLeft;   //鼠标相对于桌面左上角坐标         在mouseMoveEvent实时获取
    QPoint windowDeskTopLeft;  //窗口左上角相对于桌面左上角坐标    在mouseMoveEvent实时计算(矢量)获得

    QMenu *popMenu;               //右键弹出式菜单
    QAction *adjustTimeAction;    //右键弹出式菜单中的内容
    QAction *adjustDateAction;
    QAction *quitAction;
    QTimer *rtTimer;
};

#endif // WIDGET_H
