#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
	long long sum,N,M,i;
	while(scanf("%lld %lld",&N,&M)!= EOF)
	{
		if(M == 0) printf("1\n");
		else 
		{
			sum = 1;
			M = (N - M) + 1;
			for(i = N ; i >=  M ; i--)
			{
				sum = sum * i;
				while(sum % 10 == 0) sum = sum / 10;
				sum = sum % 1000000000;
			}
			printf("%lld\n",sum % 10);	
		}
	}
	return 0;
}
