#include<stdio.h>
#include<math.h>
int main()
{
	long long num;
	while(scanf("%lld",&num) && num >= 0)
	{
		if(num == 0 || num == 1)
		{
			printf("0%%\n");
		}
		else 
		{
			printf("%lld%%\n",num*25);
		}	
	}
	return 0;
}
