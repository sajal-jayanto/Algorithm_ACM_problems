#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int GCD(int,int);
int main()
{
	int number,count;
	while(scanf("%d",&number) && number!=0)
	{
		count = 0;
		for(int i=1;i<number;i++)
		{
			for(int j=i+1;j<=number;j++)
			{
				count = count + GCD(i,j);
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
int GCD(int a , int b)
{
	int x = a > b ? a:b;
	int y = a < b ? a:b;
	if(x%y == 0) return y;
	else
	{
		for(int i=y/2;i>=1;i--)
		{
			if(a%i == 0 && b%i == 0) return i;
		}
	}
}

