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


int main()
{
   // freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    string str , temp , te ;
    int t , pos , n ;
    cin >> t ;
    while(t--)
    {
        cin >> n ;
        pos = 0;
        cin >> str ;
        temp = str ;
        temp = temp + str;
        te.clear();
        for(int i = 0 ; i < n * 2 ; ++i)
        {
            if(i > n)
            {
                te.erase(te.begin());
                if(str > te)
                {
                    str = te;
                    pos = i ;
                }
            }
            te.push_back(temp[i]);
        }
        cout << pos - n << endl;
    }
    return 0;
}
