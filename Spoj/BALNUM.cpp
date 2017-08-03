#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>


#define sf scanf
#define pf printf

using namespace std;

int num[22] ;
long long dp[22][2][1024][1024];
bool vis[22][2][1024][1024];

int flip(int mark , int pos)
{
    if((mark & (1 << pos)) == 0) return (mark | (1 << pos));
    return (mark & ~(1 << pos));
}

bool ok(int rmask , int mask)
{
    for(int i = 0 ; i < 10 ; ++i)
    {
        if((rmask & (1 << i)) != 0)
        {
            if(i & 1)
            {
                if((mask & (1 << i)) != 0) return false;
            }
            else
            {
                if((mask & (1 << i)) == 0) return false;
            }
        }
    }
    return true;
}

long long call(int pos , int can , int rmask , int mask , int flag)
{
    if(pos == 0) return ok(rmask , mask);
    int n = flag ? num[pos] : 9;
    if(!flag && vis[pos][can][rmask][mask]) return dp[pos][can][rmask][mask];
    long long ans = 0;
    for(int i = 0 ; i <= n ; ++i)
    {
        if((can && i) || !can) ans = ans + call(pos - 1 , 0 , rmask | (1 << i) , flip(mask , i) , flag && (i == n));
        else ans = ans + call(pos - 1 , can , rmask , mask  , flag && (i == n));
    }
    if(!flag)
    {
        vis[pos][can][rmask][mask] = true;
        dp[pos][can][rmask][mask] = ans;
    }
    return ans;
}

long long pro(long long n)
{
    if(n <= 0) return 0;
    int len = 0;
    while(n)
    {
        num[++len] = n % 10;
        n = n / 10;
    }
    return call(len , 1 , 0 , 0 , 1 ) - 1;
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int t ;
    long long a , b ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%lld %lld" , &a , &b);
        pf("%lld\n" , pro(b) - pro(a - 1));
    }
    return 0;
}
