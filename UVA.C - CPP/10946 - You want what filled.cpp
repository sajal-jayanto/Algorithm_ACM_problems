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
#define MAX 100

using namespace std;


int BFS(int,int,char);


struct node {
    char ch;
    int  cc;
}have[MAX * MAX];


char grid[MAX][MAX];
int visit[MAX][MAX];
int row,col;
int one[] = {-1,1,0,0};
int two[] = {0,0,-1,1};


bool comper(const node &a ,const node &b)
{
    if(a.cc < b.cc) return true;
    else if(a.cc == b.cc && a.ch > b.ch) return true;
    else return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    int k,x = 0;
    while(scanf("%d %d",&row,&col) && (row || col))
    {
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                scanf(" %c",&grid[i][j]);
            }
        }
        memset(visit , -1 , sizeof(visit));
        k = 0;
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if((visit[i][j] == -1) && (grid[i][j] != '.'))
                {
                    have[k].ch = grid[i][j];
                    have[k].cc = BFS(i,j,grid[i][j]);
                    k++;
                }
            }
        }
        sort(have, have + k,comper);
        printf("Problem %d:\n",++x);
        for(int i = k - 1 ; i >= 0  ; i--)
        {
            printf("%c %d\n",have[i].ch,have[i].cc);
        }
    }
   return 0;
}


int BFS(int i , int j , char c)
{
    int cnt = 0;
    queue < int > Q;
    Q.push(i);
    Q.push(j);

    while(!Q.empty())
    {

        int n = Q.front();
        Q.pop();
        int m = Q.front();
        Q.pop();

        for(int l = 0 ; l < 4 ; l++)
        {
            int o = n + one[l];
            int p = m + two[l];

            if((o >= 0 && o < row) && (p >= 0 && p < col)  && (visit[o][p] == -1) && (grid[o][p] == c))
            {
                visit[o][p] = 0;
                Q.push(o);
                Q.push(p);
                cnt++;
            }
        }
    }
    if(cnt == 0) return 1;
    return cnt;
}

