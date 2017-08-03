#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
	unsigned long long num,sum; 
	while(scanf("%llu",&num) == 1)
	{
		num = num + 1;
		sum = (num * num) / 2;
		sum = (sum - 3) * 3;
		printf("%llu\n",sum);	
	}
	return 0;	
}
