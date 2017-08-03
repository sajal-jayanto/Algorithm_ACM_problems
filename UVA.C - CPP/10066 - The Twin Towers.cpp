#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#define MAX 105

using namespace std;
int A[MAX];
int B[MAX];
int DP[MAX][MAX];

int main()
{
    int x,y,cc = 0;
    while(scanf("%d %d",&x,&y) && (x || y))
    {

        for(int i = 0 ; i < x ; i++) scanf("%d",&A[i]);
        for(int j = 0 ; j < y ; j++) scanf("%d",&B[j]);
        memset(DP, 0 , sizeof(DP));

        for(int i = 1 ; i <= x ; i++)
        {
            for(int j = 0 ; j <= y ; j++)
            {
                if(A[i - 1] == B[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
                else DP[i][j] = max(DP[i][j - 1] , DP[i - 1][j]);
            }
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++cc,DP[x][y]);
    }
    return 0;
}
