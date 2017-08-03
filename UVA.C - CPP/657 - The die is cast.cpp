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
#define MAX 1010
#define MAXP 431
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;
int one[] = {-1,1,0,0};
int two[] = {0,0,-1,1};
int r , c;
char bord[MAX][MAX];
int cnt;
void DFS(int a , int b);
void DFS1(int a , int b);

int main()
{
    int cc = 0;
    vector < int > ans;
    while(scanf("%d %d", &c , &r) && (r || c))
    {
        for(int i = 0 ; i < r ; ++i) for(int j = 0 ; j < c ; ++j) scanf(" %c", &bord[i][j]);
       // for(int i = 0 ; i < r ; ++i){ for(int j = 0 ; j < c ; ++j) printf("%c" , bord[i][j]); printf("\n");}
        for(int i = 0 ; i < r ; ++i) for(int j = 0 ; j < c ; ++j)
        {
            if(bord[i][j] != '.')
            {
                cnt = 0;
                DFS(i , j);
                ans.push_back(cnt);
            }
        }
        sort( ans.begin() , ans.end() );
        printf("Throw %d\n%d", ++cc , ans[0]);
        for(int i = 1 ; i < ans.size() ; ++i) printf(" %d" , ans[i]);
        printf("\n\n");
        ans.clear();
    }
    return 0;
}


void DFS(int a , int b)
{
    if(a < 0 || a == r || b < 0 || b == c || bord[a][b] == '.') return ;
    if(bord[a][b] == 'X')
    {
        cnt++;
        DFS1(a , b);
    }
    bord[a][b] = '.';
    for(int i = 0 ; i < 4  ; ++ i) DFS(a + one[i] , b + two[i]);
}


void DFS1(int a , int b)
{
    if(a < 0 || a == r || b < 0 || b == c || bord[a][b] != 'X') return ;
    bord[a][b] = '*';
    for(int i = 0 ; i < 4  ; ++i) DFS1(a + one[i] , b + two[i]);
}
