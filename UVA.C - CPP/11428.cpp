#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n) && n!=0)
	{
		k = 0;
		for(i=1;i<=sqrt(n);i++)
		{
			for(j=0;j<=sqrt(n);j++)
			{
				if((pow(i,3)-pow(j,3))==n)
				{
					printf("%d %d\n",i,j);
						 k = 1;
						break;
				}
			}
			if(k==1)
			 break;
		}
		if(k==0)
		{
			printf("No solution\n");
		}
		
	}
	return 0;
}
