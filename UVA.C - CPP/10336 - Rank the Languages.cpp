#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>


#define pi ( 2* acos( 0.0))
#define eps 1e-7
#define MAX 30

using namespace std;

void BFS(int,int,char);

char grid[MAX][MAX];
int visit[MAX][MAX];
int abc[26];
int one[] = {-1,1,0,0};
int two[] = {0,0,-1,1};
int h,w;

int main()
{
   // freopen("input.txt","r",stdin);
    int t;
    int m,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        memset(abc , 0 , sizeof(abc));
        memset(visit , -1 , sizeof(visit));
        scanf("%d %d",&h,&w);
        for(int i = 0 ; i < h ; i++)
        {
            for(int j = 0 ; j < w ; j++)
            {
                scanf(" %c",&grid[i][j]);
            }
        }
        m = 0;
        for(int i = 0 ; i < h ; i++)
        {
            for(int j = 0 ; j < w ; j++)
            {
                if(visit[i][j] == -1)
                {
                    int c = grid[i][j] - 'a';
                    abc[c]++;
                    if(m < abc[c]) m = abc[c];
                    BFS(i,j,grid[i][j]);
                }
            }
        }
        printf("World #%d\n",++cnt);
        for(int i = m ; i > 0 ; i--)
        {
            for(int j = 0 ; j < 26 ; j++)
            {
                if(abc[j] == i)
                {
                    printf("%c: %d\n",j + 97 , i);
                }
            }
        }
    }
    return 0;
}

void BFS(int i , int j ,char ch)
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

        for(int k = 0 ; k < 4 ; k++)
        {
            int o = n + one[k];
            int p = m + two[k];

            if((o >= 0 && o < h) && (p >= 0 && p < w) && (visit[o][p] == -1) && (grid[o][p] == ch))
            {
                visit[o][p] = 0;
                Q.push(o);
                Q.push(p);
            }
        }
    }
}
