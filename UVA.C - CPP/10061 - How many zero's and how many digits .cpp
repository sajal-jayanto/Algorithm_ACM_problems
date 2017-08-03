#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 805
#define MAXP 140
bool seev[MAX];
int prime[MAXP];
int count_p[MAXP];
int count_n[MAXP];
void is_prime();
long long digit_of_factoril(long long ,long long);
void b_prime(long long num);
int k;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    is_prime();
    long long num,base,sum,n;
    bool flage;
    while(scanf("%lld %lld",&num,&base) == 2)
    {
        b_prime(base);
        flage = true;
        for(int i = 0 ; i < k ; i++)
        {
            sum = 0;
            n = num;
            while(n >= count_p[i])
            {
                sum = sum + n / count_p[i];
                n = n / count_p[i];
            }
            if(sum >= count_n[i])
            {
                count_n[i] = sum / count_n[i];
            }
            else
            {
                printf("0 %lld\n",digit_of_factoril(num,base));
                flage = false;
                break;
            }
        }
        if(flage == true)
        {
            n = count_n[0];
            for(int i = 0 ; i < k ; i++)
            {
                if(n > count_n[i]) n = count_n[i];
            }
            printf("%lld %lld\n",n,digit_of_factoril(num,base));
        }
    }
    return 0;
}

void is_prime()
{
    int k = 0;
    prime[k++] = 2;
    int n = sqrt(MAX);
    for(int i = 3 ; i < n ; i++)
    {
        if(seev[i] == false)
        {
            for(int j = i * i  ; j < MAX ; j = j + (2 * i))
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

void b_prime(long long num)
{
    int count;
    int n = sqrt(num);
    k = 0;
    for(int i = 0 ; prime[i] <= n ; i++)
    {
        if(num % prime[i] == 0)
        {
            count = 0;
            while(num % prime[i] == 0)
            {
                num = num / prime[i];
                count++;
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

long long digit_of_factoril(long long num, long long b)
{

    long double sum = 0.00;
    long long ans;
    for(int i = 1 ; i <= num ; i++)
    {
        sum = sum + log10(i);
    }
    sum = sum / log10(b);
    ans = floor(sum) + 1;
    return ans;
}

