#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <string>
#define MAXQ 8
#define MAX 100
using namespace std;


void mark(int n , int m);
void unmark(int n , int m);
void back_traking(int r , int cnt);
void cmp();
int DP[MAX][MAX];
int save[MAX][MAXQ];
int ar[MAX];
int k = 0;
int ans;



int main()
{
    int cc = 0;
    back_traking(0,0);
    while(scanf("%d %d %d %d %d %d %d %d",&ar[0],&ar[1],&ar[2],&ar[3],&ar[4],&ar[5],&ar[6],&ar[7]) == 8)
    {
        ans = 0;
        cmp();
        printf("Case %d: %d\n",++cc,MAXQ - ans);
    }
    return 0;
}

void back_traking(int r , int cnt)
{
    if(cnt == 8)
    {
        int n = 0;
        for(int i = 0 ; i < 8 ;i++)
            for(int j = 0 ; j < 8 ;j++)
                if(DP[i][j] == 0) save[k][n++] = j + 1;
        k++;
        return ;
    }
    for(int i = 0 ; i < 8 ; i++)
    {
        if(DP[r][i] == 0)
        {
            mark(r, i);
            back_traking(r + 1 , cnt + 1);
            unmark(r , i);
        }
    }
}
void mark(int n , int m)
{

    for(int i = 0 ; i < 8 ; i++)  DP[n][i]++;
    for(int j = 0 ; j < 8 ; j++)  DP[j][m]++;
    DP[n][m] = 0;
    for(int i = 1 ; i < 8 ; i++)
    {
        if(n + i < 8  &&  m + i < 8 ) DP[i + n][m + i]++;
        if(n - i >= 0 &&  m - i >= 0) DP[n - i][m - i]++;
        if(n + i < 8  &&  m - i >= 0) DP[i + n][m - i]++;
        if(n - i >= 0 &&  m + i < 8 ) DP[n - i][m + i]++;
    }
}
void unmark(int n ,int m)
{
    for(int i = 0 ; i < 8 ; i++)  DP[n][i]--;
    for(int j = 0 ; j < 8 ; j++)  DP[j][m]--;
    DP[n][m] = 0;
    for(int i = 1 ; i < 8 ; i++)
    {
        if(n + i < 8  &&  m + i < 8 ) DP[i + n][m + i]--;
        if(n - i >= 0 &&  m - i >= 0) DP[n - i][m - i]--;
        if(n + i < 8  &&  m - i >= 0) DP[i + n][m - i]--;
        if(n - i >= 0 &&  m + i < 8 ) DP[n - i][m + i]--;
    }
}

void cmp()
{

    for(int i = 0 ; i < k ; i++)
    {
        int c = 0;
        for(int j = 0 ; j < 8 ; j++)
            if(ar[j] == save[i][j]) c++;
        ans = max(ans , c);
    }
}
