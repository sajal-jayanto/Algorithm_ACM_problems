#include <stdio.h>
#include <string.h>
int main()
{
	char ar[500];
	int i;
	while(gets(ar))
	{
		for(i=0;i<strlen(ar);i++)
		{
			printf("%c",ar[i]-7);
		}
		 printf("\n");
	}
    return 0;
}
