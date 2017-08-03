#include<stdio.h>
#include<math.h>
#define MAX 65536
void is_prime();
int ar[MAX];
int prime[6545];
int ans[100000];
int main()
{
	//freopen("SAJAL.txt","w",stdout);
	is_prime();
	int number,siz,min,an,n;
	while(scanf("%d",&number) && number!=0)
	{
		min = 0;
		if(number < 0)
		{
			number = number * -1;
			min = 1;
		}
		an = number;
		siz = 0;
		for(int i=0;prime[i]<=sqrt(number);i++)
		{
			if(number%prime[i] == 0)
			{
				while(number%prime[i] == 0)
				{
					number = number / prime[i];
					ans[siz++] = prime[i];
				}
			}
		}
		if(number!=1) ans[siz++] = number;
		if(siz!=0)
		{
			if(min == 0)
			{
				printf("%d =",an);
			}
			else printf("-%d = -1 x",an);
			for(int i=0;i<siz;i++)
			{
				printf(" %d",ans[i]);
				if(i!=siz-1) printf(" x");
			}
		}
		else
		{
			if(min == 0)
			{
				printf("%d = %d",an,an);
			}
			else printf("-%d = -1 x %d",an,an);
		}
		printf("\n");
	}
	return 0;
}
void is_prime()
{
	for(int i=2;i<=sqrt(MAX);i++)
	{
		for(int j=i+i;j<=MAX;j=j+i)
		{
			ar[j-1] = 1;
		}
	}
	ar[0] = 1;
	int k = 0;
	for(int i=1;i<=MAX;i++)
	{
		if(ar[i-1] == 0)
		prime[k++] = i;
	}
}


