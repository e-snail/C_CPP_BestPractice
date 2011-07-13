#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Base
{
public:
	Base() {};
	~Base() {};
	static void print() {cout <<"Base::print" <<endl;};
};

typedef struct {
	char a;
	short c;
	char b;
	int d;
	double e;
}A;

int main(int argc, char **argv)
{
	//用法 1
	reinterpret_cast<Base*>(0)->print();

	//用法 2
    cout <<"A:a	" <<(size_t)&(((A*)(0))->a) <<endl;
    cout <<"A:b	" <<(size_t)&(((A*)(0))->b) <<endl;
    cout <<"A:c	" <<(size_t)&(((A*)(0))->c) <<endl;
    cout <<"A:d	" <<(size_t)&(((A*)(0))->d) <<endl;
    cout <<"A:e	" <<(size_t)&(((A*)(0))->e) <<endl;
    cout <<"A size	" <<sizeof(A) <<endl;

	return 0;
}
