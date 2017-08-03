#include<stdio.h>
int main()
{
	long long n,k,sum,p;
	while(scanf("%lld %lld",&n,&k)!=EOF)
	{
		sum=n;
		if(k>1)
		{
			while(1)
			{
				if(n<k)break;
				p=n%k;
				n=n/k;
				sum=sum+n;
				n=n+p;
			}	
		}
		printf("%lld\n",sum);
	}
	return 0;
}
