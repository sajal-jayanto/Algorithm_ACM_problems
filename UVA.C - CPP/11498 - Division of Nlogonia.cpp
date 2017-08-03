#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
	long long t,x,y,m,n;
	while(scanf("%lld",&t) && t)
	{
		scanf("%lld %lld",&x,&y);
		while(t--)
		{
			scanf("%lld %lld",&m,&n);
			if(x == m || y == n)     printf("divisa\n");
			else if(m > x && n > y)  printf("NE\n");
			else if(m < x && n < y)  printf("SO\n");
			else if(m < x && n > y)  printf("NO\n");
			else if(m > x && n < y)  printf("SE\n");
		}
	}
	return 0;
}
