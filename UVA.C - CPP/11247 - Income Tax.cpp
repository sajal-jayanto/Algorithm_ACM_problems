#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
int main()
{
	long long m,x,p,money;
	while(scanf("%lld %lld",&m,&x) && !(m == 0 && x == 0))
	{
		if( x == 100 || x == 0 || m == 1)   printf("Not found\n");
		else 
		{
			p = m;
			m = (m - 1) * 100;
			x = 100 - x;
			money = m / x;
			if(m % x == 0) money--;
			if(money < p)  printf("Not found\n");
			else printf("%lld\n",money);	
		}
	}
	return 0;
}
