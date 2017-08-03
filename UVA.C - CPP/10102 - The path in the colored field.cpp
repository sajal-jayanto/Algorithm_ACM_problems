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

struct node {
    int x ;
    int y ;
    node(){}
    node(int a , int b){x = a; y = b;}
};
vector < node > ve;
int t;
char bord[MAX][MAX];
int vis[MAX][MAX];
int BFS(node temp);

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int len, ans;
    while(sf("%d", &t) == 1)
    {
        for(int i = 0 ; i < t ; ++i)
        {
            for(int j = 0 ; j < t ; ++j)
            {
                sf(" %c", &bord[i][j]);
                if(bord[i][j] == '1') ve.push_back(node(i , j));
            }
        }
        ans = 0;
        len = ve.size();
        for(int i = 0 ; i < len ; ++i) ans = max(ans , BFS(ve[i]));
        pf("%d\n" , ans);
        ve.clear();
    }
    return 0;
}




int BFS(node temp)
{
    mem(vis , -1);
    vis[temp.x][temp.y] = 0;
    queue < node > Q;
    Q.push(temp);
    while(!Q.empty())
    {
        node k = Q.front();
        if(bord[k.x][k.y] == '3') return vis[k.x][k.y];
        Q.pop();
        for(int i = 0 ; i < 4 ; ++i)
        {
            node l;
            l.x = k.x + one[i];
            l.y = k.y + two[i];
            if(l.x >= 0 && l.x < t && l.y >= 0 && l.y < t && vis[l.x][l.y] == -1)
            {
                vis[l.x][l.y] = vis[k.x][k.y] + 1;
                Q.push(l);
            }
        }
    }
}
