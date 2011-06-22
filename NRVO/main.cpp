#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Base
{
public:
	Base(string str):m_str(str) { cout<<"Base constructor " <<m_str <<endl; };
	Base():m_str("null") { cout<<"Base constructor " <<m_str <<endl; };
	Base(Base const &b) { m_str = b.m_str; cout<<"Base copy constructor " <<m_str <<endl; };
	Base const& operator = (Base const &b) { m_str = b.m_str; cout<<"Base assign constructor " <<m_str <<endl; };
	~Base() { cout<<"Base de-constructor " <<m_str <<endl; };
private:
	string m_str;
};

Base func1()
{
	Base b = Base("yyyy");
	cout<<"-------------" <<endl;;
	return b;
//	return Base("yyy");
}

int main(int argc, char **argv)
{
	Base b = func1();  //using "g++ -fno-elide-constructors" to disable NRVO and see what compiler does
	cout<<"+++++++++++++" <<endl;;
	return 0;
}
