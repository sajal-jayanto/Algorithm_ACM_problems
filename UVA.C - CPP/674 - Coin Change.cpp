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

#define MAXR 6
#define MAXC 7500

int call(int i ,int m);

using namespace std;

int coin[] = {1,5,10,25,50};
int DP[MAXR][MAXC];

int main()
{
    int num;
    memset(DP,-1,sizeof(DP));
    while(scanf("%d",&num) == 1)
    {

        printf("%d\n",call(0,num));
    }
    return 0;
}
int call(int i ,int m)
{
    if(i >= 5)
    {
        if(m == 0) return 1;
        else return 0;
    }
    if(DP[i][m] != -1) return DP[i][m];
    int one = 0;
    int two = 0;
    if(m - coin[i] >= 0) one = call(i, m-coin[i]);
    two = call(i+1 , m);
    return DP[i][m] = one + two;
}
