#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Base
{
	public:
		virtual void print() {cout <<"Base::print" <<endl;};

	static void func() {};
	void testFunc() const {};

	//int modify() const { x = 10;  return x; }
private:
	int x;
};

class Drived : public Base 
{
	public:
		Drived():nn(100) {};
		void print() {cout <<"Drived::print" <<endl; cout <<__PRETTY_FUNCTION__<<endl; };

		void changeStaticVar( int n) { mm = n; };
		int  displayStaticVar() {cout <<"mm is " << mm <<endl; };

		void test(int x)
		{
			int n = 0;
			while (x != 0)
			{
				n++;
				x = x & (x-1);
			}
			cout <<"n = " <<n <<endl;
		}

	private:
		static int mm;
		const int nn;
		const static int xxx;
		static const int yyy;
};

class D{
};

int Drived::mm = 100;
const int xxx = 111;
const int yyy = 123;

void print(Base* b)
{
	b->print();
}

class OtherBase {
	public:
	OtherBase() { cout <<"OtherBase Initialization" <<endl; };
};
OtherBase b;

void AllocMemory(char **p, int num)
{
	*p = (char *) malloc(num);
}

void test1(int a, int b=1, int c=0)
{}

class Test 
{
	int x;
public:
	Test() {x=0;}
	void mod() {
		x=10;
		printf("Test x = \n");
		delete this;
		printf("Test END x=%d\n", x);
	}
	static void func1() { y++; };
	void func() { func1(); cout <<"xxxxx " <<y <<endl; };
	static int y;
};
int Test::y = 1;

//******
//Point 1
//******
void Allocate(int *p)
{
	cout<<"p address " <<p <<" value = " <<*p <<endl;
	p = new int;
	cout<<"p address " <<p <<" value = " <<*p <<endl;
	*p++ = 2;
	cout<<"p address " <<p <<" value = " <<*p <<endl;
}

int main( int argc, char **argv)
{
	cout <<" line 1 in main function" <<endl;
	/*
	 *testing 16bit or 32bit merchine
	 */
	/*
	int i = 65536;
	cout <<i <<endl;
	i = 65535;
	cout <<i <<endl;
	*/

	Base b, *pb;
	Drived d;
	print(&b);
	print(&d);

	d.changeStaticVar(111111);
	Drived dd;
	dd.displayStaticVar();

	//static const string mystr[]={"hello"" world"};
	//cout<<mystr[0] <<mystr[0];

	//if (!string::strcmp(mystr[0], mystr[1]))
	//	cout <<"Yes!" <<endl;

	{
	//about const 
		char c1='a';
		char c2='b';
		char const * p1;
		char * const p2 = &c2; //p2必须有初始值
		const char * p3; //p1与p3相同

		p1 = &c1;
		p3 = &c1;
		//*p1 = c2; //错误，p1指向的指不能改变
		//p2 = &c1; //错误, p2指向的地址不能改变
	}

	char *str = (char *)malloc(10);
   	//"hello world";
	str[0] = 'j';
	cout <<"str = " <<str <<endl;

	cout << sizeof(Base) <<endl;

	int tmp[10];
	cout << sizeof(tmp) <<endl;

	d.test(9999);

	cout <<"size of an empty class : "<<sizeof(D) <<endl;

	char hello[] = "hello world";
	cout <<sizeof(hello) <<endl;

	char *pp[] = {"http", "www", "kaixin001", "com"};
	char *pp1 = pp[1] + 1;
	cout <<pp1 <<endl;

	int a[2][2] = {{1},{2,3}};
	cout <<a[0][1] <<endl;

	char *straaa = NULL;
	AllocMemory(&straaa, 100);
	strcpy(straaa, "hello");

	printf("\n str is %s\n", straaa);
	free (straaa);

	char *nnn = new char[100];
	strcpy(nnn, "11111");
	delete []nnn;

	//test1();
	test1(0);
	test1(0, 0);
	test1(0, 0, 0);

	Test *t = new Test();
	t->mod();
	t->func();

	cout <<"---------------------------" <<endl;
	char abcd[] = "String";
	char *pA = "New String";
	char *temp;
	temp = abcd;
	printf("address of char[] abcd %p\n", abcd);
	int abcdef = 0;
	printf("address of int abcdef %p\n", &abcdef);
	//abcd = (char *)malloc(strlen(pA) + 1);
	//strcpy(abcd, pA);	
	pA = (char *)malloc(strlen(temp) + 1);
	strcpy(pA, temp);
	printf("(%s, %s)\n", abcd, pA);
//	free(pA);
//	free(abcd);

	int *p = 0;
	delete p;

//******
//Point 1
//******
	int i = 1;
	Allocate(&i);
	cout<<"i address " <<&i <<" value = " <<i <<endl;

	return 0;
}
