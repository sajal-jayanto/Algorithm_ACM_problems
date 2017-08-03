#include<bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;


vector < int > ve[105];
int dp[105][505];

int call(int s , int e , int cnt)
{
    if(cnt == 0)
    {
        if(s == e) return 1;
        return 0 ;
    }
    if(s == e) return 0;
    int &ret = dp[s][cnt];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0 ; i < ve[s].size() ; ++i)
    {
        if(ve[s][i] != s) ret = ret | call(ve[s][i] , e , cnt - 1);
    }
    return ret;
}


int main()
{
   // freopen("tem.txt" , "r" , stdin);
    int n , m , a , b , s, e , cnt ;
    while(sf("%d %d" , &n , &m) && (n || m))
    {
        while(m--)
        {
            sf("%d %d" , &a , &b);
            ve[a].push_back(b);
            ve[b].push_back(a);
        }
        sf("%d %d %d", &s , &e , &cnt);
        memset(dp , -1 , sizeof(dp));
        if(call(s , e, cnt)) pf("Yes, Teobaldo can travel.\n");
        else pf("No, Teobaldo can not travel.\n");
        for(int i = 0 ; i <= n ; ++i) ve[i].clear();
    }
    return 0;
}
