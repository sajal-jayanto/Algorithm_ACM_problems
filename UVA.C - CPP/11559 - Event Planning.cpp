#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	freopen("output.txt","w",stdout);
	long long  member,money,hotel,week,i,j;
	long long ar[50][50],ok,cost[50],k;
	while(scanf("%lld %lld %lld %lld",&member,&money,&hotel,&week)==4)
	{
		
		for(i=0;i<hotel;i++)
		{
			scanf("%lld",&ar[i][0]);
			for(j=1;j<=week;j++)
			{
				scanf("%lld",&ar[i][j]);
			}
		}
		k = 0;
		for(i=0;i<hotel;i++)
		{
			ok = 0;
			for(j=1;j<=week;j++)
			{
			    if(ar[i][j] >= member)
				{
					ok = 1;
				}
			}
			if(ok == 1)
			{
				cost[k++] = (ar[i][0]*member);
			}
		}
		if(k == 0) printf("stay home\n");
		else
		{
			sort(cost,cost+k);
			if( cost[0] <= money )
			{
				printf("%lld\n",cost[0]);
			}
			else printf("stay home\n");
		}	
	}
	return 0;
}
