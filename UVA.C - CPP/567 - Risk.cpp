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
#define MAX 25
#define MAXP 2147483640
#define fileR freopen("input.txt", "r" , stdin)
#define fileW freopen("output.txt", "w" , stdout)

using namespace std;
int BFS(int a , int b);

vector < vector < int > > bord(MAX);
vector < int > visit(MAX);


int main()
{
    //fileR;
    int num, n, a, b, cc = 0;
    int cnt = 1;
    while(scanf("%d", &num) == 1)
    {
        for(int i = 0 ; i < num ; i++)
        {
            scanf("%d" ,&n);
            bord[cnt].push_back(n);
            bord[n].push_back(cnt);
        }
        if(cnt == 19)
        {
            printf("Test Set #%d\n", ++cc);
            scanf("%d", &n);
            while(n--)
            {
                for(int i = 0 ; i < MAX ; i++) visit[i] = -1;
                scanf("%d %d", &a , &b);
                printf("%2d to %2d: %d\n", a , b , BFS(a , b));
            }
            cnt = 1;
            for(int i = 0 ; i < MAX ; i++) bord[i].clear();
            printf("\n");
        }
        else cnt++;
    }
    return 0;
}


int BFS(int a , int b)
{
    queue < int > Q;
    visit[a] = 0;
    Q.push(a);
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        if(x == b) return visit[x];
        int len = bord[x].size();
        for(int i = 0 ; i < len ; i++)
        {
            int y = bord[x][i];
            if(visit[y] == -1)
            {
                visit[y] = visit[x] + 1;
                Q.push(y);
            }
        }
    }
    return -1;
}
