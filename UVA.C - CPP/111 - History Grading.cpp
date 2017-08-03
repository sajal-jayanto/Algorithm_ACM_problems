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
#define MAX 25


using namespace std;

int first[MAX];
int second[MAX];
int DP[MAX][MAX];
int LCS(int);


int main()
{

    int t;
    int temp;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++)
    {
        scanf("%d",&temp);
        first[temp - 1] = i;
    }
    while(scanf("%d",&temp) == 1)
    {
        second[temp - 1] = 0;
        for(int i = 1 ; i < t ; i++)
        {
            scanf("%d",&temp);
            second[temp - 1] = i;
        }
        printf("%d\n",LCS(t));
    }
    return 0;
}

int LCS(int x)
{
    memset(DP, 0, sizeof(DP));
    for(int i = 1 ; i <= x ; i++)
    {
        for(int j = 1 ; j <= x ; j++)
        {
            if(first[i - 1] == second[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
            else DP[i][j] = max(DP[i][j - 1] , DP[i - 1][j]);
        }
    }
    return DP[x][x];
}
