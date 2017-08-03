#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
long long MODEX(long long,long long);
long long M;
int main()
{
	long long t,number,pow;
	while(scanf("%lld",&t) && t)
	{
		while(t--)
		{
			scanf("%lld %lld %lld",&number,&pow,&M);
			printf("%lld\n",MODEX(number,pow));
		}
	}
	return 0;
}
long long MODEX(long long N,long long P)
{
	long long sum;
	if(P == 0) return 1;
	if(P%2 == 0)
	{
		sum = MODEX(N,P/2);
		return ((sum%M) * (sum%M))%M;
	}
	else return ((N%M) * MODEX(N,P-1)%M)%M; 	
}
