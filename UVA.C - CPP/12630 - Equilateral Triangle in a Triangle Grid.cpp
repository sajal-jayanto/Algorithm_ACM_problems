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
#define MAX             105
#define MAXR            9598
#define MAXC            10000LL
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

int ar[MAX];
int sum(int n);

int main()
{
    int n;
    ar[2] = 1;
    ar[3] = 5;
    for(int i = 4 ; i < MAX ; ++i) ar[i] = sum(i - 1) + ar[i - 1] + (ar[i - 1] - ar[i - 2]);
    while(sf("%d" , &n) && n) pf("%d\n" , ar[n]);
    return 0;
}


int sum(int n)
{
    return ((n * (n + 1)) >> 1);
}
