#include "widget.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //创建分割窗口的对象
    QSplitter *Smain=new QSplitter(Qt::Horizontal,0);//水平
    QTextEdit *tLeft=new QTextEdit("左边窗口",Smain);
    //拉伸
    Smain->setStretchFactor(1,1/*0同等比例拉申，*/);

    //右侧继续分割
    QSplitter *Sright=new QSplitter(Qt::Vertical,Smain);//垂直
    QTextEdit *tright1=new QTextEdit("右边窗口1",Sright);
    QTextEdit *tright2=new QTextEdit("右边窗口2",Sright);
    Smain->show();
   // w.show();

    return a.exec();
}
