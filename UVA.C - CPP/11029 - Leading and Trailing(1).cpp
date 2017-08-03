#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int t;
	long long num1,num2,pow,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&num1,&pow);
		p = num2 = num1;
		while(--pow)
		{
			if(num1 < 1000000) num1 =  num1 * p;
			else 
			{
				while(num1 > 1000000) num1 = num1 / 10;
				num1 =  num1 * p;
			}
			if(num2 > 1000000) num2 = num2 % 1000000;
			else num2 = num2 * p;		
		}
		num2 = num2 % 1000;
		while(num1 >= 1000) num1 = num1 / 10;	
		printf("%lld...%03lld\n",num1,num2);
	}
	return 0;
}
