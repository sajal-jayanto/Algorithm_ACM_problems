#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 110
void made_board(int,int);
char ar[MAX][MAX];
int  str[MAX][MAX];
int main()
{
	//freopen("output.txt","w",stdout);
	int row,col,count = 0;
	while(scanf("%d %d",&row,&col) == 2)
	{
		if(row == 0 && col == 0 ) break;
		gets(ar[0]);
		if(count!=0) printf("\n");
		for(int i=0;i<row;i++)
		{
			gets(ar[i]);
			for(int j=0;j<col;j++)
			{
				str[i][j] = 0;	
			} 	
		}
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(ar[i][j] == '*') 
				made_board(i,j);	
			}   
		}
		printf("Field #%d:\n",++count);
		
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(ar[i][j] == '*')
				{
					printf("%c",ar[i][j]);	
				} 
				else printf("%d",str[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
void made_board(int i, int j)
{
	str[i][j+1]++;
	str[i+1][j+1]++;
	str[i+1][j]++;
	str[i+1][j-1]++;
	str[i][j-1]++;
	str[i-1][j-1]++;
	str[i-1][j]++;
	str[i-1][j+1]++;
}
