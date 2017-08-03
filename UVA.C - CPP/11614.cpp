#include<stdio.h>
#include<math.h>
int main()
{
	long long t,n,i,sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		n=n*2;
		for(i= sqrt(n) ;; i++)
		{
			sum = (i*i)+i;
			if(n <= sum)
			{
				if(n==sum)
				{
					printf("%lld\n",i);
				}
				else printf("%lld\n",i-1);
				
				break;
			}
		}
	}
	return 0;
}

