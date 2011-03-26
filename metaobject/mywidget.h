#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
	Q_OBJECT
public:
	Q_PROPERTY(QString title READ getTitle WRITE setTitle USER true); 
	
	MyWidget(QWidget *parent = 0);
	~MyWidget();

	virtual void myVFunc(QString);
	QString myFunc(int , int);

	void setTitle(QString);
	QString getTitle();

signals:
	void onShow(int, int);

public slots:
	void responseToShow(int, int);

private:
	QString title;
};

#endif
