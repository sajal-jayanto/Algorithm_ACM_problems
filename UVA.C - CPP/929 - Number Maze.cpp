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
#define MAX 1002
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;
struct node {
    int a;
    int b;
    int w;
    bool operator < (const node &x) const
    {
        if(w < x.w) return false;
        return true;
    }
};
node pos,an;
void Dijkstra(int a , int b , int r , int c);
int bord[MAX][MAX];
int cost[MAX][MAX];
bool visit[MAX][MAX];

int main()
{
    int t, r, c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &r, &c);
        for(int i = 1 ; i <= r ; ++i) for(int j = 1 ; j <= c ; ++j)
        {
            scanf("%d", &bord[i][j]);
            cost[i][j] = 1 << 30;
            visit[i][j] = false;
        }
        Dijkstra(1 , 1, r , c);
        printf("%d\n", cost[r][c]);
    }
    return 0;
}

void Dijkstra(int i , int j , int r , int c)
{
    int one[] = {-1 , 1 , 0 , 0};
    int two[] = {0 , 0 , -1 , 1};
    cost[i][j] = bord[i][j];
    pos.w = 0;
    pos.a = 1;
    pos.b = 1;
    priority_queue < node > Q;
    Q.push(pos);
    while(!Q.empty())
    {
        pos = Q.top();
        Q.pop();
        visit[pos.a][pos.b] = true;
        for(int i = 0 ;i < 4 ; ++i)
        {
            int k = pos.a + one[i];
            int l = pos.b + two[i];
            if((k >= 1 && k <= r) && (l >= 1 && l <= c) && !visit[k][l])
            {
                int p = cost[pos.a][pos.b] + bord[k][l];
                if(p < cost[k][l])
                {
                    cost[k][l] = p;
                    an.a = k;
                    an.b = l;
                    an.w = p;
                    Q.push(an);
                }
            }
        }
    }
}
