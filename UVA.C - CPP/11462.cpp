#include <stdio.h>
#include <algorithm>
int ar[2000100];
using namespace std;

int main() 
{
	int i,n;
	while(scanf("%d",&n) && n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&ar[i]);
		}
		sort(ar,ar+n);
		for(i=0;i<n;i++)
		{
			if(i!=n-1)
				printf("%d ",ar[i]);
			else 
				printf("%d",ar[i]);
		}
		printf("\n");
	}
	return 0;
}
