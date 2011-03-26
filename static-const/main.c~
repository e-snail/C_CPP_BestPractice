#include <stdlib.h>
#include <stdio.h>

const int n = 99;

int main( int argc, char **argv)
{
	const int a = 2;
	int *p = (int*)(&a);
	*p = 100; //可以改变a的值，当对const常量的地址操作时，编译器自动为其分配空间。因为此处为局部变量，所以空间在栈上。
	printf("%d\n", a);
	printf("%d\n", *p);

	int *pn = (int *)(&n);
	*pn = 9999; //段错误，因为全局const常量的地址空间是在RODATA区域
	printf("%d\n", n);
	printf("%d\n", *pn);

	return 0;
}

