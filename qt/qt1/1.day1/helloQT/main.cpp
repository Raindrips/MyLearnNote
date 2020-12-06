#include <qapplication.h>
#include <QtWidgets>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QDialog w;
    w.show();
    return a.exec();
}
