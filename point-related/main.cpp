#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//******
//Point 1
//******
void Allocate(int *p)  //this can not be used to allocate memory, following 2 works
//void Allocate(int *&p)
//void Allocate(int **p)
{
	*p = 100;
	p = new int;
	*p = 2;
	cout<<"p address " <<p <<" value = " <<*p <<endl;
}

int main( int argc, char **argv)
{
	//******
	//Point 1
	//******
	int i = 1;
	int *p = &i;
	Allocate(p);
	cout<<"i address " <<&i <<" value = " <<i <<endl;
	cout<<"p address " <<p <<" value = " <<*p <<endl;

	return 0;
}


