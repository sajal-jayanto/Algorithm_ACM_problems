#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

long long dp[15];
long long fac[15];

long long call(int n)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    long long &ret = dp[n];
    if(ret != -1) return ret;
    return ret = (n - 1) * (call(n - 1) + call(n - 2));
}

int main()
{
    memset(dp , -1 , sizeof(dp));
    fac[0] = 1;
    for(long long i = 1 ; i < 15 ; ++i) fac[i] = fac[i - 1] * i;
    int t , n ;
    long long g , temp ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        temp = call(n);
        pf("%lld/%lld\n" , temp  , fac[n]);
    }
    return 0;
}
