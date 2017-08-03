#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char ar[600];
int main()
{
	//freopen("sajal.txt","w",stdout);
	int t,n,count = 0;
	scanf("%d",&t);
	while(t--)
	{
		if(count!= 0) printf("\n");
		printf("Case %d:\n",++count);
		scanf("%d",&n);
		gets(ar);
		while(n--)
		{
			gets(ar);
			for(int i = 0 ; i < strlen(ar) ; i++)
			{
				if(ar[i] != ' ') printf("%c",ar[i]);
				else if(ar[i] == ' ' && ar[i+1] != ' ') printf(" ");
			}
			printf("\n");
		}	
	}
	return 0;
}
