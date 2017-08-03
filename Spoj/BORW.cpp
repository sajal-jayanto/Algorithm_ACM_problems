#include<bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

int t , cc = 0, ar[250];
int dp[202][202][202];
int vis[202][202][202];


int call(int pos , int b , int w)
{
    if(pos > t) return 0;
    int &ret = dp[pos][b][w];
    if(vis[pos][b][w] == cc) return ret;
    ret = 0;
    if(!b) ret = max(ret , call(pos + 1 , pos , w) + 1);
    if(!w) ret = max(ret , call(pos + 1 , b , pos) + 1);
    if(b && ar[b] > ar[pos]) ret = max(ret , call(pos + 1 , pos , w) + 1);
    if(w && ar[w] < ar[pos]) ret = max(ret , call(pos + 1 , b , pos) + 1);
    ret = max(ret , call(pos + 1 , b , w));
    vis[pos][b][w] = cc;
    return ret;
}

int main()
{
//    freopen("input.txt" , "r" , stdin);
    int ans ;
    while(sf("%d" , &t) && t != -1)
    {
        for(int i = 1 ; i <= t ; ++i) sf("%d" , &ar[i]);
        ++cc;
        ans = call(1 , 0 , 0);
        pf("%d\n" , t - ans);
    }
    return 0;
}

