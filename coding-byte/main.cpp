#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int checkEndian ()
{
	union endian {
		int a;
		char c;
	}c;
	c.a = 256;
	return (c.c == 0);
}

int main(int argc, char **argv)
{
	char p[] ={"中文123"};
	printf("%d\n", strlen(p));
	//cout <<strlen(p) <<endl;

	int n = 0x112233;
	printf("%d\n", sizeof(unsigned int));
	
	//to judge if it is big/little endian
	unsigned short x = 0x1234;
	if (*(unsigned char*)&x == 0x12)
		printf("Big endian\n");
	else 
		printf("Little endian\n");

	printf("%d\n", checkEndian());

	return 0;
}

/*
refer doc http://hi.baidu.com/serial_story/blog/item/7e110587c3ed8e29c75cc3c7.html
*/
