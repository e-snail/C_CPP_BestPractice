#include <iostream>
#include <stdlib.h>

using namespace std;

//--------------------------------------------------------------
//Test Code 1: 虚继承用在创建不可被继承的类的例子 
//--------------------------------------------------------------

//http://www.cppblog.com/sunus/archive/2007/01/11/17532.html
//

class A; 

class Lock {
	friend class A; //have friendship here, so that A can access private Lock() {} in initializing
			//but in class B, Lock() is not accessable
private:
	Lock() {}; 
};

class A: virtual public Lock { //virtual public is used, so that A can not be inherited
			       //virtual public is used, so base class (class Lock)'s initialization would be depolyed
			       //if class Lock { private:Lock() {}}; is commented, this would be ok
public:
	A() {};
	A(int n) {};
};

class B: public A { //Point is that Lock作为虚基类；在继承体系中B是最远派生类，初始化时候要负责调用Lock的初始化函数，但是Lock::Lock()是private，所以无法被调用
public:
	B() {};  
};

//--------------------------------------------------------------
//Test Code 2: 虚继承的例子 
//--------------------------------------------------------------
//-----------------------------------
//test code 2
//-----------------------------------
class Car {
public:
	Car(): price(20000) {}
	//Car(int): price(5000) {}
	Car(double b):price(b*1.1) {};
	double price;
};

class Toyota: public virtual Car {
public:
	//Toyota() { cout <<"Toyota::Toyota "<<endl; };
	Toyota(double b): Car(b){};
	//Toyota(int b): Car(b){};
};

class Prius: public Toyota {
public:
	Prius(double b):Toyota(b) {};
	//Prius(int b):Toyota(b) {};
};


int main(int argc, char **argv)
{
	//-----------------------------------
	//test code 2
	//Point:  output is "2000" 因为Prius调用了Car的默认构造函数
	//-----------------------------------
	Prius p(30000);
	cout <<p.price <<endl;

	return 0;
}
