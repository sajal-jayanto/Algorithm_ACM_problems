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

#define MAX 1010
#define MAXN 35

using namespace std;

int price[MAX];
int weight[MAX];
int DP[MAX][MAXN];
int found(int,int,int,int);
int main()
{

    int t,n,g,hweight,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d %d",&price[i],&weight[i]);
        }
        sum = 0;
        scanf("%d",&g);
        while(g--)
        {
            scanf("%d",&hweight);
            memset(DP,-1,sizeof(DP));
            sum = sum + found(1,0,n,hweight);
        }
        printf("%d\n",sum);
    }
    return 0;
}

int found(int i,int w,int n,int c)
{

    if(i == n + 1) return 0;
    if(DP[i][w] != -1) return DP[i][w];
    int cost1 = 0;int cost2 = 0;
    if(w + weight[i] <= c) cost1 = price[i] + found(i + 1 ,w + weight[i] , n , c);
    cost2 = found(i + 1, w , n , c);
    DP[i][w] = max(cost1,cost2);
    return DP[i][w];
}
