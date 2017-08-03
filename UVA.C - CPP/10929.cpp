#include<stdio.h>
#include<string.h>
int main()
{
	char ar[2000];
	int str[2000];
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
			p = sum%11;
			p = p*10;
			sum = p;
		}
		if(sum!=0)
		{
			printf("%s is not a multiple of 11.\n",ar);
		}
		else 
		{
			printf("%s is a multiple of 11.\n",ar);	
		}	
	}
	return 0;
}
