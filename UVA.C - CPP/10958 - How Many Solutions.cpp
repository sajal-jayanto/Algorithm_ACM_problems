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
#define MAX             18
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


bool sive[1000000];
vector < int > prime;

void is_prime()
{
    int n = sqrt(1000000);
    prime.push_back(2);
    for(int i = 3 ; i <= n ; i = i + 2)
    {
        if(!sive[i]) for(int j = (i * i) ; j < 1000000 ; j = j + (2 * i)) sive[j] = true;
    }
    for(int i = 3 ; i <  1000000 ; i = i + 2) if(!sive[i]) prime.push_back(i);
    //cout << prime.size() << endl;
}


long long factor(long long num)
{
    int n = sqrt(num);
    long long cnt ;
    long long ans = 1;
    for(int i = 0 ; prime[i] <= n ; ++i)
    {
        if(num % prime[i] == 0)
        {
            cnt = 1;
            while(num % prime[i] == 0)
            {
                num = num / prime[i];
                ++cnt;
            }
            n = sqrt(num);
            ans = (ans * cnt);
        }
    }
    if(num != 1) ans = ans << 1;
    return ans ;
}

int main()
{
    is_prime();
    int cc = 0;
    long long a , b , c , sum ;
    while(cin >> a >> b >> c && (a || b || c))
    {
        sum = a * b * c * c;
        sum = abs(sum);
        sum = (factor(sum) << 1) - 1;
        cout << "Case " << ++cc << ": " << sum << endl;
    }
    return 0;
}

