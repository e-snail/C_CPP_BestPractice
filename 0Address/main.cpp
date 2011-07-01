#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Base
{
public:
	Base() {};
	~Base() {};
	static void print() {cout <<"Base::print" <<endl;};
};

int main(int argc, char **argv)
{
	reinterpret_cast<Base*>(0)->print();
	return 0;
}
