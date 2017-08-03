#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAX 510
int ar[MAX];
using namespace std;
int main()
{
	int t,n,midel,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) 
		{
			scanf("%d",&ar[i]);	
		}
		sort(ar,ar+n);
		
		midel = ar[n/2];
		
		ans = 0;
		
		for(int i=0;i<n;i++)
		{
			ans = ans + abs(midel - ar[i]);
		}
		printf("%d\n",ans);	
	}
	return 0;
}
