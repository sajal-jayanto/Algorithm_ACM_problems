#define _CRT_SECURE_NO_WARNINGS
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

#define PI (2 *  acos(0.0))
#define eps 1e-7
#define sf scanf
#define pf printf
#define ab(a) (((a) > 0) ? (a) : -(a))

using namespace std;


int n , lim , cc = 0 , num[16][16] ;
long long DP[1 << 15][2][2];
int vis[1 << 15][2][2];

long long call(int mark , int mach , int supur)
{
    int pos = __builtin_popcount(mark);
    if( pos >= n)
    {
        if(mach || supur) return 1;
        return 0;
    }
    long long &ret = DP[mark][mach][supur];
    if(vis[mark][mach][supur] == cc) return ret;
    ret = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        if((mark & (1 << i)) == 0 )
        {
            int a = mach , b = supur;
            if(num[pos][i] != 1)  a = 0;
            if(num[pos][i] == 2)  b = 1;
            ret = ret + call((mark | (1 << i)) , a  , b);
        }
    }
    vis[mark][mach][supur] = cc;
    return ret;
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int t;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        lim = (1 << n) - 1;
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j) sf("%d" , &num[i][j]);
        }
        ++cc;
        pf("Case %d: %lld\n" , cc , call(0 , 1 , 0));
    }
    return 0;
}
