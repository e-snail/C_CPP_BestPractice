#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

/*
1，想清楚为什么要什么private继承？ private继承的目的仅是为了使用父类的public和protected函数和变量吗？
2，派生类和基类之间是is-a的关系还是其他关系？
3，什么情况下可以使用private继承？ private最好用public继承+composion的形式来代替

参考文档
http://tech.163.com/05/1124/14/23B2S17F0009159Q.html
http://blog.csdn.net/wuliming_sc/article/details/3827743
*/

class Base
{
public:
	Base() {};
	void baseFunc1() { cout<<"Base::baseFunc1" <<endl; };

protected:
	void printBase() { cout<<"Base::printBase()" <<endl; };

protected:
	int protected_base;
private:
	int private_base; //private的成员变量和函数在Derived中不可用
};

class Derived : private Base
{
public:
	Derived() { derived = 100; Base::baseFunc1(); protected_base = 11; };
	void testDerived1() { printBase(); };
private:
	void printBase() { cout<<"Derived::printBase()" <<endl; }; //Base::printBase() 可以override，但是没啥意义。因为private继承的本意就是使用基类的这些函数。
private:
	int derived;
};

class FarDerived : public Derived
{
public:
	FarDerived() {};
	void testFarDerived() { 
							//baseFunc1();  //子派生类中不能访问base的方法
							//protected_base = 1; //这种procted的变量就更不能访问了
	};
};
	
int main( int argc, char **argv)
{
	Derived d;
	d.testDerived1();

	return 0;
}
