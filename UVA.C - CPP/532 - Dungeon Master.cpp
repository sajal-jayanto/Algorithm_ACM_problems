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
#define MAX 31
#define MAXP 1000
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

struct node {
    int l;
    int r;
    int c;
};
node pos, one , two;

using namespace std;

int BFS();
bool is_valid(int i ,int  j ,int  k);
int a, b , c;
char bord[MAX][MAX][MAX];
int cost[MAX][MAX][MAX];

int main()
{
    while(scanf("%d %d %d", &a , &b , &c) && (a || b || c))
    {
        for(int i = 0 ; i < a ; i++) for(int j = 0 ; j < b ; j++) for(int k = 0 ; k < c ; k++)
        {
            scanf(" %c", &bord[i][j][k]);
            if(bord[i][j][k] == 'S') pos.l = i, pos.r = j, pos.c = k;
        }
        //for(int i = 0 ; i < a ; i++){ for(int j = 0 ; j < b ; j++){ for(int k = 0 ; k < c ; k++)  printf("%c", bord[i][j][k]); printf("\n");}}
        int n = BFS();
        if(n == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", n);
    }
    return 0;
}


int BFS()
{
    int x[] = {-1 , 1 , 0 , 0 , 0 , 0};
    int y[] = {0 , 0 , -1 , 1 , 0 , 0};
    int z[] = {0 , 0 , 0 , 0 , -1 , 1};

    memset(cost , -1 , sizeof(cost));
    cost[pos.l][pos.r][pos.c] = 0;
    queue < node > Q;
    Q.push(pos);
    while(!Q.empty())
    {
        one = Q.front();
        Q.pop();
        for(int i = 0 ; i < 6 ; i++)
        {
            two.l = one.l + x[i];
            two.r = one.r + y[i];
            two.c = one.c + z[i];
            if(is_valid(two.l , two.r , two.c))
            {
                cost[two.l][two.r][two.c] = cost[one.l][one.r][one.c] + 1;
                if(bord[two.l][two.r][two.c] == 'E') return cost[two.l][two.r][two.c];
                Q.push(two);
            }
        }
    }
    return -1;
}

bool is_valid(int i ,int  j ,int  k)
{
    if((i >= 0 && i < a) && (j >= 0 && j < b) && (k >= 0 && k < c) && (bord[i][j][k] != '#') && (cost[i][j][k] == -1))
    return true;
    return false;
}
