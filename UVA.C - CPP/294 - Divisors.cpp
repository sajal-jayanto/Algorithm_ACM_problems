#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	long long a,b,i,j,diveder,num,high_diveder;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		high_diveder = 0;
		for(i = a; i <= b; i++)
		{
			diveder = 0;
			for(j = 1; j <= sqrt(i); j++)
			{
				if(i % j == 0)
				{
					if(i / j != j) diveder = diveder + 2;
					else diveder = diveder + 1;
				} 	
			}
			if(high_diveder < diveder)
			{
				high_diveder = diveder;
				num = i;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,num,high_diveder);
	}
	return 0;
}
