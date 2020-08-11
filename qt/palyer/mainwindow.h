#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

private:
    Ui::MainWindow *ui;
    QMenu *popMenu; //右键弹出式菜单
    QAction *openLocalAction; //打开本地文件
    QAction *openUrlAction; //打开网络文件
    QAction *fullScreenAction; //全屏显示
    QAction *normalScreenAction; //普通显示
    QAction *quitAction; //退出
};

#endif // MAINWINDOW_H
