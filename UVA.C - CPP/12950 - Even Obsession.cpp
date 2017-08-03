#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mx 1000000000

using namespace std;

struct node {

    int u , w , cnt ;
    node(){}
    node(int x , int y , int z) { u = x ; w = y ; cnt = z; }
    bool operator < (const node &t) const {
        return w < t.w;
    }
};

int cost[10100][5];
vector < node > ve[10100];


void dijkstra(int pos)
{
    cost[pos][0] = 0;
    priority_queue < node > Q;
    Q.push(node(pos , 0 , 0));
    while(!Q.empty())
    {
        node k = Q.top();
        Q.pop();
        if(cost[k.u][k.cnt] < k.w) continue;
        int len = ve[k.u].size();
        for(int i = 0 ; i < len ; ++i)
        {
            node l = ve[k.u][i];
            int id;
            if(k.cnt) id = 0;
            else id = 1;
            if(cost[l.u][id] > cost[k.u][k.cnt] + l.w)
            {
                cost[l.u][id] = cost[k.u][k.cnt] + l.w;
                Q.push(node(l.u , l.w , id));
            }
        }
    }
}


int main()
{
  //  freopen("input.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    int n , m , x , y , z;
    while(sf("%d %d" , &n , &m) != EOF)
    {
        for(int i = 0 ; i <= n + 2 ; ++i)
        {
            ve[i].clear();
            cost[i][0] = mx ;
            cost[i][1] = mx ;
        }
        for(int i = 0 ; i < m ; ++i)
        {
            sf("%d %d %d" , &x , &y , &z);
            ve[x].push_back(node(y , z , 0));
            ve[y].push_back(node(x , z , 0));
        }
        dijkstra(1);
        if(cost[n][0] == mx) pf("-1\n");
        else pf("%d\n" , cost[n][0]);
    }
    return 0;
}
