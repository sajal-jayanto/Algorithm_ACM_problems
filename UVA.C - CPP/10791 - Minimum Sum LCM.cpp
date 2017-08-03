#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define MAX 46350
#define MAXP 4793
void is_prime();
long long pow(int,int);
long long sum_factor(long long);
bool sevie[MAX];
int prime[MAXP];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    is_prime();
    long long num,count = 0;
    while(scanf("%lld",&num) && num)
    {
        if(num == 1)
        {
            printf("Case %lld: 2\n",++count);
            continue;
        }
        printf("Case %lld: %lld\n",++count,sum_factor(num));
    }
    return 0;
}
long long sum_factor(long long num)
{
    int n = sqrt(num);
    int count,p = 0;
    long long sum = 0,l = num;
    for(int i = 0 ; prime[i] <= n ; i++)
    {
        if(num % prime[i] == 0)
        {
            count = 0;
            p++;
            while(num % prime[i] == 0)
            {
                num = num / prime[i];
                count++;
            }
           sum = sum + pow(prime[i],count);
        }
    }
    if(num != 1)
    {
        sum = sum + num;
        if(p == 0) sum++;
    }
    else if(l == sum) sum++;
    return sum;
}
void is_prime()
{
    int k = 0;
    prime[k++] = 2;
    int n = sqrt(MAX);
    for(int i = 3 ; i < n ; i =  i + 2)
    {
        if(sevie[i] == false)
        {
            for(int j = i * i ; j < MAX ; j = j + (2 * i))
            {
                sevie[j] = true;
            }
        }
    }
    for(int i = 3 ; i < MAX ; i = i + 2)
    {
        if(sevie[i] == false) prime[k++] = i;
    }
}

long long pow(int n,int p)
{
    if(p == 0) return 1;
    if(p % 2 == 0)
    {
        long long temp = pow(n , p/2);
        return temp * temp;
    }
    else return n * pow(n , p - 1);
}
