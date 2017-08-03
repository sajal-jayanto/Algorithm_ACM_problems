#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
void crited();
void count(int,int);
int ar[105][5] = {0};
int main()
{
	crited();
	int num;
	while(scanf("%d",&num) && num)
	{
		printf("%d: %d i, %d v, %d x, %d l, %d c\n",num,ar[num][0],ar[num][1],ar[num][2],ar[num][3],ar[num][4]);	
	}
	return 0;
}
void crited()
{
	int j;
	for(int i=1;i<100;i++)
	{
		j = i%10;
		count(i,j);
		if(i - j!=0) 
		{
			count(i,i-j);	
		}
	}
	count(100,100);
	for(int i=2;i<=100;i++)
	{
		ar[i][0] = ar[i][0] + ar[i-1][0];
		ar[i][1] = ar[i][1] + ar[i-1][1];
		ar[i][2] = ar[i][2] + ar[i-1][2];
		ar[i][3] = ar[i][3] + ar[i-1][3];
		ar[i][4] = ar[i][4] + ar[i-1][4];
	}
}
void count(int row,int num)
{
	if(num == 1)
	{
		ar[row][0] = ar[row][0] + 1;	
	}if(num == 2)
	{
		ar[row][0] = ar[row][0] + 2;	
	}if(num == 3)
	{
		ar[row][0] = ar[row][0] + 3;	
	}if(num == 4 || num == 6) 
	{
		ar[row][0] = ar[row][0] + 1;
		ar[row][1] = ar[row][1] + 1;
	}if(num == 5)
	{
		ar[row][1] = ar[row][1] + 1;
	}if(num == 7)
	{
		ar[row][0] = ar[row][0] + 2;
		ar[row][1] = ar[row][1] + 1;
	}if(num == 8)
	{
		ar[row][0] = ar[row][0] + 3;
		ar[row][1] = ar[row][1] + 1;
	}if(num == 9)
	{
		ar[row][2] = ar[row][2] + 1;
		ar[row][0] = ar[row][0] + 1;
	}if(num == 10)
	{
		ar[row][2] = ar[row][2] + 1;
	}if(num == 20)
	{
		ar[row][2] = ar[row][2] + 2;
	}if(num == 30)
	{
		ar[row][2] = ar[row][2] + 3;
	}if(num == 40 || num == 60)
	{
		ar[row][3] = ar[row][3] + 1;
		ar[row][2] = ar[row][2] + 1;
	}if(num == 50)
	{
		ar[row][3] = ar[row][3] + 1;
	}if(num == 70)
	{
		ar[row][3] = ar[row][3] + 1;
		ar[row][2] = ar[row][2] + 2;
	}if(num == 80)
	{
		ar[row][3] = ar[row][3] + 1;
		ar[row][2] = ar[row][2] + 3;
	}if(num == 90)
	{
		ar[row][4] = ar[row][4] + 1;
		ar[row][2] = ar[row][2] + 1;
	}if(num == 100)
	{
		ar[row][4] = ar[row][4] + 1;
	}
}
