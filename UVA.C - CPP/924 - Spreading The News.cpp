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
#define MAX             110
#define MAXR            21
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}

///***************************************  END  **********************************************///

struct node {
    int d;
    int m;
};
node visit[2501];
vector < int > ve[2501];
void BFS(int temp);

int main()
{
    int t , n , temp;
    sf("%d" , &t);
    for(int i = 0 ; i < t ; ++i)
    {
        sf("%d", &n);
        while(n--)
        {
            sf("%d", &temp);
            ve[i].push_back(temp);
        }
    }
    sf("%d", &n);
    while(n--)
    {
        sf("%d", &temp);
        for(int i = 0  ; i < t ; ++i) visit[i].d = -1 , visit[i].m = 0;
        BFS(temp);
        int mx = 0 , ans = 0;
        for(int i = 0 ; i < t ; ++i)
        {
            if(mx < visit[i].m)
            {
                mx = visit[i].m;
                ans = i;
            }
        }
        if(!mx) pf("0\n");
        else pf("%d %d\n", mx , ans);
    }

    return 0;
}


void BFS(int temp)
{
    visit[temp].d = 0;
    queue < int > Q;
    Q.push(temp);
    while(!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        int len = ve[k].size();
        for(int i = 0 ; i < len ; ++i)
        {
            int l = ve[k][i];
            if(visit[l].d == -1)
            {
                visit[l].d = visit[k].d + 1;
                visit[visit[l].d].m++;
                Q.push(l);
            }
        }
    }
}
