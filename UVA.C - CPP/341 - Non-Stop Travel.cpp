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
#define MAX             110
#define MAXR            21
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}

///***************************************  END  **********************************************///

int DP[MAX][MAX];
int path[MAX][MAX];
void print(int a , int b);

int main()
{
    int t , n , a, b , ans , cc = 0;
   // freopen("input.txt" , "r" , stdin);
    while(sf("%d" , &t) && t)
    {
        for(int i = 1 ; i <= t ; ++i) for(int j = 1 ; j <= t ; ++j)
        {
            if(i == j) DP[i][j] = 0;
            else DP[i][j] = INF;
            path[i][j] = i;
        }
        for(int i = 1 ; i <= t ; ++i)
        {
            sf("%d" , &n);
            while(n--)
            {
                sf("%d %d" , &a , &b);
                DP[i][a] = b;
            }
        }
        for(int k = 1 ; k <= t ; ++k) for(int i = 1 ; i <= t ; ++i) for(int j = 1 ; j <= t ; ++j)
        {
            if(DP[i][k] + DP[k][j] < DP[i][j]) DP[i][j] = DP[i][k] + DP[k][j] , path[i][j] = path[k][j];
        }
        sf("%d %d" , &a , &b);
        ans = DP[a][b];
        pf("Case %d: Path =",  ++cc);
        print(a , b);
        pf("; %d second delay\n" , ans);
    }
    return 0;
}


void print(int a , int b)
{
    if(a != b) print(a , path[a][b]);
    printf(" %d" , b);
}
