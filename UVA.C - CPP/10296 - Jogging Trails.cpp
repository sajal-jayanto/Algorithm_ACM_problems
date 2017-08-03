#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

int dp[16][16];
int deeg[16];
int odd[16] , lim , cnt , cc = 0;
int DP[(1 << 16) + 2];
int vis[(1 << 16) + 2];

int call(int mask)
{
    if(mask >= lim) return 0;
    int rmask , &ret = DP[mask];
    if(vis[mask] == cc) return ret;
    ret = (1 << 30);
    for(int i = 0 ; i < cnt ; ++i)
    {
        if(!(mask & (1 << i)))
        {
            for(int j = i + 1 ; j < cnt ; ++j)
            {
                if(!(mask & (1 << j)))
                {
                    rmask = mask;
                    rmask = mask | (1 << i);
                    rmask = rmask | (1 << j);
                    ret = min(ret , call(rmask) + dp[odd[i]][odd[j]]);
                }
            }
            break ;
        }
    }
    vis[mask] = cc;
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int n , m , a , b , c , sum ;
    while(sf("%d" , &n) && n)
    {
        sf("%d" , &m);
        sum = cnt = 0;
        for(int i = 0 ; i < 16 ; ++i) for(int j = 0 ; j < 16 ; ++j)
        {
            deeg[i] = 0;
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = (1 << 20);
        }
        for(int i = 0 ; i < m ; ++i)
        {
            sf("%d %d %d" , &a , &b , &c);
            dp[a][b] = min(dp[a][b] , c);
            dp[b][a] = min(dp[b][a] , c);
            deeg[a]++; deeg[b]++;
            sum = sum + c;
        }
        for(int k = 1 ; k <= n ; ++k) for(int i = 1 ; i <= n ; ++i) for(int j = 1 ; j <= n ; ++j)
        {
            dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            if(deeg[i] & 1) odd[cnt++] = i;
        }
        lim = (1 << cnt) - 1;
        ++cc;
        pf("%d\n" , sum + call(0));
    }
    return 0;
}
