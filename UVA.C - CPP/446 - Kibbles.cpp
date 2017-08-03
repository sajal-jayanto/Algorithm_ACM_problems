#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
	int t,a,b,sum,k;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%x  %c %x",&a,&ch,&b);
		if(ch == '+') sum = a + b;
		else if(ch == '-') sum = a - b;
		for(int i=12;i>=0;i--)
		{
			k = a >> i;
			if(k & 1) printf("1");
			else printf("0");
		}
		printf(" %c ",ch);
		for(int i=12;i>=0;i--)
		{
			k = b >> i;
			if(k & 1) printf("1");
			else printf("0");
		}
		printf(" = %d\n",sum);
	}
	return 0;
}
