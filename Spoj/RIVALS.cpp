#include <bits/stdc++.h>


using namespace std;

#define sf scanf
#define pf printf

long long mod = 1000000007ll;
long long ar[2000100];

long long bigmod(long long num , long long p)
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
    ar[0] = 1;
    for(long long i = 1 ; i <= 2000010 ; ++i) ar[i] = (ar[i - 1] * i) % mod;
    int t ;
    long long x , y , temp , ans ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%lld %lld" , &x , &y);
        if(x < y) swap(x , y);
        temp = x + y;
        ans = (ar[y] * ar[temp - y]) % mod;
        ans = bigmod(ans , mod - 2);
        ans = (ar[temp] * ans) % mod;
        pf("%lld\n" , ans);
    }
    return 0;
}
