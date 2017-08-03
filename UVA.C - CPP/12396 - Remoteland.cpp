#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define MAX 5000100
#define MAXR 348520
using namespace std;

bool sive[MAX];
int prime[MAXR];


void is_prime()
{
    int n = 0 , k = sqrt(MAX);
    prime[n++] = 2;
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sive[i]) for(int j = (i * i) ; j < MAX ; j = j + (2 * i)) sive[j]= true;
    }
    for(int j = 3 ; j < MAX ; j = j + 2) if(!sive[j]) prime[n++] = j;
}


long long big_mod(long long num , int p , long long mod)
{
    long long sum = 1 , temp = num;
    while(p)
    {
        if(p & 1) sum = (sum * temp) % mod;
        temp = (temp * temp) % mod;
        p = p >> 1;
    }
    return sum;
}

int times(int num , int p)
{
    int cnt = 0;
    while(num >= p)
    {
        num = num / p;
        cnt = cnt + num;
    }
    return cnt;
}

int main()
{
    is_prime();
    int num , half , cnt ;
    long long sum ;
    long long mod = 1000000007ll;
    while(sf("%d" , &num) && num)
    {
        sum = 1;
        half = num / 2;
        for(int i = 0 ; prime[i] <= half ; ++i)
        {
            cnt = times(num , prime[i]);
            if(cnt & 1) cnt--;
            if(cnt >= 2) sum = (sum * big_mod(prime[i] , cnt , mod)) % mod;
        }
        pf("%lld\n" , sum);
    }
    return 0;
}

