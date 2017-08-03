#include<stdio.h>
#include<math.h>
int main()
{
	long long t,money,tex,k=0;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&money);
		if(money<=180000)
		{
			tex = 0;
			printf("Case %lld: %lld\n",++k,tex);
		}
		else 
		{
			tex = 0;
			money = money - 180000;
			if(money - 300000 > 0)
			{
				tex = tex + 30000;
				money = money - 300000;
			}
			else if(money - 300000 <= 300000)
			{
				tex = tex + ceil((money * 0.1));
				money = 0;
			}
			if(money - 400000 > 0)
			{
				tex = tex + 60000;
				money = money - 400000;
			}
			else if(money!=0 && money - 400000 <= 400000)
			{
				tex = tex + ceil((money * 0.15));
				money = 0;
			}
			if(money - 300000 > 0)
			{
				tex = tex + 60000;
				money = money - 300000;
			}
			else if(money!= 0 && money - 300000 <= 300000)
			{
				tex = tex + ceil((money * 0.2));
				money = 0;
			}
			if (money > 0)
			{
				tex = tex + ceil((money * 0.25));
			}
			if(tex < 2000)
			{
				tex = 2000;
			}
		    printf("Case %lld: %lld\n",++k,tex);
		}
	}
	return 0;
}
