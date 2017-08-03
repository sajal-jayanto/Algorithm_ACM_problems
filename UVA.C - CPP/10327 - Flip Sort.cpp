#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int ar[10000];
int main()
{
	int n,count;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++) 
		{
			scanf("%d",&ar[i]);	
		}
		count = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(ar[i] > ar[j])
				{
					count++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n",count);	
	}
	return 0;
}
