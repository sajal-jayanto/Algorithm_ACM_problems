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
#define INF             (1<<20)
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


int num[160][160];

int main()
{
    ios_base::sync_with_stdio(false);  cin.tie(false);
   // freopen("input.txt" , "r" , stdin);
    int t , n , m , mx , temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1 ; i <= n ; ++i)
        {
            for(int j = 1 ; j <= n ; ++j)
            {
                cin >> temp;
                num[i][j] = num[i][j + n] = temp;
            }
        }
        m = n << 1;
        for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j < m ; ++j)
        {
            num[i][j] = num[i][j] + num[i][j - 1];
            num[i + n][j] = num[i][j];
        }
        temp = 0;
        for(int i = 0; i < n ; i++)
        {
            int p = 1;
            for(int j = i + 1; j < m && p <= n ; j++ , p++)
            {
                for(int h = 1; h <= n ; h++)
                {
                    int sum = 0, l = 1;
                    for(int k = h; k < m && l <= n; k++ , l++)
                    {
                        sum += num[k][j] - num[k][i];
                        //cout << sum << endl;
                        temp = max(temp , sum);
                        if(sum < 0) sum = 0;
                    }
                }
            }
        }
        cout << temp << endl;
    }
    return 0;
}
