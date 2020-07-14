#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool connectdatabase(void);
private slots:
    void on_pushButton_query_clicked();

    void on_pushButton_query_2_clicked();

    void on_pushButton_query_3_clicked();

    void on_pushButton_query_4_clicked();

    void on_pushButton_query_5_clicked();

    void on_pushButton_query_7_clicked();

    void on_pushButton_query_6_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;//创建数据视图显示模型
};

#endif // MAINWINDOW_H
