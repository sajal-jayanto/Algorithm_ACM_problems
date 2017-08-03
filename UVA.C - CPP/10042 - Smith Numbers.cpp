#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 31623
#define MAXP 3400
void is_prime();
int digsum(long long);
bool ar[MAX];
int prime[MAXP];
int main()
{
	is_prime();
	printf("%d",prime[MAXP]);
	long long num,t,sum1,sum2,n,i,count;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&num);
		while(1)
		{
			num++;
			n = num;
			count = sum2 = 0;
			sum1 = digsum(n);
			for(i = 0 ; prime[i] <= sqrt(n) ; i++)
			{
				if(n % prime[i] == 0) 
				{
					 while(n % prime[i] == 0)
					 {
					 	n = n / prime[i];	
					 	sum2 = sum2 + digsum(prime[i]);	
					 } 
					 count++;
				} 
			}
			if(n != 1) {sum2 = sum2 + digsum(n);}
			if(sum1 == sum2 && count != 0) break;
		}
		printf("%lld\n",num);	
	}
 	return 0;
}
void is_prime()
{
	int k = 0;
	prime[k++] = 2;
	for(int i = 3 ; i <= sqrt(MAX) ;i = i + 2)
	{
		if(ar[i] == false)
		{
			for(int j = i * i ;j <= MAX; j = j + (2 * i))  ar[j] = true;
		}
	}
	for(int i = 3 ;i <= MAX; i = i + 2) if(ar[i] == false) prime[k++] = i;
}
int digsum(long long num)
{
	int sum = 0;
	while(num) 
	{
		sum = sum + num % 10;
		num = num / 10;
	}
	return sum;
}
