#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "base.h"

using namespace std;


int main(int argc, char **argv)
{
	Base b;
	cout << b.getVariable() <<endl;

	function_set(111);
	cout << function() <<endl;

	//n1 = 111;
	//cout << n1 <<endl;

	return 0;
}
