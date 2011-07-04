#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Base
{
	public:
		Base () {};
		virtual void func() { cout<<"Base::func" <<endl; };
		~Base () {};
	private:
		int a;
};

class Derived 
{
	public:
		Derived() {};
		virtual void func() { cout<<"Derived::func" <<endl; };
};
	
int main( int argc, char **argv)
{
	char *p = new char[sizeof(Base)];
	
	Base *pB = new(p) Base;
	pB->func();

	pB->~Base(); // this will only destroy object, mem space reminds

	delete p;

	return 0;
}
