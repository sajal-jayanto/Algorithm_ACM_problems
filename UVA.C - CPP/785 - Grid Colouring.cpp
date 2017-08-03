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
#define MAX 50

using namespace std;

void BFS(int,int,char);

char grid[MAX][MAX];
int k;
int one[] = {-1,1,0,0};
int two[] = {0,0,-1,1};

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    int a,b;
    char str[MAX], c;
    while(gets(str))
    {
        k = 0;
        c = '\0';
        memset(grid, '\0', sizeof(grid));
        strcpy(grid[k++],str);
        while(gets(str))
        {
            strcpy(grid[k++],str);
            if(str[0] == '_') break;
        }
        for(int i = 0 ; i < k - 1 ; i++)
        {
            for(int j = 0 ; j < grid[i][j] ; j++)
            {
                if(grid[i][j] != '\0' && grid[i][j] != ' ' && c == '\0') c = grid[i][j];
                else if(grid[i][j] != ' ' && grid[i][j] != c)
                {
                    BFS(i,j,grid[i][j]);
                }
            }
        }
         for(int i = 0 ; i < k ; i++) printf("%s\n",grid[i]);
    }
    return 0;
}

void BFS(int i , int j, char ch)
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

        for(int l = 0 ; l < 4 ; l++)
        {
            int o = n + one[l];
            int p = m + two[l];

            if((o >= 0 && o < k) && (p >= 0 && p < strlen(grid[o])) && (grid[o][p] == ' '))
            {
                grid[o][p] = ch;
                Q.push(o);
                Q.push(p);
            }
        }
    }
}



