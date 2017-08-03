#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,egg,bol_get,grm,i;
	int ar[30],sum,count,k=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&egg,&bol_get,&grm);
		for(i=0;i<egg;i++)
		{
			scanf("%d",&ar[i]);
		}
		sort(ar,ar+egg);
		sum=0;
		count=0;
		for(i=0;i<egg;i++)
		{
			sum=sum+ar[i];
			if(sum<=grm)
			{
				count++;
			}
			else break;
		}
		if(bol_get>=count && egg>=count)
		{
			printf("Case %d: %d\n",++k,count);
		}
		else
		{
			count = bol_get;
			if(egg<count)
			{
				printf("Case %d: %d\n",++k,egg);
			}
			else printf("Case %d: %d\n",++k,count);
		} 
	}
	return 0;
}
