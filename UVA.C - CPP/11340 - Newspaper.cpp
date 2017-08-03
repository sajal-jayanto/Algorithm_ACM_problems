#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char get[110];
int  valu[110];
char ar[50000];
int main()
{
	int t,k,l,sum;
	double cost;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		for(int i = 0 ; i < k ; i++)
		{
			scanf(" %c %d",&ch,&valu[i]);	
			get[i] = ch;
		}	  
		scanf("%d",&l);
		gets(ar);
		sum = 0;
		for(int i = 0 ; i < l ; i++)
		{
			gets(ar);
			for(int p = 0 ; p < strlen(ar) ; p++)
			{
				for(int j = 0 ; j < k ; j ++)
				{
					if(ar[p] == get[j])
					{
						sum = sum + valu[j];
							break;
					}
				}
			}
		}
		cost = (double)sum / 100;
		printf("%.2lf$\n",cost);
	}
	return 0;
}
