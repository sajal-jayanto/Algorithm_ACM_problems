#include <bits/stdc++.h>


using namespace std;

#define sf         scanf
#define pf         printf
#define fr         first
#define se         second
#define PI         (2 *  acos(0.0))
#define eps        1e-7
#define mem(a,b)   memset(a, b, sizeof(a))
#define ios        ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false);

///**********************************************************************////////

template < class T > T Abs(T x) { return x > 0 ? x : -x; }
template < class T > inline T gcd(T a,T b)  {  return (b == 0) ? a : gcd(b ,a % b); }
template < class T > inline T lcm(T a,T b) {  return a * (b / gcd(a , b)); }
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > inline constexpr T pow(const T base, unsigned const exponent) { return (exponent == 0) ? 1 : (base * pow(base, exponent-1)); }

///*********************************************************************/////

long long ar[300010];

int main()
{
    //freopen("tem.txt" , "r" , stdin);
    int temp;
    long long n , m ,  x , ans = 0 ;
    sf("%lld %lld" , &n , &m);
    for(int i = 1 ; i <= n ; ++i) sf("%lld" , &ar[i]);
    for(int i = 1 ; i <= n ; ++i) ar[i] = ar[i] + ar[i - 1];
    for(int i = 1 ; i <= n ; ++i)
    {
        temp = upper_bound(ar + i , ar + n + 1 , ar[i - 1] + m) - (ar + 1);
        x = ar[temp] - ar[i - 1];
        if(x <= m) ans = max(ans , x);
    }
    pf("%lld\n" , ans);
    return 0;
}