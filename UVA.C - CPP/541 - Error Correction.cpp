#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int ar[110][110];
int row[110],col[110];
int main()
{
	//freopen("output.txt","w",stdout);
	int t,i,j,sum1,sum2,a,b;
	while(scanf("%d",&t) && t)
	{
		for(i=0;i<t;i++)
		{
			for(j=0;j<t;j++)
			{
				scanf("%d",&ar[i][j]);
			}
		}
		for(i=0;i<t;i++)
		{
			sum1 = 0;
			sum2 = 0;
			for(j=0;j<t;j++)
			{
				sum1 = sum1 + ar[i][j];
				sum2 = sum2 + ar[j][i];
			}
			row[i] = sum1 % 2;
			col[i] = sum2 % 2;
		}
		a = b = 0;
		for(i=0;i<t;i++)
		{
			a = a + row[i];
			b = b + col[i];
		}
		if(a == 0 && b == 0) printf("OK\n");
		else if(a == 1 && b == 1) 
		{
			for(i=0;i<t;i++)
			{
				if(row[i] == 1) a = i+1;
				if(col[i] == 1) b = i+1;
			}
			printf("Change bit (%d,%d)\n",a,b);
		}
		else printf("Corrupt\n");
	}
	return 0;
}
