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

string str;
int len ;
long long lim = 2147483647LL;
long long DP[201];

long long call(int pos)
{
    if(pos >= len) return 0;
    long long &ret = DP[pos];
    if(ret != -1) return ret;
    ret = 0;
    string temp = "" ; long long n;
    for(int i = 1 ; i <= 10 ; ++i)
    {
        temp = temp + str[pos + i - 1];
        n =  atoll(temp.c_str());
        if(n <= lim) ret = max(ret , n + call(pos + i));
        else break;
    }
    return ret;
}
int main()
{
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false); cin.tie(false);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> str;
        len = str.length();
        memset(DP , -1 , sizeof(DP));
        cout << call(0) << endl;
    }
    return 0;
}
