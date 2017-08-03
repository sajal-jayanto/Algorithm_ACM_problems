#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 1000000
int main()
{
    long long num,i;
    bool flage;
    while(scanf("%lld",&num) == 1)
    {
        if(num < 0) break;
        flage = false;
        for(i = 2 ; i <= MAX ; i++)
        {
            while(num % i == 0)
            {
                printf("    %lld\n",i);
                num = num / i;
            }
            if(num == 1)
            {
                flage = true;
                break;
            }
        }
        if(flage == false ) printf("    %lld\n",num);

        printf("\n");
    }
    return 0;
}
