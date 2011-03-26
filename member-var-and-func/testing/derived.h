#ifndef DERIVED_H
#define DERIVED_H

#include <QDebug>

#include "base.h"

class Derived : public Base
{
public:
    Derived();
    ~Derived();

private:
    const int n;
    static int mm;
    static const int zzz;
};

//int Derived::mm = 111;
//const int Derived::zzz = 222;

#endif // DERIVED_H
