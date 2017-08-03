#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 20000000
void is_prime();
int ar[MAX] = {0};
int prime[100010];
int main()
{
	is_prime();
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		printf("(%d, %d)\n",prime[num-1],prime[num-1]+2);
	}
	return 0;
}
void is_prime()
{
	int i,j;
	for(i=2;i<=sqrt(MAX);i++)
	{
		if( i==2||ar[i-1] == 0)
		{
			for(j=i+i;j<=MAX;j=j+i)
			{
				ar[j-1] = 1;
			}
		}
	}
	int k = 0;
	for(i=3;i<=MAX;i++)
	{
		if(ar[i-1] == 0 && ar[i+1] == 0)
		{
			prime[k++] = i;
		}
		if(k > 100010) break;
	}
}


