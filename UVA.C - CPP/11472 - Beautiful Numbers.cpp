#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

int n , m , lim , cc = 0;
int DP[102][(1 << 10) + 2][10][2];
int vis[102][(1 << 10) + 2][10][2];
int mod = 1000000007;

int call(int len , int mark , int last , int flag)
{
    if(len >= m)
    {
        if(mark == lim) return 1;
        return 0;
    }
    int &ret = DP[len][mark][last][flag];
    if(vis[len][mark][last][flag] == cc) return ret;
    int f , temp ;
    ret = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(flag && !i )
        {
            f = 1;
            temp = mark;
        }
        else
        {
            f = 0;
            temp = (mark | (1 << i));
        }
        if(flag || f)
        {
            ret = ret + call(len + 1 , temp , i , f) ;
            ret = ret % mod;
        }
        else if(abs(last - i) == 1)
        {
            ret = ret + call(len + 1 , temp , i , f);
            ret = ret % mod;
        }
    }
    vis[len][mark][last][flag] = cc;
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &n , &m);
        lim = ( 1 << n ) - 1;
        ++cc;
        pf("%d\n", call(0 , 0 , 0 , 1));
    }
    return 0;
}
