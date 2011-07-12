#include <stdio.h>
#include <pthread.h>

static int m;

void *pthread1(void *arg)
{
	printf("pthread1: m is %d\n", m);
	m = 5;
	printf("pthread1: m changed to %d\n", m);

	return (void*)0;
}

int main (int argc, char **argv)
{
	pthread_t id1;
	m = 4;
	printf("main: m is %d\n", m);

	int res = 0;
	res = pthread_create(&id1, NULL, (void*)pthread1, NULL);
	if (res) {
		perror("pthread1 create ");
		return -1;
	}
	printf("main: m is %d\n", m);

	return 0;
}
