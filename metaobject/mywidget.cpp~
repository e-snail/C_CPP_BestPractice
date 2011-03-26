#include "mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
{
	connect(this, SIGNAL(onShow(int, int)), this, SLOT(responseToShow(int, int)));
	QString s = QString().fromUtf8("世界你好");
	qDebug() <<s;
}

MyWidget::~MyWidget()
{}

QString MyWidget::getTitle()
{}

void MyWidget::setTitle(QString str)
{}

void MyWidget::myVFunc(QString srt)
{
	onShow(3, 4);
}

QString MyWidget::myFunc(int a, int b)
{}

void MyWidget::responseToShow(int a, int b)
{
	qDebug() <<"hello";
	qDebug() <<this->metaObject()->className();
	QWidget *w = new QWidget(this);
	qDebug() <<w->objectName();
}
