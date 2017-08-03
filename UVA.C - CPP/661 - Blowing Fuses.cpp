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
#define MAX             100010
#define MAXR            170
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;


///***************************************  END  **********************************************///

struct node{
    int a , b;
    node(int x , int y ) {a = x ; b = y ;}
};

vector < node > ve;

int main()
{
    int n , m , c , now , temp , mx , cc = 0;
    while( sf("%d %d %d" , &n , &m , &c) && (n || m || c))
    {
        now = 0;
        mx = 0;
        ve.push_back(node(0 , 0));
        while(n--)
        {
            sf("%d" , &temp);
            ve.push_back(node(temp , 0));
        }
        while(m--)
        {
            sf("%d" , &temp);
            if(mx != -1)
            {
                if(!ve[temp].b) now = now + ve[temp].a , ve[temp].b = 1;
                else now = now - ve[temp].a , ve[temp].b = 0;
                mx = max(mx , now);
                if(now > c) mx = -1;
            }
        }
        if(mx != -1) pf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n" , ++cc , mx);
        else pf("Sequence %d\nFuse was blown.\n\n" , ++cc );
        ve.clear();
    }
    return 0;
}
