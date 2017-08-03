#include<bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

int ans[45];
int n , mod = 1000007;
int dp[42][1 << 6][2][3][4][5][6];

int call(int pos , int mark , int a , int b , int c , int d , int e)
{
    if(pos >= n)
    {
        if((mark & (1 << 1)) && a) return 0;
        if((mark & (1 << 2)) && b) return 0;
        if((mark & (1 << 3)) && c) return 0;
        if((mark & (1 << 4)) && d) return 0;
        if((mark & (1 << 5)) && e) return 0;
        return 1;
    }
    int &ret = dp[pos][mark][a][b][c][d][e];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 1 ; i <= 6 ; ++i)
    {
        ret = ret + call(pos + 1 , mark | (1 << (i - 1))  , ((a * 10) + i) % 2 , ((b * 10) + i) % 3 , ((c * 10) + i) % 4 ,
        ((d * 10) + i) % 5 , ((e * 10) + i) % 6);
        ret = ret % mod;
    }
    return  ret;
}

int main()
{
    int t ;
    for(int i = 1 ; i <= 40 ; ++i)
    {
        memset(dp , -1 , sizeof(dp));
        n = i;
        ans[i] = call(0 , 0 , 0 , 0 , 0 , 0 , 0);
    }
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        pf("%d\n" , ans[n]);
    }
    return 0;
}
