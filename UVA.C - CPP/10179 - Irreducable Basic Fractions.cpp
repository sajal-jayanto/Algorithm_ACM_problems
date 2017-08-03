#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define MAX 32000
#define MAXP 3432
void is_prime();
bool seev[MAX];
int prime[MAXP];

int main()
{
    is_prime();
    int num,n;
    long long sum;
    while(scanf("%d",&num) && num)
    {
        n = sqrt(num);
        sum = num;
        for(int i = 0 ; prime[i] <= n ; i++)
        {
            if(num % prime[i] == 0)
            {
                sum = (sum * (prime[i] - 1)) / prime[i];
                while(num % prime[i] == 0)
                {
                    num = num / prime[i];
                }
            }
        }
        if(num != 1 && num == sum)
        {
            sum = num - 1;
        }
        else if(num != 1 )
        {
            sum = (sum * (num - 1)) / num;
        }
        printf("%lld\n",sum);
    }
    return 0;
}

void is_prime()
{
    int k = 0;
    prime[k++] = 2;
    int n = sqrt(MAX);
    for(int i = 3 ; i < n ; i = i + 2)
    {
        if(seev[i] == false)
        {
            for(int j = i * i ; j < MAX ; j = j + (i * 2))
            {
                seev[j] = true;
            }
        }
    }
    for(int i = 3 ; i < MAX ; i = i + 2)
    {
        if(seev[i] == false) prime[k++] = i;
    }
}

