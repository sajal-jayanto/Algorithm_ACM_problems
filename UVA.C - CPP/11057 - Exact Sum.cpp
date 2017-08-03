#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,n,money,a,b,dis,ar[10100];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&ar[i]);
		scanf("%d",&money);
		a=b=0;
		dis = money;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j) 
				{
					if((ar[i]+ar[j])==money)
					{
						if( dis > (abs(ar[i]-ar[j])))
						{
							dis = (abs(ar[i]-ar[j]));
							a = ar[i];
							b = ar[j];
						}
					
					}
				}	
			}
		} 
		printf("Peter should buy books whose prices are %d and %d.\n\n",(a<b ? a:b),(a>b ? a:b));
	}	
	return 0;
}
