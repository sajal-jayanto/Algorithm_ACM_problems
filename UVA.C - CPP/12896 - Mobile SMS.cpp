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

struct node {
    int a ;
    int b ;
};
char fin(int a , int b);
node ve[105];
int main()
{
    int t , n;
    sf("%d", &t);
    while(t--)
    {
        sf("%d", &n);
        for(int i = 0 ; i < n ; ++i) sf("%d", &ve[i].a);
        for(int i = 0 ; i < n ; ++i) sf("%d", &ve[i].b);
        for(int i = 0 ; i < n ; ++i) pf("%c", fin(ve[i].a , ve[i].b));
        pf("\n");
    }
    return 0;
}


char fin(int a , int b)
{

    if(a == 1)
    {
        if(b == 1) return '.';
        if(b == 2) return ',';
        if(b == 3) return '?';
        if(b == 4) return '"';
    }
    else if(a == 2)
    {
        if(b == 1) return 'a';
        if(b == 2) return 'b';
        if(b == 3) return 'c';
    }
    else if(a == 3)
    {
        if(b == 1) return 'd';
        if(b == 2) return 'e';
        if(b == 3) return 'f';
    }
    else if(a == 4)
    {
        if(b == 1) return 'g';
        if(b == 2) return 'h';
        if(b == 3) return 'i';
    }
    else if(a == 5)
    {
        if(b == 1) return 'j';
        if(b == 2) return 'k';
        if(b == 3) return 'l';
    }
    else if(a == 6)
    {
        if(b == 1) return 'm';
        if(b == 2) return 'n';
        if(b == 3) return 'o';
    }
    else if(a == 7)
    {
        if(b == 1) return 'p';
        if(b == 2) return 'q';
        if(b == 3) return 'r';
        if(b == 4) return 's';
    }
    else if(a == 8)
    {
        if(b == 1) return 't';
        if(b == 2) return 'u';
        if(b == 3) return 'v';
    }
    else if(a == 9)
    {
        if(b == 1) return 'w';
        if(b == 2) return 'x';
        if(b == 3) return 'y';
        if(b == 4) return 'z';
    }
    else if(a == 0)
    {
        if(b == 1) return ' ';
    }
}
