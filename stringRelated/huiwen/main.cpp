#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int huiwen(char *p)
{
	if (p == NULL)
		return -1;

	char *p1 = p + strlen(p) - 1;
	cout <<*p1 <<endl;

	while ((p < p1) && (*p == *p1)){
		p++;
		p1--;
	}
	if(p >= p1)
		return 0;
	if((p < p1) && (*p != *p1))
		return 1;
	else
		return 0;
}

int main( int argc, char **argv)
{

	char *str1 = "abcdedcba";
	char *str2 = "abcddcba";
	char *str3 = "abdcba";

	cout <<huiwen(str1) <<" " <<huiwen(str2) <<" " <<huiwen(str3) <<endl;

	return 0;
}
