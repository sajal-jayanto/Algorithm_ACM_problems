/*
problem number : 357
problem name : Let Me Count The Ways
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

#define MAXR 6
#define MAXC 30005


long long call(int,int);

using namespace std;

int cost[] = {1,5,10,25,50};
long long DP[MAXR][MAXC];

int main()
{
    int a,sum;
    long long n;
    memset(DP,-1,sizeof(DP));
    while(scanf("%d",&a) == 1)
    {
        n = call(0,a);
        if(n == 1) printf("There is only %lld way to produce %d cents change.\n",n,a);
        else printf("There are %lld ways to produce %d cents change.\n",n,a);
    }
    return 0;
}

long long call(int i ,int m)
{

    if(i >= 5)
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
