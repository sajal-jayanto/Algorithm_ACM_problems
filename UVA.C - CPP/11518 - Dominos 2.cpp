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
#define MAX             10010
#define MAXR            305
#define MAXC            305
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}
int one[] = {-1 , 1 , 0 , 0};
int two[] = { 0 , 0 ,-1 , 1};

///***************************************  END  **********************************************///

vector < int > ve[MAX];
bool vis[MAX];
int BFS(int temp);

int main()
{
    //freopen("input.txt" , "r" ,  stdin);
    int t , n , m , l , a, b, ans ;
    sf("%d" , &t);
    while(t--)
    {
        ans = 0;
        sf("%d %d %d", &n , &m , &l);
        for(int i = 0 ; i < m ; ++i)
        {
            sf("%d %d", &a , &b);
            ve[a].push_back(b);
        }
        while(l--)
        {
            sf("%d", &a);
            if(!vis[a]) ans = ans + BFS(a);
        }
        pf("%d\n", ans);
        for(int i = 0 ; i <= n + 2 ; ++i) ve[i].clear() , vis[i] = false;
    }
    return 0;
}



int BFS(int temp)
{
    int cnt = 0;
    vis[temp] = true;
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
            if(!vis[l])
            {
                vis[l] = true;
                ++cnt;
                Q.push(l);
            }
        }
    }
    return ++cnt;
}
