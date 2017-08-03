#include <bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

int num[12];
bool sive[100];
long long dp[10][90];
int vis[10][90];


void is_prime()
{
    int k = sqrt(100);
    for(int i = 2 ; i <= k ; ++i)
    {
        for(int j = i + i ; j < 100 ; j = j + i) sive[j] = true;
    }
    sive[0] = sive[1] = true;
}

long long call(int pos , int sum , int flag)
{
    if(pos == 0)
    {
        if(!sive[sum]) return 1;
        return 0;
    }
    if(!flag && vis[pos][sum]) return dp[pos][sum];
    int n = flag ? num[pos] : 9;
    long long ans = 0;
    for(int i = 0 ; i <= n ; ++i)
    {
        ans = ans + call(pos - 1 , sum + i , flag && (i == n));
    }
    if(!flag)
    {
        vis[pos][sum] = true;
        dp[pos][sum] = ans;
    }
    return ans;
}

long long pro(int n)
{
    if(n == 0) return 0;
    int len = 0;
    while(n)
    {
        num[++len] = n % 10;
        n = n / 10;
    }
    return call(len , 0 , 1);
}

int main()
{
    is_prime();
    int t , a , b;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &a , &b);
        pf("%lld\n" , pro(b) - pro(a - 1));
    }
    return 0;
}
