#include <bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

int n , t , cc = 0;
long long ar[15][8];
int need[10];
long long dp[10][10][10][10][10][10];
int vis[10][10][10][10][10][10];

long long call(int a , int b , int c , int d , int e , int f)
{
    if(!a && !b && !c && !d && !e && !f) return 0;
    if(a < 0 || b < 0 || c < 0 || e < 0 || f < 0) return 100000000000000000ll;
    long long &ret = dp[a][b][c][d][e][f];
    if(vis[a][b][c][d][e][f] == cc) return ret;
    ret = 100000000000000000ll;
    for(int i = 0 ; i < t ; ++i)
    {
        if(a >= ar[i][1] && b >= ar[i][2] && c >= ar[i][3] && d >= ar[i][4] && e >= ar[i][5] && f >= ar[i][6])
        ret = min( ret , call(a - ar[i][1] , b - ar[i][2] , c - ar[i][3] ,d - ar[i][4] , e - ar[i][5] , f - ar[i][6]) + ar[i][0]);
    }
    vis[a][b][c][d][e][f] = cc;
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int r ;
    while(sf("%d" , &n) == 1)
    {
        memset(ar , 0 , sizeof(ar));
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%lld" , &ar[i][0]);
            ar[i][i + 1] = 1;
        }
        sf("%d" , &t);
        for(int i = 0 ; i < t ; ++i)
        {
            for(int j = 1 ; j <= n ; ++j) sf("%lld" , &ar[i + n][j]);
            sf("%lld" , &ar[i + n][0]);
        }
        t = t + n;
        sf("%d" , &r);
        ++cc;
        while(r--)
        {
            memset(need , 0 , sizeof(need));
            for(int i = 0 ; i < n ; ++i) sf("%d" , &need[i]);
            pf("%lld\n" , call(need[0] , need[1] , need[2] , need[3] , need[4] , need[5]));
        }
    }
    return 0;
}
