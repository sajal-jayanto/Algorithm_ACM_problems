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
int DP[MAX][MAX];
int save[MAX][MAXQ];
void print();
int a,b,k = 0;

int main()
{
    back_traking(0,0);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        print();
        if(t) printf("\n");
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

void print()
{
    int cc = 0;
    for(int i = 0 ; i < k ; i++)
    {
        if(save[i][b - 1] == a )
        {
            printf("%2d     ",++cc);
            for(int j = 0 ; j < 8 ; j++) printf(" %d",save[i][j]);
            printf("\n");
        }
    }
}
