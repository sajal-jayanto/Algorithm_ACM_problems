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
#include <sstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 1010
#define MAXP 431
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;
struct node {
    int x ;
    int y;
};
node pos, ans , temp , tem;
char bord[MAX][MAX];
int cost[MAX][MAX];
int r , c;
void BFS();

int main()
{
  //  F_TO_R;
    int n, a, b , k;
    while(scanf("%d %d", &r , &c) && (r || c))
    {
        for(int i = 0 ; i < r ; ++i) for(int j = 0 ; j < c ; ++j) bord[i][j] = '.', cost[i][j] = -1;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d %d", &a , &b);
            while(b--)
            {
                scanf("%d", &k);
                bord[a][k] = '*';
            }
        }
        scanf("%d %d",&pos.x ,&pos.y);
        scanf("%d %d",&ans.x ,&ans.y);
        BFS();
     /*   for(int i = 0 ; i < r ; ++i)
        {
            for(int j = 0 ; j < c ; ++j) printf("%d ", cost[i][j]);
            printf("\n");
        }
        printf("%d %d %d %d", pos.x , pos.y , ans.x , ans.y);
    */
        printf("%d\n", cost[ans.x][ans.y]);
    }
    return 0;
}

void BFS()
{
    int one[] = {-1 , 1 , 0 , 0};
    int two[] = {0 , 0 , -1 , 1};
    cost[pos.x][pos.y] = 0;
    queue < node > Q;
    Q.push(pos);
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if(ans.x == temp.x && ans.y == temp.y) return ;
        for(int i = 0 ; i < 4 ; ++i)
        {
            tem.x = temp.x + one[i];
            tem.y = temp.y + two[i];
            if(tem.x >= 0 && tem.x < r && tem.y >= 0 && tem.y < c && bord[tem.x][tem.y] == '.' && cost[tem.x][tem.y] == -1)
            {
                cost[tem.x][tem.y] = cost[temp.x][temp.y] + 1;
                Q.push(tem);
            }
        }
    }
}
