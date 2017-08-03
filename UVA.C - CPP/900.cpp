#include<stdio.h>
int main()
{
	long long car,i,frist,second,temp;
	while(scanf("%lld",&temp) && temp!=0)
	{
		frist  = 0;
		second = 1;
		for(i=0;i<temp;i++)
		{
			car  = frist + second;
			frist  = second;
			second = car;
		}
		printf("%lld\n",car);
	}
	return 0;
}
