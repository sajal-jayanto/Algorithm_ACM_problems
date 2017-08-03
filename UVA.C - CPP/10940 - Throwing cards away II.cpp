#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 500010
void made();
int ar[MAX+2];
int main()
{
	made();
	int num;
	while(scanf("%d",&num) && num)
	{
		printf("%d\n",ar[num]);
	}
	return 0;
}
void made()
{
	ar[1] = 1;
	ar[2] = 2;
	int n = 2;
	for(int i = 3 ; i <= MAX ; i++)
	{
		if(i < n) n = 2;
		ar[i] = n;
		n = n + 2;
	}
}
