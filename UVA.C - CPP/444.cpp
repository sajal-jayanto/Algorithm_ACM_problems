#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    //freopen("sajal.txt","w",stdout);
	char ar[1000];
	int st[2500];
	int i,n,k;
	while(gets(ar))
	{
		if(isdigit(ar[0])==0||isdigit(ar[1])==0)
		{
			k=0;
			for(i=strlen(ar)-1;i>=0;i--)
			{
				n = ar[i];
				while(n)
				{
					st[k++] = n%10;
					n = n/10;
				}
			}
			for(i=0;i<k;i++)
			{
				printf("%d",st[i]);
			}
			printf("\n");
		}
		else 
		{
			k=0;
			for(i=strlen(ar)-1;i>=0;i--)
			{
				st[k++] = ar[i]-48;
			}
			for(i=0;i<k;)
			{
				n = (((st[i]*100)+st[i+1]*10)+st[i+2]);
				if(n<=127)
				{
					printf("%c",n);
					i = i+3;
				}
				else 
				{
					n = ((st[i]*10)+st[i+1]);
					printf("%c",n);
					i = i+2;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
