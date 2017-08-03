#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

vector < int > ve[100002];
bool memo[100002];
int dp[100002][2];
bool vis[100002][2];

int call(int now , int last , int root)
{
    memo[now] = true;
    int &ret = dp[now][last];
    if(vis[now][last]) return ret;
    ret = 0;
    for(int i = 0 ; i < (int) ve[now].size() ; ++i)
    {
        if(ve[now][i] == root) continue;
        ret += call(ve[now][i] , 1 , now);
    }
    ret++;
    if(last)
    {
        int x = 0;
        for(int i = 0 ; i < (int) ve[now].size() ; ++i)
        {
            if(ve[now][i] == root) continue;
            x += call(ve[now][i] , 0 , now);
        }
        ret = min(ret , x);
    }
    vis[now][last] = true;
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int n , a, b;
    sf("%d" , &n);
    for(int i = 1 ; i < n ; ++i)
    {
        sf("%d %d" , &a , &b);
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        if(!memo[i]) ans = ans + call(i , 1 , 200000);
    }
    pf("%d\n" , ans);
    return 0;
}
