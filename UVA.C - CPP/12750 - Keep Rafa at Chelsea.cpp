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
#define MAX             10010
#define MAXR            17
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
const double PI = 2.0 * acos(0.0);


vector < char > ve;

int main()
{
    int t , n , cnt , ans , cc = 0;
    char ch;
    sf("%d", &t);
    while(t--)
    {
        sf("%d", &n);
        for(int i = 0 ; i < n ; ++i)
        {
            sf(" %c", &ch);
            ve.push_back(ch);
        }
        cnt = 0;
        ans = -1;
        for(int i = 0 ; i < n ; ++i)
        {
            if(ve[i] == 'W') cnt = 0;
            else ++cnt;
            if(cnt == 3)
            {
                ans = i + 1;
                break;
            }
        }
        if(ans != -1) pf("Case %d: %d\n" , ++cc , ans);
        else pf("Case %d: Yay! Mighty Rafa persists!\n" , ++cc);
        ve.clear();
    }
    return 0;
}
