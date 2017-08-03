#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define MAX 1000010
#define MAXP 78499
void made();
bool ar[MAX];
int prime[MAXP];
int save[MAX];
int main()
{
	made();
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		printf("%d\n",save[num]);
	}
	return 0;
}
void made()
{
	int k = 0,count,p;
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
	count = 0;
	for(int i=1;i<=MAX;i++)
	{
		p = i;
		for(int j=0;prime[j]<=sqrt(p);j++)
		{
			if(p % prime[j] == 0)
			{
				while(p % prime[j] == 0) 
				{
					p = p / prime[j];
					count++;	
				}
			}
		}
		if(p!=1) count++;
		save[i] = count;
	}
}
