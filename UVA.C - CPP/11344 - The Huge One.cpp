#include<stdio.h>
#include<math.h>
#include<string.h>
char ar[10000000];
int str[10000000];
int nu[12];
int main()
{
	int t,n,i,num,j,p,m,sum;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s",ar);
		for(i=0;i<strlen(ar);i++)
		{
			str[i]=ar[i]-48;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&nu[i]);
		}
		m = 0;
		for(i=0;i<n;i++)
		{
			sum = 0;
			for(j=0;j<strlen(ar);j++)
			{
				sum = sum+str[j];
				p = sum%nu[i];
				p = p*10;
				sum = p;
			}
			if(sum!=0)
			{
				printf("%s - Simple.\n",ar);
						 m = 1; 
				        break;
			}
		}
		if(m!=1)
		{
			printf("%s - Wonderful.\n",ar);
		}
	}
	return 0;
}
