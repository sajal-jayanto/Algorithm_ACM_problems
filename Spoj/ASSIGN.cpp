#include <bits/stdc++.h>

using namespace std;

#define sf         scanf
#define pf         printf
#define fr         first
#define se         second
#define PI         (2 *  acos(0.0))
#define eps        1e-7
#define mem(a,b)   memset(a, b, sizeof(a))
#define ios        ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false)


bool num[22][22];
int n , lim , cc = 0;
long long dp[21][(1 << 20) + 5];
int vis[21][(1 << 20) + 5];

long long call(int take , int mark)
{
    if(mark == lim)
    {
        if(take == n) return 1;
        return 0;
    }
    long long &ret = dp[take][mark];
    int k;
    if(vis[take][mark] == cc) return ret;
    ret = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        k = __builtin_popcount(mark);
        if((mark & (1 << i)) == 0 && num[k][i])
        {
            ret = ret + call(take + num[k][i] , (mark | (1 << i)) );
        }
    }
    vis[take][mark] = cc;
    return ret;
}


int main()
{
   // freopen("tem.txt" , "r" , stdin);
    long long ans ;
    int t ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j) sf("%d" , &num[i][j]);
        }
        lim = (1 << n) - 1;
        ++cc;
        pf("%lld\n" , call(0 , 0));
    }
    return 0;
}
