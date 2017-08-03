#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 5000010
void is_prime();
bool ar[MAX];
int sum[MAX];
int main()
{
	is_prime();
	int a,b;
	while(scanf("%d",&a) == 1)
	{
		if(a == 0) break;
		scanf("%d",&b);
		printf("%d\n",sum[b] - sum[a-1]);
	}
}
void is_prime()
{
	for(int i = 2 ; i < sqrt(MAX) ; i++)
	{
		if(i == 2 || ar[i] == false)
		{
			for(int j = i + i ; j < MAX ; j = j + i)
			{
				ar[j] = true;
			}
		}
	}
	for(int i = 2 ; i < MAX ; i++)
	{
		if(ar[i] == false)
		{
			for(int j = i ; j < MAX ; j = j + i)
			sum[j] = sum[j] + i;	
		}
	}
	int k = 0;
	for(int i = 2 ; i < MAX ; i++)
	{
		if(ar[sum[i]] == false) k++, sum[i] = k;
		else sum[i] = k;
	}
}
