#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int value=5;

void use_prt(const int* p)
{}

int main()
{
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		printf("Chiled process \n");
		value += 15;
	} else if (pid > 0) {
		wait(NULL);
		printf("Father process, value = %d\n", value);
		exit(0);
	}
	char *p=0;
	p = (char *)malloc(100);
	strcpy(p, "xxxx");
	free(p);
	if (p != NULL)
		strcpy(p, "zzzz");
	printf("p is %s\n", p);

	int array[] = {1, 2, 3};
	printf("size is %d\n", sizeof(array)/sizeof(int));

	return 0;
}
