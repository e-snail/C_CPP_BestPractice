#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Base
{
public:
	Base() { cout<<"constructor" <<endl; };
	Base(const Base &b)  { cout<<"copy constructor" <<endl; };
	Base operator=(const Base &b)  { cout<<"assign constructor" <<endl; };
	~Base() { cout<<"des constructor" <<endl; };
};

Base func()
{
	return Base();
}

int main(int argc, char **argv)
{
//	Base b, c(b);
//	b = c;
	cout<<"-----------------" <<endl;
	Base d = func();

	return 0;
}
