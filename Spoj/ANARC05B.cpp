#include <bits/stdc++.h>

using namespace std;


#define sf scanf
#define pf printf

long long one[10010] , two[10010] , x[20010] , y[20010];
long long dp[10010][2] , vis[10010][2];
int n , m , cc = 0;

long long call(int pos , int flag)
{
    if(flag == 0 && pos >= n) return 0;
    if(flag && pos >= m) return 0;
    long long &ret = dp[pos][flag];
    if(vis[pos][flag] == cc) return ret;
    ret = -1000000000000ll;
    if(flag == 0)
    {
        if(x[one[pos]] != -1 && y[one[pos]] != -1)
        {
            ret = max(ret , call(x[one[pos]] + 1 , 0) + (one[pos] - 10000));
            ret = max(ret , call(y[one[pos]] + 1 , 1) + (one[pos] - 10000));
        }
        else ret = max(ret , call(pos + 1 , 0) + (one[pos] - 10000));
    }
    else
    {
        if(x[two[pos]] != -1 && y[two[pos]] != -1)
        {
            ret = max(ret , call(y[two[pos]] + 1 , 1) + (two[pos] - 10000));
            ret = max(ret , call(x[two[pos]] + 1 , 0) + (two[pos] - 10000));
        }
        else ret = max(ret , call(pos + 1 , 1) + (two[pos] - 10000));
    }
    vis[pos][flag] = cc;
    return ret;
}

int main()
{
    //freopen("tem.txt" ,"r" , stdin);
    long long mx ;
    while(sf("%d" , &n) && n)
    {
        for(int i = 0 ; i < 20005 ; ++i)
        {
            x[i] = -1 ;
            y[i] = -1 ;
        }
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%lld" , &one[i]);
            one[i] = one[i] + 10000;
            if(x[one[i]] == -1) x[one[i]] = i;
        }
        sf("%d" , &m);
        for(int i = 0 ; i < m ; ++i)
        {
            sf("%lld" , &two[i]);
            two[i] = two[i] + 10000;
            if(y[two[i]] == -1) y[two[i]] = i;
        }
        ++cc;
        mx = max( call(0 , 0) , call(0 , 1));
        pf("%lld\n" , mx);
    }
    return 0;
}