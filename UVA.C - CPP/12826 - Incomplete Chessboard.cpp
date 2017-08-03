#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

int cost[10][10];
int one [] = {1 ,1 ,0,-1,-1,-1, 0, 1};
int two [] = {0 ,1 ,1 ,1, 0,-1,-1,-1};

 void bfs(int row , int col)
{
    int k , l , x , y;
    cost[row][col] = 0;
    queue < int > Q;
    Q.push(row);
    Q.push(col);
    while(!Q.empty())
    {
        k = Q.front();
        Q.pop();
        l = Q.front();
        Q.pop();
        for(int i = 0 ; i < 8 ; ++i)
        {
            x = k + one[i];
            y = l + two[i];
            if(x >= 1 && x < 9 && y >= 1 && y < 9 && cost[x][y] == -1)
            {
                Q.push(x);
                Q.push(y);
                cost[x][y] = cost[k][l] + 1;
            }
        }
    }
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
   // freopen("output.txt" , "w" , stdout);
    int a , b , c , d , e , f , cc = 0;
    while( sf("%d %d %d %d %d %d", &a, &b , &c, &d, &e, &f) == 6)
    {
        memset(cost , -1 , sizeof(cost));
        cost[e][f] = 0;
        bfs(a , b);
        pf("Case %d: %d\n" , ++cc, cost[c][d]);
    }
    return 0;
}
