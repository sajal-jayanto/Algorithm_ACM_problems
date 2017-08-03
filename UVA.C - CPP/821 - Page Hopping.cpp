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

using namespace std;

#define F_TO_R          freopen("input.txt", "r" , stdin)
#define _pair(x,y)      make_pair(x,y)
#define INF             (1<<20)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             1010
#define MAXR            21
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}

///***************************************  END  **********************************************///

int DP[105][105];

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int a , b , ans , n , cc = 0;
    while(sf("%d %d" , &a , &b) && (a || b))
    {
        for(int i = 1 ; i <= 100 ; ++i) for(int j = 1 ; j <= 100 ; ++j)
        {
            if(i == j) DP[i][j] = 0;
            else DP[i][j] = INF;
        }
        n = 0;
        DP[a][b] = 1;
        while(sf("%d %d" , &a , &b) && (a || b)) DP[a][b] = 1;
        for(int k = 1 ; k <= 100 ; ++k) for(int i = 1 ; i <= 100 ; ++i) for(int j = 1 ; j <= 100 ; ++j)
        {
            if( DP[i][k] + DP[k][j] < DP[i][j] ) DP[i][j] = DP[i][k] + DP[k][j];
        }
        ans = 0;
        for(int i = 1 ; i <= 100 ; ++i)
        {
            for(int j = 1 ; j <= 100 ; ++j) if(DP[i][j] != INF && i != j) ans = ans + DP[i][j] , ++n;
        }
        pf("Case %d: average length between pages = %.03lf clicks\n" , ++cc , (double) ans / n);
    }
    return 0;
}
