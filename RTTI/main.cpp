#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Base
{
public:
	Base() {};
	virtual ~Base() {};
	virtual void func1() {};
};

int main(int argc, char **argv)
{
	cout <<typeid(int).name() <<endl
	     <<typeid(Base).name <<endl;
	return 0;
}


