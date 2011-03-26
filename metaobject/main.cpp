#include <QApplication>

#include "mywidget.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	MyWidget *w = new MyWidget;
	w->myVFunc("hello");
	w->show();

	app.exec();
}
