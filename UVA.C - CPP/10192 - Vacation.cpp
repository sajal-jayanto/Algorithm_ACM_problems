#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
	int len,count,k = 0;
	int ar[110][110] = {0};
	char frist[110],second[110];
	while(gets(frist) && frist[0]!='#')
	{
		gets(second);
		count = 0;
		for(int i = 0 ;i < strlen(frist) ; i++)
		{
			for(int j = 0 ; j < strlen(second) ; j++)
			{
				if(frist[i] == second[j]) 
				{
					ar[i+1][j+1] = ar[i][j] + 1;
				}
				else ar[i+1][j+1] = (ar[i][j+1] > ar[i+1][j]) ? ar[i][j+1] : ar[i+1][j];
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n",++k,ar[strlen(frist)][strlen(second)]);
	}
	return 0; 
}
