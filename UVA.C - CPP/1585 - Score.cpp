#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
char ar[100];
int main()
{
	int t,count,sum;
	scanf("%d",&t);
	gets(ar);
	while(t--)
	{
		gets(ar);
		sum = count = 0;
		for(int i = 0 ;i < strlen(ar) ; i++)
		{
			if(ar[i] == 'O') count++;
			else if(ar[i] == 'X')
			{
				while(count){ sum = sum + count; count--; } 
			}
		}
		while(count){ sum = sum + count; count--; } 
		printf("%d\n",sum);
	}
	return 0;
}
