#include<stdio.h>
int is_prim(int);
int prim_number();
long long ar[1000000]={0};
int main()
{
	long long number,revers,n;
	prim_number();
	while(scanf("%lld",&number)!=EOF)
	{
		if(ar[number-1]==1)
		{
			printf("%lld is not prime.\n",number);
		
		}
		else if(ar[number-1]==0)
		{
			n=number;
			revers=0;
			while(number)
			{
				revers=revers*10;
				revers=revers+number%10;
				number=number/10;
			}
			if(n<10)
			{
				printf("%lld is prime.\n",n);
			}
			else if(ar[revers-1]==0 && revers!=n)
			{
				printf("%lld is emirp.\n",n);
			}
			else printf("%d is prime.\n",n);
		}
	}
	return 0;
}
int prim_number()
{
	long long i,j;
	for(i=2;i<=1000;i++)
	{
		if(is_prim(i)==0)
		{
			for(j=i;j<=1000000;j=j+i)
			{
				if(j==i)
				ar[j-1]=0;
				else ar[j-1]=1;
			}
		}
	}
}
int is_prim(int num)
{
	int i,count=0;
	if(num%2==0 && num !=2)
	{
		return 1;
	}
	for(i=2;i<=num/2;i++)
	{
		if(num%i==0)
		{
			count=1;
			return 1;
			break;
		}
	}
	if(count == 0)
	{
		return 0;
	}
}
