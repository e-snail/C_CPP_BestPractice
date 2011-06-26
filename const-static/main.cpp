#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int n = 222;

int main( int argc, char **argv)
{
	int const a = 100;
	int *p = (int*)(&a);
	*p = 111;
	cout <<"a = " <<a <<endl;
	cout <<"*p = " <<*p <<endl; //result diff with upper one, 'cause compilor reallocate space for p when "int *p = (int*)(&a);
	//free(p);  //space are allocate in stack, so free() is not neccesary

	p = (int*)(&n);
	*p = 333;
	cout <<"n = " <<n <<endl;
	cout <<"*p = " <<*p <<endl; //result same with upper one, compilor does not allocate space for p 

	return 0;
}


