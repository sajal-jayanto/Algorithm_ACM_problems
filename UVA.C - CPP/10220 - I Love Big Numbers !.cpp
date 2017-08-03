#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define ROW 1010
#define COL 2580
void do_it();


unsigned int bord[ROW][COL];

int count[10];

int main()
{
    do_it();
    int num,i;
    long long sum;
    while(scanf("%d",&num)  == 1)
    {
        sum = 0;
        for(i = 0 ; i < COL ; i++)
        {
            sum = sum + bord[num][i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}

void do_it()
{
    int i,j,sum;
    bord[0][COL - 1] = 1;
    bord[1][COL - 1] = 1;
    for( i = 2 ; i < ROW - 9 ; i++)
    {
        sum = 0;
        for(j = COL - 1 ; j > 0 ; j--)
        {
            sum = sum + (bord[i - 1][j] * i);
            bord[i][j] =  sum % 10;
            sum = sum / 10;
        }
        if(sum != 0 ) bord[i][j] = sum ;
    }
}


