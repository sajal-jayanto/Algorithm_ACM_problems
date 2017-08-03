#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define MAX 10010
void last_digit(int);
int ar[MAX];
int main()
{
	last_digit(MAX);
	int num;
	while(scanf("%d",&num) == 1)
	{
		printf("%5d -> %d\n",num,ar[num]);
	}
	return 0;
}
void last_digit(int num)
{
	int n = 1;
	for(int i=1;i<=num;i++)
	{
		n = n * i;
		while( n %10 == 0)  n  = n / 10;
		n = n % 100000;
		ar[i] = n % 10;
	}
}
