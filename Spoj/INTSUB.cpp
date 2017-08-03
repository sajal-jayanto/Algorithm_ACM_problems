#include <bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;


int lim , cc = 0;
long long mod = 1000000007ll;
long long dp[2002][2002][4];
int vis[2002][2002][4];


long long call(int pos , int mn , int take)
{
    if(pos > lim)
    {
        if(take <= 1) return 0;
        if(take >= 3) return 1;
        return 0;
    }
    long long &ret = dp[pos][mn][take];
    if(vis[pos][mn][take] == cc) return ret;
    ret = 0;
    if(take == 0)
    {
        ret = ret + call(pos + 1 , pos , take + 1);
        ret = ret + call(pos + 1 , 0 , take);
    }
    else
    {
        if(take != 3 && pos % mn == 0) ret = ret + call(pos + 1 , mn , 3);
        else ret = ret + call(pos + 1 , mn , take);
        ret = ret + call(pos + 1 , mn , take);
    }
    if(ret >= mod) ret = ret % mod;
    vis[pos][mn][take] = cc;
    return ret;
}

int main()
{
//    freopen("input.txt" , "r" , stdin);
    int t , n ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        lim = (n << 1);
        ++cc;
        pf("Case %d: %lld\n" , cc , call(1 , 0 , 0));
    }
    return 0;
}
