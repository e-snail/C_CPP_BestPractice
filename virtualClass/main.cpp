#include <iostream>
using namespace std;

class A 
{
	public:
		//A(){ cout <<__FUNCTION__<<endl;};
		virtual ~A() = 0 
		{ cout <<__FUNCTION__<<endl;}
	protected:
};

class B: public A
{
	//public:
		//~B() { cout <<__FUNCTION__ <<endl;};
};

int main(int argc, char** argv)
{
	B *pB = new B; 
	delete pB;

	return 0;
}
