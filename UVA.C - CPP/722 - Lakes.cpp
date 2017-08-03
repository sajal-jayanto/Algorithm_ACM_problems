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
#include <unordered_map>
#include <unordered_set>


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
int one [] = {0 ,1 , 0,-1};
int two [] = {1 ,0 ,-1, 0};
///S , SE , E , NE , N , NW , W , SW
//int one [] = {1 ,1 ,0,-1,-1,-1, 0, 1};
//int two [] = {0 ,1 ,1 ,1, 0,-1,-1,-1};
///Knight Direction
//int one[]={2 ,1 ,-1,-2,-2,-1, 1, 2};
//int two[]={1 ,2 , 2, 1,-1,-2,-2,-1};


///***********************************************END*********************************//////////////////

char str[105][105];
int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , row, col , a , b , cnt;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d\n" , &a , &b);
        row = 0;
        cnt = 1;
        while(gets(str[row]))
        {
            if(!strlen(str[row])) break;
            ++row;
        }
        col = strlen(str[0]);
        queue < int > Q;
        str[a - 1][b - 1] = '1';
        Q.push(a - 1);
        Q.push(b - 1);
        while(!Q.empty())
        {
            int k = Q.front(); Q.pop();
            int l = Q.front(); Q.pop();
            for(int i = 0 ; i < 4 ; ++i)
            {
                int m = k + one[i];
                int n = l + two[i];
                if(m >= 0 && m < row && n >= 0 && n < col && str[m][n] == '0')
                {
                    str[m][n] = '1';
                    Q.push(m);
                    Q.push(n);
                    ++cnt;
                }
            }
        }
        pf("%d\n" , cnt);
        if(t) pf("\n");
    }
    return 0;
}
