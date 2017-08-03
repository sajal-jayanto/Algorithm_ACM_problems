#include <bits/stdc++.h>


using namespace std;

#define sf scanf
#define pf printf


int num[105];
int dp[105][105];
int vis[105][105];
int cc = 0;

int call(int s , int e)
{
    if(s > e) return 0;
    if(s == e) return 1;
    int &ret =  dp[s][e];
    if(vis[s][e] == cc) return ret;
    ret = call(s + 1 , e) + 1;
    for(int i = s + 1 ; i <= e ; ++i)
    {
        if(num[s] == num[i]) ret = min(ret , call(s + 1 , i - 1) + call(i , e));
    }
    vis[s][e] = cc;
    return ret;
}

int main()
{
    freopen("tem.txt" , "r" , stdin);
    int t , n , m ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &n , &m);
        for(int i = 1 ; i <= n ; ++i) sf("%d" , &num[i]);
        ++cc;
        pf("Case %d: %d\n" , cc , call(1 , n));
    }
    return 0;
}
