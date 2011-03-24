#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char p[5] = {'a', 'b', 'c', 'd','e'};
	char *pp[5]; 
	pp[0] = (char *)malloc(1);
	pp[1] = (char *)malloc(1);
	pp[2] = (char *)malloc(1);

	printf("%p\n", &p[0]);
	printf("%p\n", &p[1]);

	printf("%p\n", &pp[0]);
	printf("%p\n", &pp[1]);

	free(pp[0]);
	free(pp[1]);

	return 0;
}
