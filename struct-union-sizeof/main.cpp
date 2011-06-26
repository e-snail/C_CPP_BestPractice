//#include <string.h>
//#include <stdlib.h>
//#include <iostream>

//using namespace std;

#include <stdlib.h>
#include <stdio.h>

typedef struct   s1   
{   
	char   ch,   *ptr;   
	union   
	{   
		short   a,   b;   
		unsigned   int   c:2,   d:1;   
	};
	struct s1 *p1;
}s1;

union 
{
	int a[5];
	char b;
	double c;
}A;

union
{
	int a;
	char b[2];
}B;

typedef struct s2 {
	short a;
	char b;
	int c;
};

class ClassA{ //对于ClassA的对象，总不能没有空间把 所以是1
};

class ClassB{
	public:
		void f() {}; //普通成员函数位于代码区，不占用空间
	private:
		int a;
};

class ClassC{
	public:
		virtual void f() {}; //虚函数被虚函数指针指向，所以有个指针的地址
	private:
		int a;
};

int main(int argc, char **argv)
{
	printf("%d\n", sizeof(ClassA)); 
	printf("%d\n", sizeof(ClassB));
	printf("%d\n", sizeof(ClassC)); 

//	cout <<sizeof(int) <<endl;
//	cout <<sizeof(short) <<endl;
//	cout <<sizeof(s1) <<endl;
//	cout <<sizeof(A) <<endl;

	printf("%d\n", sizeof(s1)); //16
	printf("%d\n", sizeof(A)); //20
	printf("s2 %d\n", sizeof(s2)); //16

	B.b[0] = 10;
	B.b[1] = 1;
	printf("%d\n", B.a);


	return 0;
}
