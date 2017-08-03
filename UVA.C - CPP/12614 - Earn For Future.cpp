#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int t,n,num,sum,count = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum = 0;
		while(n--)
		{
			scanf("%d",&num);
			sum = sum > num ? sum : num;
		}
		printf("Case %d: %d\n",++count,sum);
	}
	return 0;
}
