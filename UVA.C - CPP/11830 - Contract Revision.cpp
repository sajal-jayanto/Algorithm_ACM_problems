#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAX 150

char num[MAX];

int main()
{
    int n,len,sum;
    while(scanf("%d %s",&n,num) == 2)
    {
        len =  strlen(num);
        if(n == 0 && len == 1 && num[0] == '0') break;
        sum = 0;
        for(int i = 0 ; i < len ; i++)
        {
            if(num[i] - 48 != n)
            {
                sum = sum + (num[i] - 48);
                if(num[i] == '0' && sum == 0)  continue;
                printf("%c",num[i]);
            }
        }
        if(sum == 0) printf("0");

        printf("\n");

    }
    return 0;
}
