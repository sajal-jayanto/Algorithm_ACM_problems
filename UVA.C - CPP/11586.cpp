#include <stdio.h>
#include <string.h>
int main()
{
	char ar[500];
	int i,t,M,F;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(ar);
		M=0;
		F=0;
		for(i=0;i<strlen(ar);i++)
		{
			if(ar[i]=='M')
			{
				M++;
			}
			else if(ar[i]=='F')
			{
				F++;
			}			
		}
		if((M!=0 && F!=0) && (M!=1 && F!=1) && (M==F))
		{
			printf("LOOP\n");
		}
		else printf("NO LOOP\n");
	}
	return 0;
}
