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
#define INF             (1<<25)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             1001
#define MAXR            205
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

void MST(int n );
int find_set(int r);

struct eage{

    int u , v;
    long long w;
    bool operator < (const eage& t) const { return w < t.w; }
};

vector < eage > ve;
bool ans[MAX];
int dis_set[MAX];

int main()
{
    int a , b, x, y;
    long long z;
    eage temp;
    bool flag ;
    while ( scanf("%d %d", &a , &b) && (a || b) )
    {
        flag = false;
        mem(ans , false);
        for(int i = 0 ; i < b ; ++i)
        {
            scanf("%d %d %lld", &x , &y , &z);
            temp.u = x;
            temp.v = y;
            temp.w = z;
            ve.push_back(temp);
        }
        MST(a);
        for(int i = 0 ; i < b ; ++i)
        {
            if(!ans[i] && flag) pf(" %lld",ve[i].w);
            else if(!ans[i] && !flag){ pf("%lld", ve[i].w);  flag = true; }
        }
        if(!flag) pf("forest");
        pf("\n");
        ve.clear();
    }
    return 0;
}


void MST(int n )
{
    for(int i = 0 ; i < n ; ++i) dis_set[i] = i ;
    sort(ve.begin() , ve.end());
    int get = 0;
    int len = ve.size();
    for(int i = 0 ; i < len ; ++i)
    {
        int x = find_set(ve[i].u);
        int y = find_set(ve[i].v);
        if(x != y)
        {
            ans[i] = true;
            ++get;
            dis_set[x] = y;
            if(get == n - 1) i = len;
        }
    }
}

int find_set(int r)
{
    if(dis_set[r] == r) return r;
    return find_set(dis_set[r]);
}
