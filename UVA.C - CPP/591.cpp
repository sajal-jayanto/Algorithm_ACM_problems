#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int i,n,sum,count,k=0,ar[100];
	while((scanf("%d",&n)==1)&& n!=0)
	{
		sum=0;
		count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&ar[i]);
			sum=sum+ar[i];
		}
		sum=sum/n;	
		sort(ar,ar+n);
		for(i=0;i<n;i++)
		{
			if(ar[i]>sum)
			{
				count=count+(ar[i]-sum);
				
			}
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",++k,count);
	}
	return 0;
}
