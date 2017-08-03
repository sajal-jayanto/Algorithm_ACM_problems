#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char ar[10000],ar_se[100][100];
	int t,i,j,k,len;
	double l;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(ar);
		k=0;
		len=strlen(ar);
		l=sqrt(len);
		len=sqrt(len);
		if(l==len)
		{
			for(i=0;i<len;i++)
			{
				for(j=0;j<len;j++)
				{
					ar_se[i][j]=ar[k++];	
				}	
			}
			for(i=0;i<len;i++)
			{
				for(j=0;j<len;j++)
				{
					printf("%c",ar_se[j][i]);	
				}	
			}
		}
		else printf("INVALID");
		printf("\n");
	}
	return 0;
}
