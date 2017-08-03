#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	long long num,i,count;
	while(scanf("%lld",&num) == 1)
	{
		i = count = 1;
		while(i)
		{
			i = (i * 10) + 1;
			i = i % num;
			count++;
		}
		printf("%lld\n",count);
	}
	return 0;
}
