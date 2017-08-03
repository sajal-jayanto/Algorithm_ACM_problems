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
#define MAX             10001000
#define MAXR            6064581
#define MAXC            100010

typedef long long ll;

const double PI = 2.0 * acos(0.0);
const double eps = 1e-9;

template < class T > T Abs(T x) { return x > 0 ? x : -x; }
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > inline T gcd(T a,T b) { if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b); }
template < class T > inline T lcm(T a,T b) { if(a < 0) return lcm(-a,b); if(b < 0)return lcm(a,-b); return a * (b / gcd(a , b)); }
long long bit_set(long long k , int p) { return k = (k|(1 << p));}
long long re_set(long long k , int p) { return k = (k & ~(1 << p));}
template < class T > inline T sqr(T n) { return n * n; }

long long bigmod ( long long a, long long p, long long mod )
{
    long long res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}
///-------------------------------------------------END---------------------------------------------///

int g(int n);
int f(int n);
int f_dp[50];
int g_dp[50];

int f(int n)
{
    if(n == 0) return 1;
    if(n == 1) return 0;
    if(f_dp[n] != -1) return f_dp[n];
    return f_dp[n] = f(n - 2) + 2 * g(n - 1);
}


int g(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(g_dp[n] != -1) return g_dp[n];
    return g_dp[n] = f(n - 1) + g(n - 2);
}

int main()
{
    int t;
    memset(g_dp , -1 , sizeof(g_dp));
    memset(f_dp , -1 , sizeof(f_dp));
    while(cin >> t && t != -1)
    {
        if(t % 2) cout << 0 << endl;
        else cout << f(t) << endl;
    }
    return 0;
}

