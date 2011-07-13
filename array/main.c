#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int loop, a[10];
	int *p = a;
	for (loop=0; loop < 10; loop++) {
		*p = loop + 1;
		p++;
		printf("%d  ", a[loop]);
	}
	printf("\n");

	printf("%d  ", (loop-1)[a]); //this also works!
	printf("\n");
	return 0;
}
