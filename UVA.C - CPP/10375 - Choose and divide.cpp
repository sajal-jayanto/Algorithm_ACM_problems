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
#define MAX             10100
#define MAXR            305
#define MAXC            305
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > T Abs(T x) { return x > 0 ? x : -x;}

int main()
{
    int a , b , c , d;
    double ans;
    while(sf("%d %d %d %d",&a ,&b , &c, &d) == 4)
    {
        ans = 1.0;
        if(a - b < b) b = a - b;
        if(c - d < d) d = c - d;
        for(int i = 1; i <= b || i <= d; i++)
        {
            if(i <= b) ans = ans * (a - b + i) / i;
            if(i <= d) ans = ans / (c - d + i) * i;
        }
        pf("%.5lf\n",ans);
    }
    return 0;
}
