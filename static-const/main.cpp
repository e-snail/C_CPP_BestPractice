#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Integer
{
	public:
		Integer():m_lng(100){}
		long m_lng;
};

int main( int argc, char **argv)
{
	const int a = 2;
	int *p = const_cast<int*>(&a);
	*p = 100;
	cout <<a <<endl;
	cout <<*p <<endl;

	const Integer c1;
	Integer *c2 = const_cast<Integer*>(&c1);
	c2->m_lng = 111;
	cout <<c1.m_lng <<endl;
	cout <<c2->m_lng <<endl;

	//***
	int abc = 100;
	int abcdef = 111;
	const int ccc = 444;

	//const int* pA = &ccc;
	const int* pA = &abc;
	int* const pAD = &abc;
	//*pA = 111; //WRONG!
	pA = &abcdef;

	*pAD = 222;
	//*pAD = &abcdef; //WRONG
	
	cout <<*pA <<endl;

	return 0;
}

