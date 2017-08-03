#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define ROW 410
#define COL 875
void do_it();


unsigned int bord[ROW][COL];

int count[10];

int main()
{
    do_it();
    int num,n,i;
    while(scanf("%d",&num) && num)
    {
        n = 0;
        printf("%d! --\n",num);
        while(bord[num][n] == 0) n++;
        for(i = n ; i < COL ; i++)
        {
            if(bord[num][i] < 10)
            {
                count[bord[num][i]]++;
                continue;
            }
            while(bord[num][i])
            {
                count[bord[num][i] % 10]++;
                bord[num][i] = bord[num][i] / 10;
            }
        }
        printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",count[0],count[1],count[2],count[3],count[4]);
        printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",count[5],count[6],count[7],count[8],count[9]);
        for(int i = 0 ; i < 10 ;i++)  count[i] = 0;
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


