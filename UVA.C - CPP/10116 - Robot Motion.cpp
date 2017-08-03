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

using namespace std;

int BFS(int,int);

int row, col, nod, n,m;
char grid[15][15];
int memo[15][15];
int cnt[15][15];
int cc;

int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d %d %d",&row,&col,&nod) && (row || col || nod))
    {
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                scanf(" %c",&grid[i][j]);
            }
        }
        memset(memo,-1,sizeof(memo));
        memset(cnt,-1,sizeof(cnt));
        cc = 0;
        if(BFS(0,--nod))
        {
            printf("%d step(s) before a loop of %d step(s)\n",++cnt[n][m],cc - cnt[n][m]);
        }
        else printf("%d step(s) to exit\n",++cc);
    }
    return 0;
}

int BFS(int i , int j)
{

    queue < int > Q;

    Q.push(i);
    Q.push(j);
    memo[i][j] = 0;

    while(!Q.empty())
    {
        n = Q.front();
        Q.pop();
        m = Q.front();
        Q.pop();

        if(grid[n][m] == 'N') --n;
        else if(grid[n][m] == 'S') ++n;
        else if(grid[n][m] == 'W') --m;
        else if(grid[n][m] == 'E') ++m;

        if((n >= 0 && n < row) && (m >= 0 && m < col))
        {
            if(memo[n][m] == -1)
            {
                memo[n][m] = 0;
                Q.push(n);
                Q.push(m);
                cc++;
                cnt[n][m] = cc - 1;
            }
            else return 1;
        }
        else  return 0;
    }
}
