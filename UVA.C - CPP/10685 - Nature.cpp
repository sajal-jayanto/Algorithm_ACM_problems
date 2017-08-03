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
#define MAXR            205
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
const double PI = 2.0 * acos(0.0);


///***************************************  END  **********************************************///

map < string  , int > mp;
int ar[5010] ;
int mark[5010];
int find_set(int r);

int main()
{
   // freopen("in.txt" , "r" , stdin);
    int n , m , x , y , mx;
    string temp , one , two;
    while(sf("%d %d" , &n , &m) && (n || m))
    {
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> temp;
            mp[temp] = i;
        }
        for(int i = 1 ; i <= n ; ++i) ar[i] = i , mark[i] = 1;
        for(int i = 0 ; i < m ; ++i)
        {
            cin >> one >> two;
            x = mp[one];
            y = mp[two];
            x = find_set(x);
            y = find_set(y);
            if(x != y)
            {
                ar[x] = y;
                mark[y] = mark[y] + mark[x];
            }
        }
        mx = 0;
        for(int i = 1 ; i <= n ; ++i) mx = max(mx , mark[i]);
        pf("%d\n" , mx);
        mp.clear();
    }
    return 0;
}

int find_set(int r)
{
    if(ar[r] == r) return r;
    return find_set(ar[r]);
}
