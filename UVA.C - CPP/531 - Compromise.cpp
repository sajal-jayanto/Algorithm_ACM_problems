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
#define MAX 105

using namespace std;
void LCS(int x , int y);
void printLCS(int x , int y);
string first[MAX];
string second[MAX];
string ans[MAX];
int DP[MAX][MAX];
int k;

int main()
{
    int a,b;
    while(cin >> first[0])
    {
        a = 1;
        b = 0;
        while(cin >> first[a])
        {
            if(first[a][0] == '#') break;
            else a++;
        }
        while(cin >> second[b])
        {
            if(second[b][0] == '#') break;
            else b++;
        }
        k = 0;
        LCS(a,b);
        printLCS(a,b);
        for(int i = k - 1; i >= 0 ; i--)
        {
            printf("%s",ans[i].c_str());
            if(i) printf(" ");
        }
        if(k) printf("\n");
    }
    return 0;
}

void LCS(int x , int y)
{
    memset(DP,0,sizeof(DP));
    for(int i = 1 ; i <= x ; i++)
    {
        for(int j = 1 ; j <= y ; j++)
        {
            if(first[i - 1] == second[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
            else DP[i][j] = max(DP[i][j - 1] , DP[i - 1][j]);
        }
    }
}

void printLCS(int x , int y)
{
    if(x == 0 || y == 0) return ;
    if(first[x - 1] == second[y - 1])
    {
        ans[k++] = first[x - 1];
        printLCS(x - 1, y - 1);
    }
    else if(DP[x][y] == DP[x - 1][y]) printLCS(x - 1 , y);
    else printLCS(x, y - 1);
}
