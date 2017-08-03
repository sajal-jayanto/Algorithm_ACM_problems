#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

char str[1010];
int cc = 0;
int dp[1010][1010];
int vis[1010][1010];

int call(int s , int e)
{
    if(s >= e) return 0;
    int &ret = dp[s][e];
    if(vis[s][e] == cc) return ret;
    ret = (1 << 30);
    if(str[s] == str[e]) ret = call(s + 1 , e - 1);
    else ret = min(call(s + 1 , e) + 1 , call(s , e - 1) + 1);
    vis[s][e] = cc;
    return ret;
}

void path(int s , int e)
{
    if(s > e) return ;
    if(s == e) { pf("%c" , str[s]); return ; }
    if(str[s] == str[e])
    {
        pf("%c", str[s]);
        path(s + 1 , e - 1);
        pf("%c" , str[e]);
    }
    else if(dp[s][e] == dp[s + 1][e] + 1)
    {
        pf("%c", str[s]);
        path(s + 1 , e);
        pf("%c" , str[s]);
    }
    else
    {
        pf("%c", str[e]);
        path(s , e - 1);
        pf("%c" , str[e]);
    }
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int ans , len ;
    while(sf("%s" , str) != EOF)
    {
        ++cc;
        len = strlen(str);
        ans = call(0 , len - 1);
        pf("%d " , ans);
        path(0 , len - 1);
        pf("\n");
    }
    return 0;
}
