#include <stdlib.h>
#include <stdio.h>

void translate1(int *p)
{
	printf("p=%x *p=%d\n", p, *p);
	p += 1;
	printf("p=%x *p=%d\n", p, *p);
}

void translate2(int *p)
{
	//printf("p=%x *p=%d\n", p, *p);
	*p += 1;
	//printf("p=%x *p=%d\n", p, *p);
}

int main(int argc, char **argv)
{
	int x = 1;
	int *p = &x;

	printf("p=%x *p=%d\n", p, *p);
	translate1(&x);
	//printf("x=%d &x=%x p=%x *p=%d\n", x, &x, p, *p);
	translate1(p);
	//printf("x=%d &x=%x p=%x *p=%d\n", x, &x, p, *p);

	translate2(&x);
	//printf("x=%d &x=%x p=%x *p=%d\n", x, &x, p, *p);
	translate2(p);
	//printf("x=%d &x=%x p=%x *p=%d\n", x, &x, p, *p);

	return 0;
}
