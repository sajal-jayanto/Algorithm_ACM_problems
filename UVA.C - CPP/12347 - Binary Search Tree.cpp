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
#define INF             (1<<20)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             10100
#define MAXR            305
#define MAXC            305
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}

int num[MAX];
int one[MAX] , two[MAX];
void DFS(int a , int b);
void print(int temp);

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int cnt = 0;
    while(sf("%d", &num[cnt]) != EOF) cnt++;
    mem(one , -1);
    mem(two , -1);
    for(int i = 1 ; i < cnt ; ++i) DFS(0 , i);
    print(0);
}


void DFS(int a , int b)
{
    if(num[a] > num[b])
    {
        if(one[a] == -1) one[a] = b;
        else DFS(one[a] , b);
    }
    else
    {
        if(two[a] == -1) two[a] = b;
        else DFS(two[a] , b);
    }
}

void print(int temp)
{
    if(one[temp] != -1) print(one[temp]);
    if(two[temp] != -1) print(two[temp]);
    pf("%d\n", num[temp]);
}
