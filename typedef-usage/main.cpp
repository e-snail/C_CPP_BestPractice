#include <iostreami>
#include <stdlib.h>
#include <string>

using namespace std;

//USAGE 1: define function pointer
typedef void (*pFunc)(int);
void func1(int n)
{
	cout <<"func1: n = "<<n<<endl;
}

//USAGE 2: for porting convenieense
typedef int INT;
typedef unsigned int INT;
 
//USAGE 3: when define struct
typedef struct whoStruct{
int a;
char b;
}myStruct;

int main(int argc, char **argv)
{
	//for Usage 1:
	pFunc f = func1;	
	f(111);

	//for Usage 3:
	myStruct n;  //without typedef you should use "struct whoStruct n"

	return 0;
}

