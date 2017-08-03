#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAXC 1002
#define MAXR 220
void made(int i);
int ar[MAXC][MAXR];
int main()
{
	int num,i,j;
	ar[0][MAXR - 1] = 1;
	ar[1][MAXR - 1] = 2;
	for(int i = 2 ; i < MAXC ; i++) { made(i);} 
	while(scanf("%d",&num) == 1)
	{
		for(i = 0 ; i < MAXR ; i++) if(ar[num][i] != 0) break;
		for(j = i ; j < MAXR ; j++) printf("%d",ar[num][j]);
		printf("\n");
	}
	return 0;
}
void made(int i)
{
	int n,sum = 0,k = MAXR;
	for( n = MAXR - 1 ; n >= 0 ; n--)
	{
		sum	= sum + (ar[i - 1][n] + ar[i - 2][n]);
		if(sum >= 10) ar[i][--k] = sum % 10;
		else ar[i][--k] = sum;
		sum = sum / 10;
	}
	if(sum != 0) ar[i][--k] = sum;
}
