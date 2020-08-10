#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
QObject::connect(XX,SIGNAL(XXXX),OOO,SLOT(XXXXX));
    return a.exec();
}
