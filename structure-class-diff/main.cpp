#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//------------------------------
// Point is marked by **Number**
//------------------------------

struct Base {
	Base() { cout<<"struct Base::Base() " <<endl; }
	unsigned int color;
	
	Base operator += (const Base &a) {
		Base b;
		b.color = this->color + a.color;
		return b;
	}
};

//---------------------------------------------------------------
// **1** struct can use "virtual inherit" and also general inherit
//---------------------------------------------------------------
struct C1: virtual public Base {}; 
struct C2: virtual public Base {};
struct C3: public Base {};
struct C4: public Base {};

struct Derived : public C1, public C2, public C3, public C4 {};
	

int main( int argc, char **argv)
{
	Derived d;

	return 0;
}
