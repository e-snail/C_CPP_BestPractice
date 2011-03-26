#include <stdio.h>
#include <stdlib.h>

int isnum(int ch)
{
	  if(ch>='0' && ch<='9')
		return 1;
	  else
	      return 0; 
}

int iszimu(int ch)
{
	  if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
		return 1;
	  else
	       return 0; 
}

int filter_ansi(char* gbk_string)
{
	  int i = 0;
	    int filter = 0;
	  char* tmp = gbk_string;
	    while(*tmp)
	    {
	      if(isnum(*tmp) || iszimu(*tmp))
	      {
	          filter++;
	          tmp++;
	      }
	      else if(*tmp&0x80)
	      {
	         gbk_string[i] = *tmp;
	         i++;
	         tmp++;
	         gbk_string[i] = *tmp;
	         i++;
	         tmp++;
	      }
	      else
	         tmp++; 
	    }
	 gbk_string[i] = '\0';
	
	return filter;
}
 
int main(int argc, char *argv[])
{
	  char gbk_string[] = "a1我b2是c3A谁";
	    printf("original str is %s\n", gbk_string);
	    printf("filter %d chars\n", filter_ansi(gbk_string));
	   printf("after the str is:%s\n", gbk_string);

	    return 0;
}
