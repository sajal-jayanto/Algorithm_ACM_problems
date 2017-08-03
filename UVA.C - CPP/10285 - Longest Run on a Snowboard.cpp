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
#define MAX 105
using namespace std;
int BFS(int i , int j);
int row , col;
string s;
int bord[MAX][MAX];
int visit[MAX][MAX];
int one[] = {0,0,1,-1};
int two[] = {1,-1,0,0};

int main()
{
    //freopen("input.txt" , "r" ,stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        getchar();
        cin >> s;
        scanf("%d %d",&row, &col);
        memset(visit , -1 , sizeof(visit));
        for(int i = 0 ; i < row ;i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                scanf("%d",&bord[i][j]);
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if(visit[i][j] = -1)
                {
                    cnt = max(cnt , BFS(i , j));
                }
                else  cnt = max(cnt , visit[i][j]);
            }
        }
        printf("%s: %d\n",s.c_str() , cnt);
    }
    return 0;
}

int BFS(int i , int j)
{
    int cnt = 0;
    queue < int > Q;
    Q.push(i);
    Q.push(j);
    visit[i][j] = 0;
    while(!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        int l = Q.front();
        Q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int x = one[i] + k;
            int y = two[i] + l;
            if((x >= 0 && x < row) && (y >= 0 && y < col) && (bord[k][l] > bord[x][y]))
            {
                visit[x][y] = visit[k][l] + 1;
                Q.push(x);
                Q.push(y);
               cnt = max(cnt ,visit[x][y]);
            }
        }
    }
    return cnt + 1;
}
