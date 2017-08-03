#include<stdio.h>
#include<math.h>
int is_prim(int);
int prim_is();
int ar[1000000]={0};
int main()
{
	prim_is();
	long long number,i,count;
	while(scanf("%lld",&number) && number!=0)
	{
		if(ar[number-1]==0)
		{
			printf("%lld : 1\n",number);
		}
		else 
		{
			count = 0;
			for(i = 2; i<=number/2;i++)
			{
				if((ar[i-1]==0) && (number%i==0))
				{
					    count++;
				}
			}
			printf("%lld : %lld\n",number,count);
		}
	}
	return 0;
}
int prim_is()
{
	//freopen ("output.txt","w",stdout);
	int i,j;
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
	int i;
	if(num%2==0 && num !=2)
	{
		return 1;
	}
	for(i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
		{
			return 1;
			 break;
		}
	}
	return 0;
}
