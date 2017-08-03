#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define PI (2 *  acos(0.0))
#define eps 1e-7
#define sf scanf
#define pf printf

using namespace std;

#define MAX 100010

struct node {

    int v ;
    long long w;
    node () {}
    node(int a , long long b) {v = a ; w = b; }
    bool operator < (const node &t) const {
        return t.w < w;
    }
};
int n , m , s , lim , cc = 0;
long long DP[(1 << 10) + 2][15];
int vis[(1 << 10) + 2][15];
vector < node > adj[100010];
int shop[20];
long long save[20][20];
long long cost[100010];

long long dijkstra(int a)
{
    for(int i = 0 ; i <= n ; ++i) cost[i] = 100000000000LL;
    cost[a] = 0;
    priority_queue < node > Q;
    Q.push(node(a , 0));
    while(!Q.empty())
    {
        node k = Q.top();
        Q.pop();
        if(cost[k.v] < k.w) continue ;
        int len = adj[k.v].size();
        for(int i = 0 ; i < len ; ++i)
        {
            node l = adj[k.v][i];
            if(cost[l.v] > cost[k.v] + l.w)
            {
                cost[l.v] = cost[k.v] + l.w;
                Q.push(l);
            }
        }
    }
}

long long call(int mark , int last)
{
   if(mark == lim) return save[last][0];
   long long &ret = DP[mark][last];
   if(vis[mark][last] == cc) return ret;
   ret = 100000000000LL;
    for(int i = 0 ; i < s ; ++i)
    {
        if((mark & (1 << i)) == 0) ret = min(ret , call( (mark | (1 << i)) , i + 1) + save[last][i + 1]);
    }
   vis[mark][last] = cc;
   return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int x , y ;
    long long temp ;
    int t;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &n , &m);
        while(m--)
        {
            sf("%d %d %lld", &x , &y , &temp);
            adj[x].push_back(node(y , temp));
            adj[y].push_back(node(x , temp));
        }
        memset(save , 0 , sizeof(save));
        sf("%d" , &s);
        lim = (1 << s) - 1;
        for(int i = 0 ; i < s ; ++i) sf("%d" , &shop[i]);
        dijkstra(0);
        for(int i = 1 ; i <= s ; ++i) save[i][0] = save[0][i] = cost[shop[i - 1]];
        for(int i = 1 ; i <= s ; ++i)
        {
            dijkstra(shop[i - 1]);
            for(int j = 1 ; j <= s ; ++j) save[i][j] = cost[shop[j - 1]];
        }
        if(t) for(int i = 0 ; i <= n ; ++i) adj[i].clear();
        ++cc;
        pf("%lld\n" , call(0 , 0));
    }
    return 0;
}
