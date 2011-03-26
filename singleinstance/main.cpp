#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class SingleInstance {
	public: 
		static SingleInstance *getInstance() { 
			if (!instance) 
				instance = new SingleInstance();	
			return instance;   
		};
		void print() { cout <<a <<endl; };
	protected:
		SingleInstance() { a = 100; };
		~SingleInstance() { 
			if (instance) 
				delete instance; 
		};
	private:
		int a;
		static SingleInstance *instance;
};

SingleInstance *SingleInstance::instance = NULL;

int main( int argc, char **argv)
{
	SingleInstance *s = SingleInstance::getInstance();
	s->print();

	const int a = 2;
	int *p = const_cast<int*>(&a);
	*p = 100;
	cout <<a <<endl;
	cout <<*p <<endl;

	return 0;
}
