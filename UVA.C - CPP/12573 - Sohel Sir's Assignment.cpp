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
#define INF             (1<<28)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             1000000000000000ll
#define MAXR            1000005
#define MAXC            11


int main()
{
    //freopen("tem.txt" , "r" , stdin);
    long long a , b , x , y , temp , k , ans;
    int t;
    sf("%d" , &t);
    while(t--)
    {
        sf("%lld %lld" , &a , &b);
        if(b == 2)
        {
            pf("1\n");
            continue ;
        }
        temp = a - (b - 2);
        if(temp <= 0)
        {
            if(a + 2 != b) pf("Impossible\n");
            else pf("%lld\n" , a + 1);
            continue ;
        }
        ans = MAX;
        k = sqrt(temp);
        for(long long i = 1 ; i <= k ; ++i)
        {
            if(temp % i == 0)
            {
                x = (a % i) + 2;
                if(x == b) ans = min(ans , i);
                x = (temp / i);
                y = (a % x) + 2;
                if(y == b) ans = min(ans , x);
            }
        }
        if(ans == MAX) pf("Impossible\n");
        else pf("%lld\n" , ans);
    }
    return 0;
}
