#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define MAX 2010
char num[MAX];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %s",&n,num);
        int len = strlen(num);
        int sum = 0;
        for(int i = 0 ; i < len ; i++)
        {
            sum = (sum * 10) + (num[i] - 48);
            sum = sum % n;
        }
        printf("%d\n",sum);
    }

    return 0;
}

