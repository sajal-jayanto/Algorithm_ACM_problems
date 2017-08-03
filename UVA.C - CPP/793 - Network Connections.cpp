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


int ve[100010];

int find_set(int r)
{
    if(ve[r] == r) return r;
    return find_set(ve[r]);
}

int main()
{
  //  freopen("in.txt" , "r" , stdin);
    int t , n , a, b , x, y , one , two ;
    char ch, str[10000];;
    sf("%d", &t);
    while(t--)
    {
        one = 0 ;
        two = 0 ;
        sf("%d", &n);
        getchar();
        for(int i = 1 ; i <= n ; ++i) ve[i] = i;
        while(gets(str))
        {
            if(str[0] == '\0') break;
            sscanf(str , "%c %d %d", &ch , &a , &b);
            if(ch == 'c')
            {
                x = find_set(a);
                y = find_set(b);
                if(x != y) ve[x] = y;
            }
            else if(ch == 'q')
            {
                x = find_set(a);
                y = find_set(b);
                if(x == y) ++one;
                else ++two;
            }
        }
        pf("%d,%d\n", one , two);
        if(t) pf("\n");
    }
    return 0;
}
