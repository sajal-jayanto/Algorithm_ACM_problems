#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<math.h>
int main()
{
	//freopen("output.txt","w",stdout);
	long long num,mod,n,count = 0;
	int k;
	while(scanf("%lld",&num) != EOF)
	{
		printf("%4lld.",++count);
		if(num == 0) { printf(" 0\n"); continue;}
		k = 0; 
		mod = 100000000000000;
		if(num % mod != num)
		{
			n = num / mod;
			printf(" %lld kuti",n);
			num = num - n * mod;
			k = 1;
		} 	
		mod = 1000000000000;
		if(num % mod != num)
		{
			n = num / mod;
			printf(" %lld lakh",n);
			num = num - n * mod;
			k = 1;
		}
		mod = 10000000000;
		if(num % mod != num)
		{
			n = num / mod;
			printf(" %lld hajar",n);
			num = num - n * mod;
			k = 1;
		}
		mod = 1000000000;
		if(num % mod != num)
		{
			n = num / mod;
			printf(" %lld shata",n);
			num = num - n * mod;
			k = 1;
		}
		mod = 10000000;
		if(num % mod != num)
		{
			n = num / mod;
			printf(" %lld kuti",n);
			num = num - n * mod;
			k = 0;
		}
		mod = 100000;
		if(num % mod != num)
		{
			if(k == 1) printf(" kuti");
			n = num / mod;
			printf(" %lld lakh",n);
			num = num - n * mod;
			k = 0;
		}
		mod = 1000;
		if(num % mod != num)
		{
			if(k == 1) printf(" kuti");
			n = num / mod;
			printf(" %lld hajar",n);
			num = num - n * mod;
			k = 0;
		}
		mod = 100;
		if(num % mod != num)
		{
			if(k == 1) printf(" kuti");
			n = num / mod;
			printf(" %lld shata",n);
			num = num - n * mod;
			k = 0;
		}
		if(k == 1) printf(" kuti");
		if(num != 0) printf(" %lld",num);
		printf("\n");
		
	}
	return 0;
}
