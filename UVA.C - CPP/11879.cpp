#include<stdio.h>
#include<string.h>
char ar[100000];
int str[100000];
int main()
{
	
	int i,sum,p;
	while(scanf("%s",ar))
	{
		if(strlen(ar)==1 && ar[0]==48)
		{
			break;
		}
		for(i=0;i<strlen(ar);i++)
		{
			str[i]=ar[i]-48;
		}
		sum=0;
		for(i=0;i<strlen(ar);i++)
		{
			sum = sum+str[i];
			p = sum%17;
			p = p*10;
			sum = p;
		}
		if(sum!=0)
		{
			printf("0\n");
		}
		else 
		{
			printf("1\n");	
		}	
	}
	return 0;
}
