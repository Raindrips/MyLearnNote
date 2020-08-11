#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QDate>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>  //数码框
#include <QProgressBar>
#include<QScrollBar>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:
    void useCheck();
    void useComboBox();
    void  useLine();
    void  useSpinBox();
    void useLcd();

    void useDial();
    void useProgressBar();
private:
    QCheckBox *check;
    QDial *pdial;
    QSpinBox *pspinbox;
    QLCDNumber *LcdNuber;
    QProgressBar *ProgressBar;
    QScrollBar *ScrollBar;
public slots:
    void onChange(int);  //点击复选框
    void ondialChange(int va);
    void dtDate(QDate da);

    void ontimeout();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
