#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 50
int algo_prime[] = { 2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,313,337,373,733,919,991};

int main()
{
    int num,n,r;
    bool flage;
    while(scanf("%d",&num) && num)
    {
        if(num >= 1000)
        {
            printf("0\n");
            continue;
        }
        if(num < 10)
        {
            n = 0;
            r = 3;
        }
        else if (num >= 10 && num < 100)
        {
            n = 4;
            r = 12;
        }
        else
        {
            n = 13;
            r = 22;
        }
        num++;
        flage = false;
        for(int i = n ; i <= r ; i++)
        {
            if(num <= algo_prime[i])
            {
                printf("%d\n",algo_prime[i]);
                flage = true;
                break;
            }
        }
        if(flage == false)
        {
            printf("0\n");
        }
    }
    return 0;
}
