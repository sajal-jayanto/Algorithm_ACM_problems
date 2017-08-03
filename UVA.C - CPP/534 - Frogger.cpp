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


double DP[205][205];
int a[205];
int b[205];



int main()
{
    int t , cc = 0;
    while(sf("%d" , &t) && t)
    {
        for(int i = 0 ; i < t ; ++i) sf("%d %d", &a[i] , &b[i]);
        for(int i = 0 ; i < t ; ++i)
        {
            for(int j = 0 ; j < 205 ; ++j)
            {
                if(i == j) DP[i][j] = (double) INF;
                else DP[i][j] = sqrt(pow(a[i] - a[j] , 2) + pow(b[i] - b[j] , 2));
            }
        }
        for(int k = 0 ; k < t ; ++k) for(int i = 0 ; i < t ; ++i) for(int j = 0 ; j < t ; ++j)
        {
            DP[i][j] = min( DP[i][j], max(DP[i][k], DP[k][j]) );
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n" , ++cc , DP[0][1]);
    }
    return 0;
}
