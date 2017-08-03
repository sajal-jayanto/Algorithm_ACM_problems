#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

int bigmod ( int a, int p, int mod )
{
    int res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}

int n , b , cc = 0;
long long DP[65][65][100];
int vis[65][65][100];

long long call(int one , int zero , int rem )
{
    int pos = (one + zero);
    if( pos >= n )
    {
        if((one == zero) && !rem ) return 1;
        return 0;
    }
    long long &ret = DP[one][zero][rem];
    if(vis[one][zero][rem] == cc) return ret;
    ret = 0;
    ret = ret + call(one + 1 , zero , (rem +  bigmod(2 , pos - 1 , b)) % b );
    ret = ret + call(one , zero + 1 , rem % b );
    vis[one][zero][rem] = cc;
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &n , &b);
        ++cc;
		 if(n % 2 == 1 || !b) pf("Case %d: 0\n" , cc);
        pf("Case %d: %lld\n" , cc , call(1 , 0 , bigmod(2 , n - 1 , b)) );
    }
    return 0;
}
