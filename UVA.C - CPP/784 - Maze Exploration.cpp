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
#define MAXR 50
#define MAXC 100

using namespace std;

void BFS(int,int);

char grid[MAXR][MAXC];
int k;
int one[] = {-1,1,0,0};
int two[] = {0,0,-1,1};

int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    int a,b;
    bool flage;
    char str[MAXC];
    scanf("%d",&t);
    gets(str);
    while(t--)
    {
        k = 0;
        flage = false;
        while(gets(str))
        {
            strcpy(grid[k],str);
            if(str[0] == '_') break;
            if(!flage)
            {
                for(int i = 0 ; grid[k][i] ; i++)
                {
                    if(grid[k][i] == '*') {flage = true; a = k ; b = i ; grid[k][i] = '#'; break;}
                }
            }
            k++;
        }
        BFS(a,b);
        for(int i = 0 ; i < k + 1; i++) printf("%s\n",grid[i]);
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

        for(int l = 0 ; l < 4 ; l++)
        {
            int o = n + one[l];
            int p = m + two[l];

            if((o >= 0 && o < k) && (p >= 0 && p < strlen(grid[o])) && (grid[o][p] == ' '))
            {
                grid[o][p] = '#';
                Q.push(o);
                Q.push(p);
            }
        }
    }
}
