#include "c.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    c w;
    w.show();

    return a.exec();
}
