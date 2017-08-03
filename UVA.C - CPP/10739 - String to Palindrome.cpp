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

char first[MAX];
int DP[MAX][MAX];
int LCS(int i , int j);

int main()
{
    int t,cc = 0;
    scanf("%d",&t);
    gets(first);
    while(t--)
    {
        gets(first);
        memset(DP, -1, sizeof(DP));
        printf("Case %d: %d\n",++cc,LCS(0,strlen(first) - 1));
    }
    return 0;
}

int LCS(int i , int j)
{
    if(i >= j) return 0;
    if(DP[i][j] != -1) return DP[i][j];
    if(first[i] == first[j]) return LCS(i + 1 , j - 1);
    else DP[i][j] = min(LCS(i + 1 , j),min(LCS(i , j - 1), LCS(i + 1 , j - 1))) + 1;
    return DP[i][j];
}
