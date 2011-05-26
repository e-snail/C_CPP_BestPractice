#include <iostream>
#include <stdlib.h>

//http://www.cppblog.com/sunus/archive/2007/01/11/17532.html
//

class A; 

class Lock {
	friend class A; //have friendship here, so that A can access private Lock() {} in initializing
			//but in class B, Lock() is not accessable
private:
	Lock() {}; 
};

class A: virtual public Lock { //virtual public is used, so that A can not be inherited
			       //virtual public is used, so base class (class Lock)'s initialization would be depolyed
			       //if class Lock { private:Lock() {}}; is commented, this would be ok
public:
	A() {};
	A(int n) {};
};

class B: public A {
public:
	B() {};
};

int main(int argc, char **argv)
{
	return 0;
}
