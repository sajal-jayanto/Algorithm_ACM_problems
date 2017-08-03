#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf


long long dig[65];
long long dp[30][30];
bool vis[30][30];

long long call(int pos , int cnt , int flag)
{
    if(pos == 0) return cnt;
    if(!flag && vis[pos][cnt]) return dp[pos][cnt];
    long long ans = 0;
    int n = flag ? dig[pos] : 1;
    for(int i = 0 ; i <= n ; ++i)
    ans = ans + call(pos - 1 , cnt + (i == 1) , flag && (i == n));
    if(!flag)
    {
        vis[pos][cnt] = true;
        dp[pos][cnt] = ans;
    }
    return ans;
}


long long pro(int num)
{
    if(num == 0) return 0;
    int len = 0;
    while(num)
    {
        dig[++len] = (num % 2);
        num = num / 2;
    }
    return call(len , 0 , 1);
}

int main()
{
    int n , m  , cc = 0;
    while( sf("%d %d" , &n , &m) && (n || m))
    {
        pf("Case %d: %lld\n" , ++cc , pro(m) - pro(n - 1));
    }
    return 0;
}
