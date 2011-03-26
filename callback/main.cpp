#include <iostream>
using namespace std;

typedef void (*CALLBACK)(int a,int b);
void (*myCallback)(int a,int b);

class otherBase
{
public:
	inline void func1(int a, int b) {cout<<"this is otherBase::func1"<<endl;};
	inline void func2(int a, int b) {cout<<"this is otherBase::func2"<<endl;};
};

class base
{
private:
	int m;
	int n;
	CALLBACK func;
	otherBase *poba;
	//static CALLBACK func;
public:
	void registercallback(CALLBACK fun,int k,int j);
	void registerObject(otherBase *oba);
	void callcallback();

};

//CALLBACK base::func=NULL;

void base::registercallback(CALLBACK fun,int k,int j)
{
	func=fun;
	m=k;
	n=j;
}

void base::registerObject(otherBase *oba)
{
	//oba->func1(3, 4);
	poba = oba;
}

void base::callcallback()
{
	base::func(m,n);
	poba->func1(1, 2);
}

void seiya(int a,int b)
{
	cout<<a<<endl<<b<<endl;
	cout<<"this is seiya callback function"<<endl;
}

void zilong(int a,int b)
{
	cout<<a<<endl<<b<<endl;
	cout<<"this is zilong callback function"<<endl;
}


int main(int argc, char **argv)
{
	base ba;
	otherBase oba;

	ba.registercallback(seiya,2,3);
	ba.registerObject(&oba);
	ba.callcallback();

	ba.registercallback(zilong,5,6); 
	ba.callcallback();

	CALLBACK aaFunc= seiya;
	(*aaFunc)(10, 100);
	myCallback = zilong;
	(*myCallback)(100, 111);

	return 0;
}
