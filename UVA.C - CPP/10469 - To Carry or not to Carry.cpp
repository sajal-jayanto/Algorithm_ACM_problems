#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int ar[32];
int main()
{
	long long a,b,reminder,ans;
	int x,y;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
		int n = 0;
		ans = 0;
		for(int i=31;i>=0;i--)
		{
			x = a >> i;
			y = b >> i;
			if(x & 1 && y & 1) ar[n++] = 0;
			else if(x & 1 || y & 1) ar[n++] = 1;
			else ar[n++] = 0; 
		}
		n = 0;
		for(int i=31;i>=0;i--) 
		{
			reminder = pow(2,n++);
			ans = ans + (ar[i] * reminder);
		}
		printf("%d\n",ans);
	}
	return 0;
}
