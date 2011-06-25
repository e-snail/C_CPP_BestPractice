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

	char *p1 = "abc";
	char *p2 = "abc";
	printf("p1 add: %p\np2 add: %p\n compare %d\n", p1, p2, p1==p2);

	char *p10 = "abc";
	const char *p20 = "abc";
	printf("p10 add: %p\np20 add: %p\n compare %d\n", p10, p20, p10==p20);

	char *p11 = "abc";
	char p21[] = {'a', 'b', 'c'};
	printf("p11 add: %p\np21 add: %p\n compare %d\n", p11, p21, p11==p21);

	char str1[] = "abc";
	char str2[] = "abc";
	printf("str1 add: %p\nstr2 add: %p\n compare %d\n", str1, str2, str1==str2);


	const char str3[] = "abc";
	const char str4[] = "abc";
	printf("str3 add: %p\nstr4 add: %p\n compare %d\n", str3, str4, str3==str4);

	return 0;
}
