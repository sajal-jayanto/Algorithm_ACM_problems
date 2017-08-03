#include <bits/stdc++.h>


#define sf scanf
#define pf printf
#define MAX 87000000

using namespace std;

bool sive[10010];
int prime[10010];

void is_prime()
{
    int k = sqrt(10010) , cnt = 0;
    prime[cnt++] = 2;
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sive[i]) for(int j = i * i ; j < 10010 ; j = j + (2 * i)) sive[j] = true;
    }
    for(int i = 3 ; i < 10010 ; i = i + 2) if(!sive[i]) prime[cnt++] = i;
}

long long big_mod(int num , int p , long long mod)
{
    long long sum = 1 , temp = num;
    while(p)
    {
        if(p & 1) sum = (sum * temp) % mod;
        temp = (temp * temp) % mod; p = p >> 1;
    }
    return sum;
}


int main()
{
    is_prime();
    int t , n  , cnt , num , mod = 1000000007ll;
    long long ans;
    sf("%d" , &t);
    while(t--)
    {
        ans = 1;
        sf("%d" , &n);
        for(int i = 0 ; prime[i] <= n ; ++i)
        {
            num = prime[i];
            cnt = 0;
            while(num <= n)
            {
                num = num * prime[i];
                ++cnt;
            }
            ans = ans * big_mod(prime[i] , cnt , mod);
            if(ans >= mod) ans = ans % mod;
        }
        pf("%lld\n" , ans);
    }
    return 0;
}
