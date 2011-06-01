#include <stdlib.h>
#include <iostream>

using namespace std;

class Base
{
public:
	Base() {};
	virtual ~Base() = 0;
};

Base::~Base() //abstrack de-construct function 
{
	std::cout <<"Base::~Base()" <<endl;
}

class Derived : public Base 
{
public:
	Derived(){};
	~Derived(){ std::cout <<"Derived::~Derived()" <<endl; };
	virtual void func() = 0;
};

void Derived::func()
{
	std::cout <<"Derived::~func()" <<endl;
}

class DeepDerived : public Derived
{
	void func() { std::cout <<"DeepDerived::func()" <<endl; };
};

int main(int argc, char **argv)
{
	DeepDerived d;
	return 0;
}
