#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 46350
#define MAXP 4793
void is_prime();
int divider(long long);
bool seev[MAX];
int prime[MAXP];
int main()
{
    is_prime();
    long long num,n,divides,sum,ans;
    while(scanf("%lld",&num) != EOF)
    {
        n = sqrt(num);
        sum = ans = num;
        divides = divider(num);
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
            sum--;
        }
        else if(num != 1 && num != sum)
        {
            sum = (sum * (num - 1)) / num;
        }
        sum = sum + divides;
        ans = ans - sum;
        printf("%lld\n",ans + 1);
    }

    return 0;
}

int divider(long long num)
{
    int count = 0;
    int n = sqrt(num);
    for(int i = 1 ; i <= n ; i++)
    {
        if(num % i == 0)
        {
            if(num / i != i) count = count + 2;
            else count = count + 1;
        }
    }
    return count;
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
            for(int j = i * i; j < MAX ; j = j  + (2 * i))
            {
                seev[j] = true;
            }
        }
    }
    for(int i = 3  ; i < MAX ; i =  i + 2)
    {
        if(seev[i] == false ) prime[k++] = i;
    }
}

