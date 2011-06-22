#include <stdlib.h>
#include <iostream>

using namespace std;

/*
 * template function
*/
template <class type> void MySwap(type &a, type &b)
{
	type c(a);
	a = b;
	b = c;
}

/*
 * template class 
*/
template <class T>
class Test {
public:
	Test() {};
	Test(T k);
	~Test(){};
	void print();
	T operator + (T x);
private:
	T n;
	static T m;
};

template <class T>
Test<T>::Test(T k)
{
	n = k;
}

template <class T>
void Test<T>::print()
{
	cout<<n <<endl;
}

template <class T>
T Test<T>::operator+(T x) {
	return (n+x);
}

int main(int argc, char **argv)
{
	cout<<"--------------- template function" <<endl;
	int a = 10, b = 111;
	MySwap(a, b);
	cout <<a <<"  " <<b <<endl;

	cout<<"--------------- template class " <<endl;
	Test<int> ti(1111);
	ti.print();

	Test<char> tc('a');
	tc.print();

	return 0;
}
