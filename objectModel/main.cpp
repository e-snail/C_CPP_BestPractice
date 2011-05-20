#include "classb.h"
#include "singleLineInherit.h"
#include "multiInherit.h"

#include "assert.h"

typedef void(*Func)(void);

int main(int argc, char** argv)
{
	//Class objects 
	ClassB b;
	b.funcB();

	//how to deploy virtual function through function point
	Func f = (Func)*((int*)*(int*)(&b));
	assert(f);
	f();

	//try to get how GrandChild orgnize its' memory
	cout <<endl <<"********************************************************" <<endl;
	cout <<"******* Single Inherit Virtal Table function ***********" <<endl;
	cout <<"********************************************************" <<endl;
	GrandChild gc;
	int **pVtab = (int**)(&gc);

	cout << "[0] GrandChild::_vptr->" << endl;
	for (int i = 0; (Func)pVtab[0][i] != NULL; i++) {
		Func f = (Func)pVtab[0][i];	
		cout << "    ["<<i<<"] ";
		f();
	}
	cout << "[1] Parent.iparent = " << (int)pVtab[1] << endl;
	cout << "[2] Child.ichild = " << (int)pVtab[2] << endl;
	cout << "[3] GrandChild.igrandchild = " << (int)pVtab[3] << endl;

	cout <<"******* Object address" <<endl;
	cout <<"GrandChild object: " <<&gc <<endl;
	cout <<"GrandChild object vt: " <<(int*)(&gc) <<endl;
	//following two line functions same
	cout <<"GrandChild object member data: " <<(int*)(&gc)+1 <<" " <<(int)*((int*)(&gc) + 1) <<endl;
	cout <<"GrandChild object member data: " <<&pVtab[1]<<" " <<(int)(pVtab[1]) <<endl;

	cout <<endl <<"********************************************************" <<endl;
	cout <<"******* Multi-Inherit Virtal Table function **********" <<endl;
	cout <<"********************************************************" <<endl;
	Derive d;	
	int **pVtab1 = (int**)(&d);

	cout << "[0] Base1::_vptr->[0]" << endl;
	for (int i=0; i < 4 && (Func)(pVtab[0][i]) != NULL; i++) { //!!!!! why pVtab[0][4] != 00000000
		cout <<"  [" <<i<<"] ";
		Func f = (Func)(pVtab1[0][i]);
		f();
	}
	cout << "[1] Base1::ibase1 = " << (int)pVtab[1] << endl;
	int s = sizeof(Base1)/4;
	cout <<"[" <<s <<"] Base2::_vptr->" <<endl;

	return 0;
}
