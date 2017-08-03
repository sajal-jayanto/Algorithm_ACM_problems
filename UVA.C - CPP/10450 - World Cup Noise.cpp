#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
void made();
long long ar[50];

int main(void)
{
	int t,num,count = 0;
	made();
	scanf("%d",&t);
	for(int i = 0 ; i < t ; i++)
	{
		scanf("%d",&num);
		printf("Scenario #%d:\n",++count);
		printf("%lld\n\n",ar[num - 1]);
	}
	return 0;
}
void made()
{
	long long frist = 1 ;
	long long second = 1;
	long long temp;
	for(int i = 0 ; i <= 50 ; i++)
	{
		temp = frist + second;
		frist = second;
		second = temp;
		ar[i] = temp;
	}
}
