#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
long long BIG_MOD(long long,long long);
long long M;
int main()
{
	long long num,pow;
	while(scanf("%lld %lld %lld",&num,&pow,&M)==3)
	{
		printf("%lld\n",BIG_MOD(num,pow));
	}
	return 0;
}
long long BIG_MOD(long long num,long long pow)
{
	long long sum;
	if(pow == 0) return 1;
	if(pow % 2 == 0)
	{
		sum = BIG_MOD(num,pow/2);
		return ((sum%M)*(sum%M))%M;
	}
	else return ((num%M)*(BIG_MOD(num,pow-1)%M))%M;
}
