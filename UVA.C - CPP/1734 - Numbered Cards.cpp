#include <bits/stdc++.h>

#define sf scanf
#define pf printf

#define MAX 20000010

using namespace std;

int dig[12] , rmask , cc = 0;
long long dp[11][2][1025];
long long DP[1025][1025];
int viss[1025][1025];
int vis[11][2][1025];
long long ans[1025];
long long mod = 1000000007ll;


long long call(int pos , int can , int mask , int flag)
{
    if(pos == 0)
    {
        if(mask == rmask) return 1;
        return 0;
    }
    int lim = flag ? dig[pos] : 9;
    if(!flag && vis[pos][can][mask] == cc) return dp[pos][can][mask];
    long long ret = 0;
    for(int i = 0 ; i <= lim ; ++i)
    {
        if(can) ret = ret + call(pos - 1 , can , mask | (1 << i) , flag && (i == lim));
        else
        {
            if(!i) ret = ret + call(pos - 1 , can , mask , flag && (i == lim));
            else ret = ret + call(pos - 1 , 1 , mask | (1 << i) , flag && (i == lim));
        }
    }
    if(!flag)
    {
        vis[pos][can][mask] = cc;
        dp[pos][can][mask] = ret;
    }
    return ret;
}

int pro(int num)
{
    int len = 0;
    while(num)
    {
        dig[++len] = num % 10;
        num = num / 10;
    }
    return len;
}

long long Call(int pos , int mask)
{
    if(pos >= 1024) return 1ll;
    long long &ret = DP[pos][mask];
    if(viss[pos][mask] == cc) return ret;
    ret = 0;
    if((mask & pos) == 0) ret = ret + (ans[pos] * Call(pos + 1 , mask | pos)) % mod;
    if(ret >= mod) ret = ret - mod;
    ret = ret + Call(pos + 1 , mask);
    if(ret >= mod) ret = ret - mod;
    viss[pos][mask] = cc;
    return ret;
}

int main()
{
//    freopen("input.txt" , "r" , stdin);
    int t , n , len , cas = 0;
    long long sum;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        len = pro(n);
        for(int i = 2 ; i < 1024 ; ++i)
        {
            rmask = i;
            ++cc;
            ans[i] = call(len , 0 , 0 , 1);
        }
        ++cc;
        sum = Call(2 , 0);
        sum--;
        if(sum < 0) sum = sum + mod;
        pf("Case %d: %lld\n" , ++cas , sum);
    }
    return 0;
}
