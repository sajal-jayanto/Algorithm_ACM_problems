#include <bits/stdc++.h>


using namespace std;

#define sf scanf
#define pf printf

long long dp[10010][12];
int vis[10010][12];
char str[10010];
int len , cc = 0;
long long mod = 1000000007ll;

long long call(int last , int pos)
{
    if(pos >= len) return 1;
    long long &ret = dp[pos][last];
    if(vis[pos][last] == cc) return ret;
    ret = 0;
    int id = (str[pos] - '0') + 1;
    if(last < id ) ret = ret + call(id , pos + 1);
    if(ret >= mod) ret = ret % mod;
    ret = ret + call(last , pos + 1);
    if(ret >= mod) ret = ret % mod;
    vis[pos][last] = cc;
    return ret;
}

int main()
{
//    freopen("input.txt" , "r" , stdin);
    int t;
    long long ans ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%s" , str);
        len = strlen(str);
        ++cc;
        ans = call(0 , 0);
        pf("Case %d: %lld\n" , cc , ans - 1);
    }
    return 0;
}
