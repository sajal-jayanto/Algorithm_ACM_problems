#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
void BFS(int a,map < int , vector < int > > mymap);

map < int , int > memo;

int main()
{
    freopen("input.txt","r",stdin);
    int t,n,a,b,cc = 0;
    while(scanf("%d",&t) && t)
    {
        map < int , vector < int > > mymap;
        while(t--)
        {
            scanf("%d %d",&a,&b);
            mymap[a].push_back(b);
            mymap[b].push_back(a);
        }
        while(scanf("%d %d",&a,&b) && (a || b))
        {
            BFS(a,mymap);
            int cnt = 0;
            for(map < int , int >::iterator it = memo.begin() ; it != memo.end() ; it++)
            {
                if(it->second > b) cnt++;
            }
            cnt = cnt + mymap.size() - memo.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cc , cnt ,a , b);
        }
    }
    return 0;
}


void BFS(int a ,map < int , vector < int > > mymap)
{
    memo.clear();
    queue < int > Q;
    Q.push(a);
    memo[a] = 0;
    while(!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        int len = mymap[t].size();
        for(int i = 0 ; i < len ; i++)
        {
            int n = mymap[t][i];
            if(!memo.count(n))
            {
                memo[n] = memo[t] + 1;
                Q.push(n);
            }
        }
    }
}
