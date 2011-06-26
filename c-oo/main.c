#include <stdlib.h>
#include <stdio.h>

#include "testclass.h"

int main(int argc, char **argv)
{
	TestClass a;
	a.setDataFunc = setData;
	a.getDataFunc = getData;

	a.data = 100;
	printf("data = %d\n", a.getDataFunc(&a));

	a.setDataFunc(&a, 111);
	printf("data = %d\n", a.getDataFunc(&a));

	return 0;
}
