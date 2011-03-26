#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Base
{
	public:
		virtual void print() {cout <<"Base::print" <<endl;};
};

class Drived : public Base 
{
	public:
		void print() {cout <<"Drived::print" <<endl; }; // cout <<__PRETTY_FUNCTION__<<endl; };
};

void printf(Base &b)
{
	b.print();
}

void printf1(Base b)
{
	b.print();
}

int main( int argc, char **argv)
{

	Base b, *pb;
	Drived d;
	pb = &d;
	pb->print();

	printf(b);
	printf(d);
	printf1(d);

	b = d;
	b.print();

	return 0;
}
