#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
	long long a,b,c,d,l,sum,count;
	while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&l) == 5)
	{
		if(a == 0 && b == 0 && c == 0 && d == 0 && l == 0) break;
		count = 0;
		for(int i=0;i<=l;i++)
		{
			sum = ((a * i * i) + (b * i) + c);
			if(sum % d == 0) count++;
		}
		printf("%lld\n",count);	
	}
	return 0;
}
