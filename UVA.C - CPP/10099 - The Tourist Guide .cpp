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
#define INF             (1<<25)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             1010
#define MAXR            205
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

int ve[105][105];

int main()
{
    int n , m , a , b , c , mx , cc = 0;
    while ( sf("%d %d" , &n , &m) && ( n || m))
    {
        mem(ve , 0);
        while(m--)
        {
            sf("%d %d %d" , &a , &b , &c);
            ve[a][b] = c;
            ve[b][a] = c;
        }
        for(int i = 1 ; i <= 102 ; ++i) ve[i][i] = 0;
        for(int k = 1 ; k <= n ; ++k) for(int i = 1 ; i <= n ; ++i)  for(int j = 1 ; j <= n ; ++j)
        ve[i][j] = max(ve[i][j] , min(ve[i][k] , ve[k][j]));
        sf("%d %d %d", &a , &b ,  &c);
        if(a != b)
        {
            --ve[a][b];
            mx = (c / ve[a][b]);
            if(c % ve[a][b]) ++mx;
        }
        else mx = 1;
        pf("Scenario #%d\nMinimum Number of Trips = %d\n\n" , ++cc ,  mx);
    }
    return 0;
}

