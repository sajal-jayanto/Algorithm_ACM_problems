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
    long long num , sum, pos;
    int t;
    sf("%d", &t);
    while(t--)
    {
        sf("%lld", &num);
        num = Abs(num);
        for(long long i = 1 ; ; ++i)
        {
            sum = ((i + 1) * i) >> 1;
            if(sum >= num)
            {
                pos = i;
                break;
            }
        }
        sum = sum - num;
        while(sum % 2 != 0) sum = sum + (++pos);
        pf("%lld\n", pos);
        if(t) pf("\n");
    }
    return 0;
}
