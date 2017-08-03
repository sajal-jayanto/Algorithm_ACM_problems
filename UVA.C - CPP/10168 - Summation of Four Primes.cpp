#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10000000
#define MAXP 664579
bool ar[MAX];
int prime[MAXP];
int main()
{
	int k = 0;
	prime[k++] = 2;
	for(int i=3 ;i<=sqrt(MAX) ;i = i + 2)
	{
		if(ar[i] == false)
		{
			for(int j = i * i ;j<=MAX; j = j + (2 * i))
			{
				ar[j] = true;
			}	
		}
	}
	for(int i=3 ;i<=MAX; i = i + 2)
	{
		if(ar[i] == false) prime[k++] = i;
	}
	k = 0;
	for(int i=4;i<=MAX;i=i+2) 
	{
		if(i == prime[k]) ar[i] = false, k++;
		else ar[i] = true;	
	} 
	int num;
	int sum;
	while(scanf("%d",&num)!=EOF)
	{
		if(num < 8) printf("Impossible.\n");
		else 
		{
			if(num % 2 == 0)
			{
				printf("2 2");
				num = num - 4;	
			} 
			else if(num % 2 == 1)
			{
				printf("2 3");
				num = num - 5;	
			} 
			for(int i=0;num>prime[i];i++)
			{
				sum = num - prime[i];
				if(ar[sum] == false)
				{
					printf(" %d %d\n",prime[i],sum);
						      break;	
				} 
			}
		}
	}
	return 0;
}
