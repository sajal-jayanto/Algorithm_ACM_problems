#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 100000100
void find_prime();
int ar[MAX];
int prime[5800000];
int k = 0;
int main()
{
	//freopen("ou.txt","w",stdout);
	find_prime();
	long long num,n,p;
	while(scanf("%lld",&num)!=EOF)
	{
		if(num == 0|| num ==1 || num == 3)
		{
			printf("%lld is not the sum of two primes!\n", num);	
		} 
		else if(num %2!=0)
		{
			if(ar[num - 2] == 0)  printf("%lld is the sum of 2 and %lld.\n",num,num-2);
			else printf("%lld is not the sum of two primes!\n",num); 	
		} 
		else
		{
			n = 0;
			p = num / 2;
			if(p == num - p) p--;
			while(p >= 3)
			{
				if(ar[p] == 0 && ar[num-p] == 0)
				{
					printf("%lld is the sum of %lld and %lld.\n",num,p,num-p);
							n = 1;
							break;
				}
				p--;
			}	
			if(n == 0) printf("%lld is not the sum of two primes!\n",num);
		}
	}
	return 0;
}
void find_prime()
{
	prime[k++] = 2;
	for(int i=3 ;i<=sqrt(MAX) ;i = i + 2)
	{
		if(ar[i] == 0)
		{
			for(int j = i * i ;j<=MAX; j = j + (2 * i))
			{
				ar[j] = 1;
			}	
		}
	}
	for(int i=3 ;i<=MAX; i = i + 2)
	{
		if(ar[i] == 0) prime[k++] = i;
	}
	k = 0;
	for(int i=2;i<=MAX;i++) 
	{
		if(i == prime[k])
		{
			ar[i] = 0;
			k++;
		}
		else ar[i] = 1;
	}
}

