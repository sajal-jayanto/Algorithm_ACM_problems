#include<stdio.h>
#include<string.h>
int main()
{
	int str[110];
	char ar[20];
	int t,n,j,p,i,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		getchar();
		count = 0;
		for(i=0;i<n;i++)
		{
			gets(ar);
			if(ar[0]=='R')
			{
				str[i] = 1;	
			}	
			else if (ar[0]=='L')
			{
				str[i] = -1;
			}
			else if(ar[0]=='S')
			{
				j = 8;
				p = 0;
				while(ar[j]!= NULL)
				{
					p =  (p *10 ) + (ar[j++] - 48);
				}
				str[i] = str[p-1];
			}
			count = count + str[i];
		}
		printf("%d\n",count);
	}
	return 0;	
}
