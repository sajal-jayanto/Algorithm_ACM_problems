#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char ar[500];
	int i,j,sum;
	while(gets(ar))
	{
		sum = 0;
		for(i=0;i<strlen(ar);i++)
		{
			if(isdigit(ar[i])!=0)
			{
				sum = sum + ar[i] - 48;
			}
			else if(ar[i]=='!')
			{
				printf("\n");
			}
			else if(isdigit(ar[i])==0 && ar[i]!='b')
			{
				for(j=0;j<sum;j++)
				{
					printf("%c",ar[i]);
				}
				sum = 0;
			}
			else if(isdigit(ar[i])==0 && ar[i]=='b')
			{
				for(j=0;j<sum;j++)
				{
					printf(" ");
				}
				sum = 0;
			}	
		}
		printf("\n");
	}
	return 0;
}
