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
#define MAX 1010

using namespace std;
int DP[MAX][MAX];
char first[MAX];
char second[MAX];

int main()
{

    while(gets(first))
    {
        gets(second);

        int x = strlen(first);
        int y = strlen(second);

        memset(DP ,0, sizeof(DP));

        for(int i = 1 ; i <= x ; i++)
        {
            for(int j = 1 ; j <= y ; j++)
            {
                if(first[i - 1] == second[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
                else DP[i][j] = max(DP[i][j - 1] , DP[i - 1][j]);
            }
        }
        printf("%d\n",DP[x][y]);
    }
    return 0;
}
