#include<stdio.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	unsigned long long t,num;
	scanf("%llu",&t);
	while(t--)
    {
        scanf("%llu",&num);
        printf("%llu\n",num/2);
    }
	return 0;
}
