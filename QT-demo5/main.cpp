#include "maprun.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    maprun w;
    w.show();
    return a.exec();
}
