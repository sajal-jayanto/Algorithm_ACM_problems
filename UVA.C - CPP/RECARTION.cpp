#include<stdio.h>
#include<math.h>
#include<string.h>
long long BIG_MOD(long long N,long long P);
int M = 36123;
int main()
{
	printf("%lld",BIG_MOD(2374859,3029382));
}
long long BIG_MOD(long long N,long long P)
{
	long long sum;
	if (P == 0) return 1;
	if(P%2 == 0)
	{
		sum = BIG_MOD(N,P/2);
		return ((sum%M)*(sum%M))%M;
	}
	else return ((N%M)*(BIG_MOD(N,P-1)%M))%M;
}
