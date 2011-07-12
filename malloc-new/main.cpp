#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Base
{
	public:
		void foo() { delete this; }; // delete won't do any harm to only if "this" no longer be operated
};

int main(int argc, char **argv)
{
	Base *b = new Base;
	b->foo();

	return 0;
}

