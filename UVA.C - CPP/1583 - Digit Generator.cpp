#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define MAX 100010
int ar[MAX];
int sum_of_a_num(int);
void made();
int main()
{
	//freopen("output.txt","w",stdout);
	made();
	int t,num;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		printf("%d\n",ar[num]);
	}
	return 0;
}
void made()
{
	int n;
	for(int i = 1 ; i < MAX ; i++)
	{
		n = sum_of_a_num(i);
		if(MAX >= n && ar[n] == 0)
		{
			ar[n] = i;
		}
	}
}
int sum_of_a_num(int num)
{
	int sum = num;
	while(num)
	{
		sum = sum + num % 10;
		num = num / 10;
	}
	return sum;
}
