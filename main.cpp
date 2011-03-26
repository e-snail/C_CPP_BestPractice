#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Base
{
	public:
		virtual void print() {cout <<"Base::print" <<endl;};

	static void func() {};
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

	return 0;
}
