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
#define MAX 105


using namespace std;

void BFS(int,int);

char grid[MAX][MAX];
int visit[MAX][MAX];

int a,b;
int cnt;

int one[] = {-1,-1,0,1,1,1,0,-1};
int two[] = {0,1,1,1,0,-1,-1,-1};


int main()
{
    //freopen("input.txt","r",stdin);

    while(scanf("%d %d",&a,&b) && (a || b))
    {
        for(int i = 0 ; i < a ; i++)
        {
            for(int j = 0 ; j < b ; j++)
            {
                scanf(" %c",&grid[i][j]);
            }
        }
        memset(visit , -1 , sizeof(visit));
        cnt = 0;
        for(int i = 0 ; i < a ; i++)
        {
            for(int j = 0 ; j < b ; j++)
            {
                if(grid[i][j] == '@' && visit[i][j] == -1)
                {
                    BFS(i,j);
                    cnt++;
                }
            }
        }
    printf("%d\n",cnt);
    }
    return 0;
}


void BFS(int i , int j)
{
    queue < int > Q;

    Q.push(i);
    Q.push(j);

    while(!Q.empty())
    {

        int n = Q.front();
        Q.pop();
        int m = Q.front();
        Q.pop();


        for(int i = 0 ; i < 8 ; i++)
        {
            int o = n + one[i];
            int p = m + two[i];

            if((o >= 0 && o < a) && (p >= 0 && p < b) && (grid[o][p] == '@') && (visit[o][p] == -1))
            {

                visit[o][p] = 0;
                Q.push(o);
                Q.push(p);
            }
        }
    }
}

