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

vector < int > ve;

int main()
{
    int t , temp;
    while(sf("%d", &t) && t)
    {
        for(int i = 0 ; i < t ; ++i)
        {
            sf("%d", &temp);
            if(temp) ve.push_back(temp);
        }
        temp = ve.size();
        if(!temp) pf("0\n");
        else
        {
            pf("%d", ve[0]);
            for(int i = 1 ; i < temp ; ++i) pf(" %d", ve[i]);
            pf("\n");
            ve.clear();
        }
    }
    return 0;
}
