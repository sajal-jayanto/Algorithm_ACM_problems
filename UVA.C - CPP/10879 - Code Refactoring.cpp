#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int t,i,n,num,count = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        printf("Case #%d: %d",++count,num);
        n = 0;
        for(i = 2 ; i < sqrt(num) + 1 ; i++)
        {
            if(num % i == 0)
            {
                printf(" = %d * %d",i,num/i);
                n++;
            }
            if (n == 2) break;
        }
        printf("\n");
    }
    return 0;
}
