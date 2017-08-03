#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char ar[300];
	int t,i,j,k=0,number;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(ar);
		printf("Case %d: ",++k);
		for(i=0;i<strlen(ar);i++)
		{
			if(isalpha(ar[i])!=0)
			{
				if(isdigit(ar[i+1])!=0 && isdigit(ar[i+2])==0) 
				{
					number = (ar[i+1]-48);
				}
				else 
				{
					number = ((ar[i+1]-48)*10)+(ar[i+2]-48);
				}
				for(j=0;j<number;j++)
				{
					printf("%c",ar[i]);		
				}
			}
		}
		printf("\n");
	}
	return 0;
}
