#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 2000002
#define MAXN 1500
#define MAXP 250
void is_prime();
bool seev[MAXN + 2];
int prime[MAXP + 2];
long long count[MAX + 2];
long long save[MAX + 2];
int main()
{
    is_prime();
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("%lld\n",count[b] - count[a - 1]);
    }
    return 0;
}
void is_prime()
{
    int k = 0;
    long long  sum;
    int num;
    int n =  sqrt(MAXN);
    for(int i = 3 ; i < n ; i = i + 2)
    {
        if(seev[i] == false)
        {
            for(int j = i * i ; j < MAXN ; j = j + (2 * i))
            {
                seev[j] = true;
            }
        }
    }
    prime[k++] = 2;
    for(int i = 3 ; i < MAXN ; i = i + 2)
    {
         if(seev[i] == false) prime[k++] = i;
    }
    for(int i = 1 ; i < MAX ; i++)
    {
        num = sum = i;
        n = sqrt(i);
        for(int j = 0 ; prime[j] <= n ; j++)
        {
            if(num % prime[j] == 0)
            {
                sum = (sum * (prime[j] - 1)) / prime[j];
                while(num % prime[j] == 0) num = num / prime[j];
            }
        }
        if(num != 1 && num == sum) sum--;
        else if(num != 1) sum = (sum * (num - 1)) / num;
        save[i] = sum;
    }
    count[1] = count[2] = 1;
    for(int i = 3 ; i < MAX ; i++)
    {
        count[i] = count[save[i]] + 1;
    }
    for(int i = 1 ; i < MAX ; i++) count[i] = count[i] + count[i - 1];
}
