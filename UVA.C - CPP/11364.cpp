#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int t,n,i,distance,ar[20];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&ar[i]);
		}
		sort(ar,ar+n);
		distance = (ar[n-1]-ar[0])*2;
		printf("%d\n",distance);
	}
	return 0;
}
