#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <cstring>
#define MAX 8
using namespace std;

int bord[MAX][MAX];
int ans;
int DP[MAX][MAX];
void mark(int n , int m);
void unmark(int n , int m);
void back_traking(int r , int cnt);
int sum();
int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(DP ,0, sizeof(DP));
        for(int i = 0 ; i < 8 ; i++)
            for(int j = 0 ; j < 8 ; j++)
                scanf("%d",&bord[i][j]);
        ans = 0;
        back_traking(0,0);
        printf("%5d\n",ans);
    }
    return 0;
}

void back_traking(int r , int cnt)
{
    if(cnt == 8)
    {
        ans = max(ans, sum());
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

int sum()
{
    int total = 0;
    for(int i = 0 ; i < 8 ; i++)
        for(int j = 0 ; j < 8 ; j++)
            if(DP[i][j] == 0) total = total + bord[i][j];

    return total;
}
