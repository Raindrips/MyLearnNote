#include "dialog.h"
#include <QApplication>
#include<QLabel>
#include<QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dialog w;
//    w.show();
    QLabel label("yingtao");
    label.show();

    QPushButton buton("关闭");
    buton.show();

//    QObject::connect(&buton,SIGNAL(clicked()),
//                                   &label,SLOT(close()));

//    QObject::connect(&buton,SIGNAL(clicked()),
//                                   &buton,SLOT(close()));
        QObject::connect(&buton,&QPushButton::clicked,
                                       &label,&QLabel::close);

        QObject::connect(&buton,SIGNAL(clicked()),
                                       &buton,SLOT(close()));
    return a.exec();
}
