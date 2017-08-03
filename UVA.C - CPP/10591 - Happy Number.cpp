#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
long long made(long long);
int main()
{
	long long num,t,count = 0;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&num);
		if(num == 7) printf("Case #%lld: %lld is a Happy number.\n",++count,num);
		else if(made(num) == 1) printf("Case #%lld: %lld is a Happy number.\n",++count,num);
		else printf("Case #%lld: %lld is an Unhappy number.\n",++count,num);
	}
	return 0;
}
long long made(long long num)
{
	long long count = 0;
	if(num < 10) return num;
	while(num)
	{
		count = count + ((num % 10) * (num % 10));
		num = num / 10;
	}
	made(count);
}
