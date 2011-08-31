#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


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

	union {
		struct ST { 
			char str[0];
		}s0;
		struct ST1 { 
		}s1;
	}s0;

union V {
	struct X {
		unsigned char s1:2;
		unsigned char s2:3;
		unsigned char s3:3;
	}x;
	int c;
	//unsigned char c;
}v;

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

typedef struct s3 {
	int n : 16;
	int m : 16;
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
	printf("s3 %d\n", sizeof(s3)); //16

	B.b[0] = 10;
	B.b[1] = 1;
	printf("B.a %d\n", B.a);

	char array[] = "ABC";
	char array2[] = "B\0A";
	printf("******* %s %d\n", array, sizeof(array));
	printf("+++++++ %s %d\n", array2, sizeof(array2));
	printf("+++++++  %s %d\n", array2, strlen(array2));
	strcpy(array, array2);
	int a[5];
	int *p = a;
	printf("******* %p : %p\n", &a, p);
	printf("******* %d\n", a[3]);
	for (int i=0; i <5; i++) {
		*p = i+1;
	}
	printf("******* %d\n", sizeof(a));
	printf("******* %d\n", a[3]);
	printf("******* %p\n", a);
	printf("******* %p\n", &a[0]);
	printf("******* %p\n", &a[1]);

	char aaaa[0];
	printf("******* %d\n", sizeof(aaaa));

	cout <<"-------- " <<sizeof(s0);
	printf("%d\n", sizeof(s0));

	char c = 'a';
	typeof(c) cc = 45;
	printf("%c\n", cc);

	v.c = 100;
	printf("%d %d %d\n", v.x.s1, v.x.s2, v.x.s3);

	return 0;
}
