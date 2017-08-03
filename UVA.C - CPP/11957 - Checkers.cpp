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

char str[105][105];
int dp[105][105];
int vis[105][105];
int n , cc = 0 , mod = 1000007;

int call(int r , int c)
{
    if(r <= 0) return 1;
    int &ret = dp[r][c];
    if(vis[r][c] == cc) return ret;
    ret = 0;
    if(c - 1 < n && str[r - 1 ][c - 1] == '.') ret = ret + call(r - 1 , c - 1);
    else if(c - 2 < n && str[r - 2][c - 2] == '.') ret = ret + call(r - 2 , c - 2);
    ret = ret % mod;
    if(c + 1 < n && str[r - 1][c + 1] == '.') ret = ret + call(r - 1 , c + 1);
    else if(c + 2 < n && str[r - 2][c + 2] == '.') ret = ret + call(r - 2 , c + 2);
    ret = ret % mod;
    vis[r][c] = cc;
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , x , y;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                sf(" %c" , &str[i][j]);
                if(str[i][j] == 'W') { x = i , y = j; }
            }
        }
        ++cc;
        pf("Case %d: %d\n" , cc, call(x , y));
    }
    return 0;
}
