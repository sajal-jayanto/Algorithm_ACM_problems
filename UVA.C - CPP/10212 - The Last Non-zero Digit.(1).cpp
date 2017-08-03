#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	long long i,num,num2,sum;
	while(scanf("%lld %lld",&num,&num2)!=EOF)
	{
		sum = 1;
		while(num2--)
		{
			sum = sum * num--;
			while( sum % 10 == 0) sum = sum / 10;
			sum = sum % 100000000;
		}
		printf("%lld\n",sum%10);
	}
	return 0;
}
