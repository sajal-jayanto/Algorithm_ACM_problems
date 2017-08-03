#include<stdio.h>
#include<math.h>
int main()
{
	long long num;
	int dig,i;
	while(1)
	{
		dig = 0;
		scanf("%lld",&num);
		for(i=1;i<=num;i++)
		{
			dig =  (floor(log10(i))+1);
			printf("%d\n",dig);
		}
		
	}
	return 0;
}
