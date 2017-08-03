//#include <bits/stdc++.h>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <utility>
#include <sstream>
#include <numeric>
#include <iterator>
#include <iostream>
#include <algorithm>


using namespace std;

#define sf              scanf
#define pf              printf
#define fs              first
#define se              second
#define pb              push_back
#define ins             insert
#define Lb              lower_bound
#define Up              upper_bound
#define INF             0x7F7F7F7F
#define mem(a,b)        memset(a, b, sizeof(a))
#define MAX             100010
#define MAXR            100010
#define MAXC            100010

typedef long long ll;

const double PI = 2.0 * acos(0.0);
const double eps = 1e-9;

template < class T > T Abs(T x) { return x > 0 ? x : -x; }
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > inline T sqr(T n) { return n * n; }

template < class T > inline T gcd(T a,T b)
{
    if(a < 0) return gcd(-a,b);
    if(b < 0) return gcd(a,-b);
    return (b == 0) ? a : gcd(b ,a % b);
}

template < class T > inline T lcm(T a,T b)
{
    if(a < 0) return lcm(-a,b);
    if(b < 0) return lcm(a,-b);
    return a * (b / gcd(a , b));
}

template < class T > T power(T n, int p)
{
    if(!p) return 1;
    else
    {
        T sum = sqr( power( n ,  p >> 1) );
        if(p & 1) sum =  n;
        return sum;
    }
}


//ll bigmod(ll num , ll p , ll mod)
//{
//    ll sum = 1 , temp = num;
//    while(p)
//    {
//        if(p & 1) sum = (sum * temp) % mod;
//        temp = (temp * temp) % mod; p = p >> 1;
//    }
//    return sum;
//}


/// S , E  , N , W
////int one [] = {0 ,1 , 0,-1};
////int two [] = {1 ,0 ,-1, 0};
///S , SE , E , NE , N , NW , W , SW
//int one [] = {1 ,1 ,0,-1,-1,-1, 0, 1};
//int two [] = {0 ,1 ,1 ,1, 0,-1,-1,-1};
///Knight Direction
//int one[]={2 ,1 ,-1,-2,-2,-1, 1, 2};
//int two[]={1 ,2 , 2, 1,-1,-2,-2,-1};


///***********************************************END*********************************//////////////////

char bord[105][105];

int main()
{
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false); cin.tie(false);
    int n , m , s , x , y , cnt;
    char ch , st;
    while(cin >> n >> m >> s && (n || m || s))
    {
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                cin >> bord[i][j];
                if(isalpha(bord[i][j]))
                {
                    x = i; y = j;
                    if(bord[i][j] == 'N') ch = 'N';
                    else if(bord[i][j] == 'S') ch = 'S';
                    else if(bord[i][j] == 'L') ch = 'E';
                    else ch = 'W';
                }
            }
        }
        cnt = 0;
        for(int i = 0 ; i < s ; ++i)
        {
            cin >> st;
            if(st == 'F')
            {
                if(ch == 'N')
                {
                    if(x - 1 >= 0 && x < n && bord[x - 1][y] != '#')
                    {
                        x = x - 1;
                        if(bord[x][y] == '*')
                        {
                            bord[x][y] = '.';
                            ++cnt;
                        }
                    }
                }
                else if(ch == 'S')
                {
                    if(x >= 0 && x + 1 < n && bord[x + 1][y] != '#')
                    {
                        x = x + 1;
                        if(bord[x][y] == '*')
                        {
                            bord[x][y] = '.';
                            ++cnt;
                        }
                    }
                }
                else if(ch == 'E')
                {
                    if(y >= 0 && y + 1 < m && bord[x][y + 1] != '#')
                    {
                        y = y + 1;
                        if(bord[x][y] == '*')
                        {
                            bord[x][y] = '.';
                            ++cnt;
                        }
                    }
                }
                else
                {
                    if(y - 1 >= 0 && y < m && bord[x][y - 1] != '#')
                    {
                        y = y - 1;
                        if(bord[x][y] == '*')
                        {
                            bord[x][y] = '.';
                            ++cnt;
                        }
                    }
                }
            }
            else if(st == 'D')
            {
                if(ch == 'N') ch = 'E';
                else if(ch == 'S') ch = 'W';
                else if(ch == 'E') ch = 'S';
                else ch = 'N';
            }
            else if(st == 'E')
            {
                if(ch == 'N') ch = 'W';
                else if(ch == 'S') ch = 'E';
                else if(ch == 'E') ch = 'N';
                else ch = 'S';
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
