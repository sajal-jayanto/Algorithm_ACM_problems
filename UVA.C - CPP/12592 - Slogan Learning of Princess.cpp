#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define N 25
#define L 120
char they[N][L];
char me[N][L];
char dammy[L];
int main()
{
    int t,n;
    scanf("%d",&t);
    gets(dammy);
    for(int i = 0 ;i < t ; i++)
    {
        gets(they[i]);
        gets(me[i]);
    }
    scanf("%d",&n);
    gets(dammy);
    while(n--)
    {
        gets(dammy);
        for(int i = 0 ; i < t ; i++)
        {
            if(strcmp(they[i],dammy) == 0)
            {
                printf("--%s\n",me[i]);
                break;
            }
        }
    }
    return 0;
}
