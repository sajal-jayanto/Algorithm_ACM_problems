#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char ar[128][128];
char lin[200];
int main()
{
    int i,j,n,len = 0;
    i = 0;
    while(gets(ar[i]))
    {
        if(len < strlen(ar[i])) len = strlen(ar[i]);
        i++;
    }
    for(j = i - 1 ; j >= 0 ; j--)
    {
        n = strlen(ar[j]);
        if(n != len)
        {
            while(n != len) { ar[j][n++] = ' ';}
        }
        ar[j][n] = '\0';
    }
    for(j = 0 ; j < len ; j++)
    {
        for(n = i - 1 ; n >= 0 ; n--)
        {
            printf("%c",ar[n][j]);
        }
        printf("\n");
    }
    return 0;
}
