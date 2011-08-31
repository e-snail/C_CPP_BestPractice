#include <QtGui/QApplication>
 #include "mainwindow.h"

#include  <QPushButton>
#include <QLabel>
#include <QBitmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
