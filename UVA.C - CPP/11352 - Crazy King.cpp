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
#define MAX 150
#define MAXP 1000
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;
struct node {
    int x ,y;
};
node ans , pos, temp , tem;
char bord[MAX][MAX];
int cost[MAX][MAX];
int r , c;

int one[] = {-1,0,1, 0,-1,-1,1, 1};
int two[] = { 0,1,0,-1,-1, 1,1,-1};
int Hone[] = {1,1,2,2,-1,-1,-2,-2};
int Htwo[] = {2,-2,1,-1,2,-2,1,-1};

void up_great(int a , int b);
void BFS();

int main()
{
   // F_TO_R;
   // F_TO_W;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &r , &c);
        for(int i = 0 ; i < r ; ++i) for(int j = 0 ; j < c;  ++j) scanf(" %c", &bord[i][j]);
        for(int i = 0 ; i < r ; ++i) for(int j = 0 ; j < c ; ++j)
        {
            if(bord[i][j] == 'A') pos.x = i, pos.y = j;
            else if(bord[i][j] == 'B') ans.x = i, ans.y = j;
            else if(bord[i][j] == 'Z') up_great(i ,j);
        }
        BFS();
        if(cost[ans.x][ans.y] == -1) printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n", cost[ans.x][ans.y]);
    }
    return 0;
}


void up_great(int a , int b)
{
    int k , l;
    for(int i = 0 ; i < 8 ; ++i)
    {
        k = a + Hone[i];
        l = b + Htwo[i];
        if(k >= 0 && k < r && l >= 0 && l < c && bord[k][l] == '.') bord[k][l] = '*';
    }
}

void BFS()
{
    memset(cost , -1 , sizeof(cost));
    cost[pos.x][pos.y] = 0;
    queue < node > Q;
    Q.push(pos);
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if(ans.x == temp.x && ans.y == temp.y) return ;
        for(int i = 0 ; i < 8 ; ++i)
        {
            tem.x = temp.x + one[i];
            tem.y = temp.y + two[i];
            if(tem.x >= 0 && tem.x < r && tem.y >= 0 && tem.y < c && bord[tem.x][tem.y] != 'Z' && bord[tem.x][tem.y] != '*' && cost[tem.x][tem.y] == -1)
            {
                cost[tem.x][tem.y] = cost[temp.x][temp.y] + 1;
                Q.push(tem);
            }
        }
    }

}

