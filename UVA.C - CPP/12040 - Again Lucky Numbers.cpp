#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define MAX  1010

using namespace std;

char str[105];
int mark[105];
int len ,lenb , cc = 0;
long long dp[105][105];
int vis[105][105];
long long mod = 10000007ll;

void pre_fix()
{
    int k = 0;
    mark[0] = 0;
    for(int i = 1 ; i < lenb ; ++i)
    {
        while(k > 0 && str[i] != str[k]) k = mark[k - 1];
        if(str[i] == str[k]) k++;
        mark[i] = k;
    }
}

long long call(int pos , int match )
{
    if(match >= lenb) return 0;
    if(pos >= len) return 1;
    long long &ret = dp[pos][match];
    if(vis[pos][match] == cc) return ret;
    int temp = match , lim = pos ? 0 : 1;
    ret = 0;
    for(int i = lim ; i <= 9 ; ++i)
    {
        while(temp)
        {
            if((str[temp] - '0') == i) break ;
            temp = mark[temp - 1];
        }
        if((str[temp] - '0') == i) ret = ret + call(pos + 1 , temp + 1);
        else ret = ret + call(pos + 1 , temp);
        if(ret >= mod) ret = ret % mod;
        temp = match ;
    }
    vis[pos][match] = cc;
    return ret;
}

int main()
{
    freopen("input.txt" , "r" , stdin);
    int t ;
    long long ans ;
    sf("%d" , &t);
    while(t--)
    {
        ++cc;
        sf("%d %s" , &len , str);
        lenb = strlen(str);
        pre_fix();
        ans = call(0 , 0);
        if(len == 1) ans++;
        pf("%lld\n" , ans % mod);
    }
    return 0;
}
