#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 46350
#define MAXP 4794
#define MAXN 1000
void is_prime();
void made_factor(long long);
bool seev[MAX];
int prime[MAXP];
int count_p[MAXN];
int count_n[MAXN];

int k;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    is_prime();
    long long a,b,sum,n;
    bool flage;
    while(scanf("%lld %lld",&a,&b) == 2)
    {
        if(a == 0 && b == 1)
        {
             printf("%lld divides %lld!\n",b,a);
             continue;
        }
        if(a == 0 || b == 0)
        {
            printf("%lld does not divide %lld!\n",b,a);
            continue;
        }
        if(a >= b)
        {
            printf("%lld divides %lld!\n",b,a);
            continue;
        }
        made_factor(b);
        flage = true;
        for(int i = 0 ; i < k ; i++)
        {
            sum = 0;
            n = a;
            while(n >= count_p[i])
            {
                sum = sum + n / count_p[i];
                n = n / count_p[i];
            }
            if(sum >= count_n[i])
            {
                flage = true;
            }
            else
            {
                flage = false;
                break;
            }
        }
        if(flage == true)
        {
             printf("%lld divides %lld!\n",b,a);
        }
        else printf("%lld does not divide %lld!\n",b,a);
    }
    return 0;
}

void made_factor(long long num)
{
    k = 0;
    int n = sqrt(num);
    int count;
    for(int i = 0 ; prime[i] <= n ; i++)
    {
        if( num % prime[i] == 0)
        {
            count = 0;
            while(num % prime[i] == 0)
            {
                count++;
                num = num / prime[i];
            }
            count_p[k] = prime[i];
            count_n[k] = count;
            k++;
        }
    }
    if(num != 1)
    {
        count_p[k] = num;
        count_n[k] = 1;
        k++;
    }
}

void is_prime()
{

    int k = 0;
    prime[k++] = 2;
    int n = sqrt(MAX);
    for(int i = 3 ; i < n ; i = i + 2)
    {
        if(seev[i] ==  false)
        {
            for(int j = i * i ; j < MAX ; j = j + (2 * i))
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
