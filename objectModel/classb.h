#include <stdio.h>
#include <iostream>

using namespace std;

class ClassB {
public:
	virtual void funcB() { cout << "ClassB::b " <<b <<endl; };
private:
	int b;
};
