#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>

using namespace std;

#define F_TO_R          freopen("input.txt", "r" , stdin)
#define _pair(x,y)      make_pair(x,y)
#define INF             (1<<30)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             1002
#define MAXR            32000
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;


///***************************************  END  **********************************************///

vector < int > ve[MAX];
int cost[MAX];
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37};
void factor(int num);
void BFS(int n , int m);

int main()
{
    int n , m , cc = 0;
    while(sf("%d %d" , &n , &m) && (n || m))
    {
        mem(cost , -1);
        BFS(n , m);
        pf("Case %d: %d\n" , ++cc , cost[m]);
    }
    return 0;
}


void BFS(int n , int m)
{
    cost[n] = 0;
    queue < int > Q;
    Q.push(n);
    while(!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        if(k == m) return ;
        int len = ve[k].size();
        if( !len ) factor(k);
        len = ve[k].size();
        for(int i = 0 ; i < len ; ++i)
        {
            int l = k + ve[k][i];
            if(cost[l] == -1)
            {
                cost[l] = cost[k] + 1;
                Q.push(l);
            }
        }
    }
}

void factor(int num)
{
    int k = num;
    int n = sqrt(num);
    for(int i = 0 ; prime[i] <= n ; ++i)
    {
        if(num % prime[i] == 0)
        {
            while(num % prime[i] == 0) num = num / prime[i];
            n = sqrt(num);
            ve[k].push_back(prime[i]);
        }
    }
    if(num != 1 && num != k) ve[k].push_back(num);
}
