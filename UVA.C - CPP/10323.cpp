#include <stdio.h>
int main()
{
	long long i,number,factoril;
	while(scanf("%lld",&number)!=EOF)
	{
		if(number<0)
		{
			number=number*-1;
			if(number%2==0)
			{
				printf("Underflow!\n");
			}
			else printf("Overflow!\n");
		}
		else
		{
			factoril=1;
			for(i=1;i<=number;i++)
			{
				factoril=factoril*i;
				if(factoril>6227020800)
				{
					break;
				}
			}
			if(factoril<10000)
			{
				printf("Underflow!\n");
			}
			else if(factoril>6227020800)
			{
				printf("Overflow!\n");
			}		
			else printf("%lld\n",factoril);
		}		
	}
	return 0;
}
