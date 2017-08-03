#include<bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;
long long num[12] , k ;
long long dp[11][10002][100];
int vis[11][10002][100] , cc = 0;

long long call(int pos , int mod , int sum , int flag)
{
    if(pos == 0)
    {
        if(!mod && sum && sum % k == 0) return 1;
        return 0;
    }
    if(!flag && vis[pos][mod][sum] == cc) return dp[pos][mod][sum];
    int n = flag ? num[pos] : 9;
    long long ans = 0;
    for(int i = 0 ; i <= n ; ++i)
    ans = ans + call(pos - 1 , ((mod * 10) + i) % k , sum + i , flag && (i == n));
    if(!flag)
    {
        vis[pos][mod][sum] = cc;
        dp[pos][mod][sum] = ans;
    }
    return ans;
}


long long pro(long long n)
{
    ++cc;
    int len = 0;
    while(n)
    {
        num[++len] = n % 10;
        n = n / 10;
    }
    return call(len , 0 , 0 , 1);
}

int main()
{
    //freopen("tem.txt" , "r" , stdin);
    long long a , b;
    int t;
    sf("%d" , &t);
    while(t--)
    {
        sf("%lld %lld %lld" , &a , &b , &k);
        pf("%lld\n" , pro(b) - pro(a - 1));
    }
    return 0;
}
