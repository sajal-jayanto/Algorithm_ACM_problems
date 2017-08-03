/*
problem number : 147
problem name : Dollars
*/
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

#define MAXR 12
#define MAXC 30005


long long call(int,int);

using namespace std;

int cost[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
long long DP[MAXR][MAXC];

int main()
{
    int a,b,sum;
    memset(DP,-1,sizeof(DP));
    while(scanf("%d.%d",&a,&b) && (a || b))
    {
        sum = (100 * a) +  b;
        printf("%3d.%02d%17lld\n",a,b,call(0,sum));
    }
    return 0;
}

long long call(int i ,int m)
{

    if(i >= 11)
    {
        if(m == 0) return 1;
        else return 0;
    }
    if(DP[i][m] != -1) return DP[i][m];
    long long one = 0;
    long long two = 0;
    if(m - cost[i] >= 0) one = call(i , m - cost[i]);
    two = call(i + 1, m);
    return DP[i][m] = one + two;
}
