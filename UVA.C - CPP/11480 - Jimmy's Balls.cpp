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
#define INF             (1<<30)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             105
#define MAXR            9598
#define MAXC            10000LL
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

int main()
{
    int t , one , two , cc = 0;
    long long ans ;
    while(sf("%d" , &t) && t)
    {
        ans = 0;
        for(int i = 1 ;  ; ++i)
        {
            one = i + 1;
            two = t - (one + i);
            if(two > one) ans = ans + (long long) (t - 3 * i - 1) / 2;
            else break;
        }
        pf("Case %d: %lld\n" , ++cc , ans);
    }
    return 0;
}
