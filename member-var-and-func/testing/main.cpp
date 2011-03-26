#include <QtGui/QApplication>
#include "mainwindow.h"

#include "base.h"
#include "derived.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Derived *d = new Derived;
    delete d;

    return a.exec();
}
