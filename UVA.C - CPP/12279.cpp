#include<stdio.h>
int main()
{
	int n,i,ar[1000],k=0,count;
	while(scanf("%d",&n) && n!=0)
	{
		count = 0; 
		for(i=0;i<n;i++)
		{
			scanf("%d",&ar[i]);
			if(ar[i]>0)
			{
				count++;
			}
			else if(ar[i]==0)
			{
				count--;
			}
		}
		printf("Case %d: %d\n",++k,count);
	}
	return 0;
}
