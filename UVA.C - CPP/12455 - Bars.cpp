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
#define MAXC 1010

int DP[MAXR][MAXC];
int have[MAXR];
int call(int i,int c,int m);

int main()
{
    int t;
    int bar,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&bar);
        scanf("%d",&cnt);
        for(int i = 0 ; i < cnt ; i++) scanf("%d",&have[i]);
        memset(DP,-1,sizeof(DP));
        call(0,cnt,bar);
        if(DP[0][bar] == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

int call(int i,int c,int m)
{
    if(i >= c)
    {
        if(m == 0) return 1;
        else return 0;
    }
    if(DP[i][m] != -1) return DP[i][m];
    int one = 0;
    int two = 0;
    if(m - have[i] >= 0) one = call(i + 1 ,c, m - have[i]);
    two = call(i + 1,c,m);
    return DP[i][m] = one | two;
}
