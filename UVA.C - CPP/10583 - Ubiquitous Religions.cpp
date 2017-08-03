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
#define MAX             100010
#define MAXR            2141
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
int ar[MAX];
int find_path(int r);

int main()
{
    int n , m , a , b , ans , cc = 0;
    while( sf("%d %d", &n , &m) && (n || m))
    {
        for(int i = 1 ; i <= n ; ++i) ar[i] = i;
        while(m--)
        {
            sf("%d %d" , &a , &b);
            int x = find_path(a);
            int y = find_path(b);
            if(x != y) ar[x] = y;
        }
        ans = 0;
        for(int i = 1 ; i <= n ; ++i) if(ar[i] == i) ++ans;
        pf("Case %d: %d\n" , ++cc  , ans);
    }
    return 0;
}

int find_path(int r)
{
    if(ar[r] == r) return r;
    return find_path(ar[r]);
}
