#include <stdlib.h>
#include <stdio.h>

char *strcat(char *dest, char *src)
{
	char *p = dest;
	while (*dest != '\0')
		dest++;
	while( (*dest++ = *src++) != '\0' );

	return p;
}

int strcmp ( const char* src, const char* dst )
{
	int ret = 0 ;
	//while( ! (ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
	while( ! (ret = *src - *dst) && *dst)
		++src, ++dst;

	if ( ret < 0 )
		ret = -1 ;
	else if ( ret > 0 )
		ret = 1 ;
	return( ret );
}

int main(int argc, char **argv)
{
	//char dest[100] = "abcde";
	char dest[100] = "ABCD";
	char src[20] = "ABCDE";

	strcat(dest, src);
	//char *p = strcat(dest, src);

	printf("%s\n", dest);

	printf("%d\n", strcmp(dest, src));
	return 0;
}

//http://blog.csdn.net/yexianyi/archive/2009/04/19/4092945.aspx
