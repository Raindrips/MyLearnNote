#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>
#include <QFileDialog>
#include <QInputDialog>
#include <QFileInfo>
#include <QDir>
#include <QEvent>
#include <QDebug>

//编解码
//ffmpeg  使用线程进行编解码

/* 播放器core相关 */
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaList.h>    //播放列表
#include <VLCQtCore/MediaPlayer.h>  //多媒体播放器

#include <VLCQtWidgets/WidgetVideo.h>   //显示视频的窗口
#include <VLCQtWidgets/WidgetSeek.h>     //视频快进/回退
#include <VLCQtWidgets/WidgetVolumeSlider.h> //调节声音



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
    // Event handlers
    virtual void contextMenuEvent(QContextMenuEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);

private:
    void createRightPopActions();

private:
    Ui::Widget *ui;

    QMenu *popMenu;
    QAction *openLocalAction;
    QAction *openUrlAction;
    QAction *quitAction;

    //与播放器相关的....
    VlcInstance *_instance;
    VlcMediaPlayer *_player;
    VlcMedia *_media;

};

#endif // WIDGET_H
