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

long long DP[22];
long long DP1[22][22];
long long der(long long n);
long long NcR(long long n ,long long r);
int main()
{
    long long a , b , ans;
    mem(DP , -1);
    mem(DP1 , -1);
    while(scanf("%lld %lld", &a , &b) == 2)
    {
        ans = 0;
        for(int i = 0 ; i <= b ; ++i)
        {
            ans = ans + NcR(a , i) * der(a - i);
        }
        pf("%lld\n" , ans);
    }
    return 0;
}

long long der(long long n)
{
    if(n == 0 || n == 2) return 1;
    if(n == 1) return 0;
    long long &ret = DP[n];
    if(ret != -1) return ret;
    return ret = (n - 1) * (der(n - 1) + der(n - 2));
}


long long NcR(long long n ,long long r)
{
    if(r == 0) return 1;
    if(n == 0) return 0;
    long long &ret = DP1[n][r];
    if(ret != -1) return ret;
    return ret = NcR(n - 1 , r) + NcR(n - 1 , r - 1);
}
