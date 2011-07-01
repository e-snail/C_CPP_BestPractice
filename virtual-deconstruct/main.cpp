#include <stdlib.h>
#include <iostream>

using namespace std;

class Base
{
public:
	Base() {};
	virtual void id() {std::cout <<"Base id" <<endl; };
	virtual ~Base();
};

Base::~Base() //abstrack de-construct function 
{
	std::cout <<"Base::~Base()" <<endl;
}

class Derived : public Base 
{
public:
	Derived(){};
	virtual void id() {std::cout <<"Derived id" <<endl; };
	virtual ~Derived(){ std::cout <<"Derived::~Derived()" <<endl; };
	virtual void func();
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
	Base *b = new Derived();
	b->id();
	delete b; //if Base::~Base is not virtual, this line will output "Base::~Base()" only

	std::cout <<"---------------" <<endl;

	Derived d; //this line will output "Derived::~Derived()" and then "Base::~Base()" regard less if Base::~Base() is virtual

	return 0;
}
