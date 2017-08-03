#include <bits/stdc++.h>

using namespace std;

#define FF              freopen("input.txt" , "r" , stdin);
#define sf              scanf
#define pf              printf
#define fs              first
#define se              second
#define pb              push_back
#define ins             insert
#define Lb              lower_bound
#define Up              upper_bound
#define INF             (1<<30)
#define mem(a,b)        memset(a, b, sizeof(a))
#define MAX             100010
#define MAXR            100010
#define MAXC            100010

typedef long long ll;

const double PI = 2.0 * acos(0.0);
const double eps = 1e-9;

template < class T > T Abs(T x) { return x > 0 ? x : -x; }
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > inline T gcd(T a,T b) { if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b); }
template < class T > inline T lcm(T a,T b) { if(a < 0) return lcm(-a,b); if(b < 0)return lcm(a,-b); return a * (b / gcd(a , b)); }
template < class T > inline T sqr(T n) { return n * n; }
template < class T > T power(T n, T p)
{
    if(!p) return 1;
    else
    {
        T sum = sqr( power( n ,  p >> 1) );
        if(p & 1) sum =  n;
        return sum;
    }
}


ll bigmod(ll num , ll p , ll mod)
{
    ll sum = 1 , temp = num;
    while(p)
    {
        if(p & 1) sum = (sum * temp) % mod;
        temp = (temp * temp) % mod; p = p >> 1;
    }
    return sum;
}


/// S , E  , N , W
//int one [] = {1 ,0,-1, 0};
//int two [] = {0 ,1, 0,-1};
///S , SE , E , NE , N , NW , W , SW
//int one [] = {1 ,1 ,0,-1,-1,-1, 0, 1};
//int two [] = {0 ,1 ,1 ,1, 0,-1,-1,-1};
///Knight Direction
//int one[]={2 ,1 ,-1,-2,-2,-1, 1, 2};
//int two[]={1 ,2 , 2, 1,-1,-2,-2,-1};

bool day[4660];

int main()
{
   // freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false); cin.tie(false);
    int t , n , p , cn , sum;
    cin >> t;
    while(t--)
    {
        sum = 0;
        cin >> n >> p;
        while(p--)
        {
            cin >> cn;
            for(int i = cn ; i <= n ; i = i + cn) day[i] = true;
        }
        p = 7;
        cn = 6;
        for(int i = 1 ; i <= n ; ++i)
        {
            if(day[i] && i != cn && i != p) ++sum;
            if(i == cn) cn = cn + 7 ;
            if(i == p) p = p + 7;
            day[i] = false;
        }
        cout << sum << endl;
    }
    return 0;
}


