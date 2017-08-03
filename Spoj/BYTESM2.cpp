#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

long long num[105][105];
long long dp[105][105];
int n , m ;

long long call(int row , int col)
{
    if(col < 0 || col >= m || row < 0 || row >= n) return -10000000;
    if(row == n - 1) return num[row][col];
    long long &ret = dp[row][col];
    if(ret != -1) return ret;
    ret = -10000000;
    ret = max(ret , num[row][col] + call(row + 1 , col - 1));
    ret = max(ret , num[row][col] + call(row + 1 , col));
    ret = max(ret , num[row][col] + call(row + 1 , col + 1));
    return ret;
}


int main()
{
    //freopen("tem.txt" , "r" , stdin);
    int t ;
    long long ans ;
    sf("%d" , &t);
    while(t--)
    {
        memset(dp , -1 , sizeof(dp));
        sf("%d %d" , &n , &m);
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j) sf("%lld" , &num[i][j]);
        }
        ans = 0;
        for(int i = 0 ; i < m ; ++i) ans = max(ans , call(0 , i));
        pf("%lld\n" , ans);
    }
    return 0;
}
