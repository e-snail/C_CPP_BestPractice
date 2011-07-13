#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	int *p = NULL;
	printf("%p\n", p);

	p = (int *)malloc(0); //POINT_1: even malloc size is 0, gcc also allocate some space for p
	printf("%p\n", p);

	free(p);
	p = (int *)malloc(16);
	printf("%p\n", p);

	free(p);
	p = (int *)malloc(32);
	printf("%p\n", p);
	free(p);
}
