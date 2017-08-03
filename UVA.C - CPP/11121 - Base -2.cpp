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

vector < char > ve;

int main()
{
    int t , cc = 0;
    long long num, base;
    sf("%d", &t);
    while(t--)
    {
        base = -2;
        sf("%lld", &num);
        while(num)
        {
            if(num % base)
            {
                ve.push_back('1');
                num = num - base / (-2);
            }
            else ve.push_back('0');
            base = base * -2;
        }
        pf("Case #%d: ", ++cc);
        int len = ve.size();
        if(!len) pf("0");
        else for(int i = len - 1 ; i >= 0 ; --i) pf("%c", ve[i]);
        pf("\n");
        ve.clear();
    }
    return 0;
}
