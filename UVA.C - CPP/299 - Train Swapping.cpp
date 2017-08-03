#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
int ar[100];
int main()
{
	int t,n,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&ar[i]);
		}
		count = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(ar[i] > ar[j]) count++;
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",count);
	}
	return 0;
}
