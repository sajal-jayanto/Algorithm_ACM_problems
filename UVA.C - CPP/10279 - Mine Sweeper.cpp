#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define S 15
void made(int,int);
char bord1[S][S];
char bord2[S][S];
int num[S][S];
int main()
{
    //freopen("output.txt","w",stdout);
    int t,n;
    bool flage;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        gets(bord1[0]);
        flage = false;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                num[i][j] = 0;
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            gets(bord1[i]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            gets(bord2[i]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(bord1[i][j] == '*')
                {
                    made(i,j);
                }
                if((bord1[i][j] == '*') && (isalpha(bord2[i][j]) != 0))
                {
                    flage = true;
                }
            }
        }
        if(flage == false)
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(isalpha(bord2[i][j]) != 0)
                    {
                        printf("%d",num[i][j]);
                    }
                    else printf("%c",bord2[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if((bord1[i][j] == '*') && (isalpha(bord2[i][j]) != 0))
                    {
                        printf("*");
                    }
                    else if(isalpha(bord2[i][j]) != 0)
                    {
                         printf("%d",num[i][j]);
                    }
                    else if(bord1[i][j] == '*')
                    {
                        printf("%c",bord1[i][j]);
                    }
                    else printf("%c",bord2[i][j]);
                }
                printf("\n");
            }
        }
        if(t != 0) printf("\n");
    }
    return 0;
}
void made(int i , int j)
{
    num[i - 1][j]++;
    num[i - 1][j + 1]++;
    num[i][j + 1]++;
    num[i + 1][j + 1]++;
    num[i + 1][j]++;
    num[i + 1][j - 1]++;
    num[i][j - 1]++;
    num[i - 1][j - 1]++;
}
