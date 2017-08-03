#include<stdio.h>
#include<string.h>
#include<ctype.h>
int is_prim(int);
int main()
{
	char ar[50];
	int i,sum;
	while(scanf("%s",ar)!=EOF)
	{
		sum=0;
		for(i=0;i<strlen(ar);i++)
		{
			if(islower(ar[i])!=0)
			{
				sum+= ar[i]-96;
			}	
			else 
			{
				sum+=ar[i]-38;
			}
		}
		if(is_prim(sum)==0)
		{
			printf("It is a prime word.\n");
		}
		else printf("It is not a prime word.\n");
	}
	return 0;
}
int is_prim(int num)
{
	int i,count=0;
	if(num%2==0 && num!=2)
	{
		return 1;
	}
	else 
	{
		for(i=2;i<=num/2;i++)
		{
			if(num%i==0)
			{
				count++;
				return 1;
				break;
			}
		}
		if(count==0)
		{
			return 0;
		}	
	}
}
