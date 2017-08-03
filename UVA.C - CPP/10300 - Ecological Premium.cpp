#include<stdio.h>
int main()
{
	int t,n,i,j,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ar[n][3];
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%d",&ar[i][j]);
			}
		}
		sum = 0;
		for(i=0;i<n;i++)
		{
			sum = sum + (ar[i][0] *ar[i][2]);
		}
		printf("%d\n",sum);	
	}
	return 0;
}
