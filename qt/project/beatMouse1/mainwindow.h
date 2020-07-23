#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscence.h"
#include <QCloseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent * event);

private:
    Ui::MainWindow *ui;
    myscence *sc;


    int score;

public slots:
    void updateScore();
    void stopGame1();
};

#endif // MAINWINDOW_H
