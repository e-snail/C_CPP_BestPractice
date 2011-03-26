#include "derived.h"

#include <QDebug>

Derived::Derived()
    :n(100)
{
    qDebug() <<"Derived Constructor";
    qDebug()<<" n = " <<n;
    qDebug()<<" mm = " <<mm;
}

Derived::~Derived()
{
    qDebug() <<"Derived Des-constructor";
}
