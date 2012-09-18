#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class A
{
	int a;
};

class B : private A {
	B(A *a) {};
	int b;
};

class C : private B {
	C(A* a) {};
	int c;
};

int main(int argc, char **argv)
{
	return 0;
}
