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
int one[] = {-1 , 1 , 0 , 0};
int two[] = { 0 , 0 ,-1 , 1};

///***************************************  END  **********************************************///


char bord[205][205];
void BFS(int x , int y);
int n;

int main()
{
    //freopen("input.txt", "r" , stdin);
    int t , cnt , cc = 0;
    sf("%d" , &t);
    while(t--)
    {
        cnt = 0;
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i) for(int j = 0 ; j < n ; ++j) sf(" %c", &bord[i][j]);
        for(int i = 0 ; i < n ; ++i) for(int j = 0 ; j < n ; ++j)
        {
            if(bord[i][j] == 'x')
            {
                ++cnt;
                BFS( i , j );
            }
        }
        pf("Case %d: %d\n", ++cc , cnt);
    }
    return 0;
}

void BFS(int x , int y)
{
    bord[x][y] = '.';
    queue < int > Q;
    Q.push(x);
    Q.push(y);
    while(!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        int l = Q.front();
        Q.pop();
        for(int i = 0 ; i < 4 ; ++i)
        {
            int m = k + one[i];
            int o = l + two[i];
            if(m >= 0 && m < n && o >= 0 && o < n && (bord[m][o] == 'x' || bord[m][o] == '@'))
            {
                bord[m][o] = '.';
                Q.push(m);
                Q.push(o);
            }
        }
    }
}
