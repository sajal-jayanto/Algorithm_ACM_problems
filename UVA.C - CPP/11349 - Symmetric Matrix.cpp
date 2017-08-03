#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 110
long matrix[MAX][MAX];
int main()
{
	int t,n,count = 0;
	char ch,as;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%c%c%c%c%d",&ch,&as,&ch,&as,&n);
		int ok = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%ld",&matrix[i][j]);
				if(matrix[i][j] < 0) ok = 1; 
			}
		}
		if(ok == 0)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(matrix[i][j]!=matrix[n-i-1][n-j-1])
					{
						ok = 1;	
						break;
					} 			
				}
				if(ok == 1) break;
			}	
		}
		if(ok == 0) printf("Test #%d: Symmetric.\n",++count);
		else printf("Test #%d: Non-symmetric.\n",++count);	
	}
	return 0;
}
