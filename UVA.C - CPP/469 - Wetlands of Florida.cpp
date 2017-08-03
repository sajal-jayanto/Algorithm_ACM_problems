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

void BFS(int,int);

char grid[MAX][MAX];
int visit[MAX][MAX];
int cnt, k ;

int one[] = {-1,-1,0,1,1,1,0,-1};
int two[] = {0,1,1,1,0,-1,-1,-1};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,a,b;
    char str[MAX];
    scanf("%d",&t);
    gets(str);
    gets(str);
    while(t--)
    {
        k = 0;
        while(gets(str))
        {
            if(str[0] == '\0') break;
            if(str[0] == 'W' || str[0] == 'L') sscanf(str,"%s",grid[k++]);
            else
            {
                memset(visit, -1 , sizeof(visit));
                sscanf(str,"%d %d",&a,&b);
                if(grid[a - 1][b - 1] == 'W')
                {
                    cnt = 0;
                    BFS(a - 1,b - 1);
                    if(cnt == 0) cnt++;
                    printf("%d\n",cnt);
                }
                else printf("%d\n",0);
            }
        }
        if(t) printf("\n");
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


        for(int l = 0 ; l < 8 ; l++)
        {
            int o = n + one[l];
            int p = m + two[l];

            if((o >= 0 && o < k) && (p >= 0 && p < strlen(grid[o])) && (visit[o][p] == -1) && (grid[o][p] == 'W'))
            {
                visit[o][p] = 0;
                Q.push(o);
                Q.push(p);
                cnt++;
            }
        }
    }
}
