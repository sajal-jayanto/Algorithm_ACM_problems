#include<stdio.h>
#include<string.h>
int degree(int);
int main()
{
	char ar[2000];
	int str[2000];
	int i,sum,p,deg;
	while(scanf("%s",ar))
	{
		if(strlen(ar)==1 && ar[0]==48)
		{
			break;
		}
		deg = 0;
		for(i=0;i<strlen(ar);i++)
		{
			str[i]=ar[i]-48;
			deg = deg + ar[i]-48;
		}
		sum=0;
		for(i=0;i<strlen(ar);i++)
		{
			sum = sum+str[i];
			p = sum%9;
			p = p*10;
			sum = p;
		}
		if(sum!=0)
		{
			printf("%s is not a multiple of 9.\n",ar);
		}
		else 
		{
			printf("%s is a multiple of 9 and has 9-degree %d.\n",ar,degree(deg));
		}	
	}
	return 0;
}
int degree(int num)
{
	int deg = 1,i,j,n;
	while(num!=9)
	{
		n = num;
		j = 0;
		while(n)
		{
			i = n%10;
			j = j + i;
			n = n / 10;
		}
		num = j;
		deg++;
	}
	return deg;
}
