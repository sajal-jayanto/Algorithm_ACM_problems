#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 1010
#define MAXP 2147483640
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;

map < int ,vector < int > > mymap;
int visit[MAX];
void BFS();

int main()
{
   // F_TO_R;
    int t, a , b, node, cnt;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &node , &cnt);
        while(cnt--)
        {
            scanf("%d %d", &a , &b);
            mymap[a].push_back(b);
            mymap[b].push_back(a);
        }
        BFS();
        for(int i = 1 ; i < node ; i++) printf("%d\n", visit[i]);
        mymap.clear();
        if(t) printf("\n");
    }

    return 0;
}



void BFS()
{
    memset(visit , -1 , sizeof(visit));
    queue < int > Q;
    visit[0] = 0;
    Q.push(0);
    while(!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        int len = mymap[k].size();
        for(int i = 0 ; i < len ; i++)
        {
            int l = mymap[k][i];
            if(visit[l] == -1)
            {
                visit[l] = visit[k] + 1;
                Q.push(l);
            }
        }
    }
}
