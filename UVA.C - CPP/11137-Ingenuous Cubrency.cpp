/*
problem number : 1004
problem name : Monkey Banana Problem
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

#define MAXR 22
#define MAXC 10005

long long call(int i , int m);

using namespace std;

int cost[] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
long long DP[MAXR][MAXC];

int main()
{

    int sum;
    memset(DP,-1,sizeof(DP));
    while(scanf("%d",&sum) == 1)
    {
        printf("%lld\n",call(0,sum));
    }
    return 0;
}

long long call(int i , int m)
{

    if(i >= 21)
    {
        if(m == 0) return 1;
        else return 0;
    }
    if(DP[i][m] != -1) return DP[i][m];
    long long one = 0;
    long long two = 0;
    if(m - cost[i] >= 0) one = call(i , m - cost[i]);
    two = call(i + 1 , m);
    return DP[i][m] = one + two;
}
