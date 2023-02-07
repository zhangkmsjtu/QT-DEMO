#include "caishuzi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    caishuzi w;
    w.show();
    return a.exec();
}
