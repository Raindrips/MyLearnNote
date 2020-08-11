#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

public slots:
   void  TestNumType();
   void  TestString();
   void TestDateTime();
   void TestTimer();
  void  TimeProc();
};

#endif // DIALOG_H