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
#define MAX             105
#define MAXR            305
#define MAXC            305
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}

int one[]={-1 ,-1 , 0 ,0 ,1 ,1};
int two[]={-1 , 0 ,-1 ,1 ,0 ,1};

///***************************************  END  **********************************************///


char bord[205][205];
bool flag;
int t;
void DFS(int a , int b);

int main()
{
    freopen("input.txt", "r" , stdin);
    int cc = 0;
    while(sf("%d" , &t) && t)
    {
        flag = false;
        for(int i = 0 ; i < t ; ++i) for(int j = 0 ; j < t ; ++j) sf(" %c", &bord[i][j]);
        //for(int i = 0 ; i < t ; ++i) for(int j = 0 ; j < t ; ++j) pf("%c", bord[i][j]);
        for(int i = 0 ; i < t ; ++i) if(bord[0][i] == 'b') DFS(0 , i);else if(flag) break;
        if(flag) pf("%d B\n", ++cc);
        else pf("%d W\n", ++cc);
    }
    return 0;
}

void DFS(int a , int b)
{
    bord[a][b] = 'w';
    if(a == t - 1) { flag = true; return; }
    for(int i = 0 ; i < 6 ; ++i)
    {
        int x = a + one[i];
        int y = b + two[i];
        if(x >= 0 && x < t && y >= 0 && y < t && bord[x][y] == 'b') DFS(x , y);
    }
}
