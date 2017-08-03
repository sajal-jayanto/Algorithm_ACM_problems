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

template < class T > inline T gcd(T a,T b) { if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}
template < class T > inline T lcm(T a,T b) { if(a < 0) return lcm(-a,b); if(b < 0)return lcm(a,-b); return a * (b / gcd(a , b));}

vector < long long > ve;

int main()
{
    int t , n ,cc = 0;
    long long temp , ans , one;
    sf("%d" , &t);
    while(t--)
    {
        ans = 0;
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%lld" , &temp);
            ve.push_back(temp);
        }
        temp = ve[0];
        for(int i = 0 ; i < ve.size() ; ++i) temp = lcm(temp , ve[i]);
        for(int i = 0 ; i < ve.size() ; ++i) ans = ans + (temp / ve[i]);
        temp = (long long) temp * n;
        one = gcd(temp , ans);
        pf("Case %d: %lld/%lld\n" , ++cc , temp / one , ans / one);
        ve.clear();
    }
    return 0;
}
