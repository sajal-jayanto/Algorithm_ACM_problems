#include<stdio.h>
int main()
{
	long long number,sum;
	while(scanf("%lld",&number) && number>=0)
	{
		if(number==0)
		{
			sum = 1;
		}
		else
		{
			sum = 2;
			while(number!=1)
			{
				sum = sum + number;
				number--; 
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
