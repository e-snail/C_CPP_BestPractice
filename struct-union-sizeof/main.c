#include <string.h>
#include <stdio.h>

int main()
{
	union {
		struct ST { 
			char str[0];
		}s0;
		struct ST1 { 
			char str[0];
		}s1;
	}s;

	printf("%d\n", sizeof(s));

	return 0;
}
