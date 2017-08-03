#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int a,b,c,d,total,temp;
	while(scanf("%d %d %d %d",&a,&b,&c,&d) == 4)
	{
		if(a == 0 && b == 0 && c == 0 && d == 0) break;
		total = 1080;
		temp = a - b;
		if(temp < 0) temp = temp + 40;
		total += temp * 9;
		temp = c - b;
		if(temp < 0) temp = temp + 40;
		total += temp * 9;
		temp = c - d;
		if(temp < 0) temp = temp + 40;
		total += temp * 9;
		printf("%d\n",total);
	}
	return 0;
}
