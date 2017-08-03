#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

long long num[10];
long long DP[10][10][2];
bool vis[10][10][2];
long long kye ;
long long total1[12] , total2[12];

long long call(int pos , int cnt , int can , int flag)
{
    if(pos == 0) return cnt;
    if(!flag && vis[pos][cnt][can]) return DP[pos][cnt][can];
    int n = flag ? num[pos] : 9;
    long long ans = 0;
    for(int i = 0 ; i <= n ; ++i)
    {
        if(kye == 0) ans = ans + call(pos - 1 , cnt + (!can && !i) , can && !i , flag && (i == n));
        else ans = ans + call(pos - 1 , cnt + (i == kye) , can , flag && (i == n));
    }
    if(!flag)
    {
        vis[pos][cnt][can] = true;
        DP[pos][cnt][can] = ans;
    }
    return ans;
}

void pro(long long n)
{
    memset(total2 , 0 , sizeof(total2));
    int len = 0;
    while(n)
    {
        num[++len] = n % 10LL;
        n = n / 10LL;
    }
    for(int i = 0 ; i < 10 ; ++i)
    {
        memset(vis, false , sizeof(vis));
        kye = i;
        total2[i] = call(len , 0 , 1 , 1);
    }
}

int main()
{
    freopen("input.txt" , "r" , stdin);
    long long a , b;
    while(sf("%lld %lld" , &a  , &b) && (a || b))
    {
        pro(a - 1);
        for(int i = 0 ; i < 10 ; ++i) total1[i] = total2[i];
        pro(b);
        pf("%d" , total2[0] - total1[0]);
        for(int i = 1 ; i < 10 ; ++i) pf(" %d" , total2[i] - total1[i]);
        pf("\n");
    }
    return 0;
}
