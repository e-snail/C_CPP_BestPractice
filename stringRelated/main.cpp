#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

char *reverseWords(char *str)
{
	char *newstr = new char[strlen(str)+1];
	strcpy(newstr, str);
	int n = strlen(newstr);
	int i = 0;
	int j= n-1;
	//现将字符串倒转
	for (;i<j; i++,j--) {
		char tmp = *(newstr+ i);
		*(newstr + i) = *(newstr + j);
		*(newstr + j) = tmp;
	}

	//在倒转的基础上，按照每个单词倒转
	i = 0;
	while (i < n && newstr[i] !='\0') {
		j = i;
		int k = i;
		while (newstr[j] != ' ' && newstr[j] != '\0')
			++j;
		i = j+1;
		j--;
		for(; k<j; k++, j--) {
			char tmp = newstr[k];
			newstr[k] = newstr[j];
			newstr[j] = tmp;
		}
	}

	return newstr;
}

void remove_duplicated2(int a[])
{
	 if(a[0]==0 || a==NULL)
		return;
	 int insert=1,current=1;
		while(a[current]!=0)
		{
			if(a[current]!=a[current-1])
			{
				a[insert]=a[current];
				insert++;
				current++;
			}
			else
				current++;
		}
	a[insert]=0;
}

int main(int argc, char **argv)
{
	char *str = "You are an exelent man!"; 
	char *s = reverseWords(str);
	cout <<s <<endl;
	delete s;

	int array[8] = {1, 1, 2, 2, 1, 3, 3, 0};
	remove_duplicated2(array);
	for (int i = 0; i < 8; i++)
		cout <<array[i] <<"  ";
	cout <<endl;

	return 0;
}
