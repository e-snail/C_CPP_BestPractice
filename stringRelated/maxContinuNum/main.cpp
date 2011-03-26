#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//实现一个函数的完整代码。
//int maxContinuNum(const char*inputstr.char*outputstr)
//	功能：
//	在以‘\0’结尾的字符串中找出连续最长的数字串，并把这个串的长度返回，并把这个最长数字串付给其中一个函数参数outputstr所指内存。不能用strlen之类的库函数。

int str_len(const char*str)
{
	int i = 0;
	while(*(str + i) != '\0') {
		i++;
	}
	return i;
}

//int maxContinuNum(const char *inputstr, char **outputstr)
int maxContinuNum(const char *inputstr, char *&outputstr) //C语言不支持 指向指针的引用
{
	printf("%p\n\n", inputstr);
	int n = str_len(inputstr);
	int add = 0;
	char *p = (char*)malloc(n+1);
	int len = 0;
	int i;
	for(i=0; i <= n ; i++)
	{
		if (*(inputstr+i) >= 48 && *(inputstr+i) <= 57) 
			*(p+i) = *(inputstr+i);
		else
			*(p+i) = '\0';
	}
	for(i=0; i <= n ; i++)
	{
		if (*(p+i) != '\0')
		{
			int n = str_len(p+i);
			if (len < n)
			{
				len = n;
				add = i;
				//outputstr = inputstr + i;
				//printf("%p\n", outputstr);
			}
			i += n-1;
		}
	}
//	*outputstr = (char *) malloc (n+1); //用指向指针的指针来返回分配的内存，调用本函数时要用maxContinuNum(xxx, &xxx)；
//	for (i=0; i <= n+1; i++)
//		*(*outputstr + i) = *(p+add+i);
//	printf("%s\n", *outputstr);

	outputstr = (char *) malloc (n+1);
	for (i=0; i <= n+1; i++)
		*(outputstr + i) = *(p+add+i);
	printf("%s\n", outputstr);

	free(p);

	return len;
}

int main( int argc, char **argv)
{
	const char *str = "abc123cd23efgh123456789igk230";
	char *add; 
	int n = maxContinuNum(str, add);

	//printf("%p\n", str);
	printf("\n%d %s\n", n, add);

	//printf("%d\n", str_len(add));
	//printf("%d\n", strlen(add));
	free (add);

	return 0;
}
