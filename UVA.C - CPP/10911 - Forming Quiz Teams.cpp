#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")

using namespace std;

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


double x[20], y[20];
double cost[20][20];
bool vis[(1 << 17)];
double DP[(1 << 17)];
int n ;

double dis(int i, int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}


double call(int mark)
{
    if(mark == ((1 << (n << 1)) - 1) ) return 0;
    int temp;
    if(vis[mark]) return DP[mark];
    double &ret = DP[mark];
    ret = (1 << 30);
    for(int i = 0 ; i < (n << 1) ; ++i)
    {
        if((mark & (1 << i)) == 0)
        {
            for(int j = 0 ; j < (n << 1) ; ++j)
            {
                if(i == j) continue;
                if((mark & (1 << j)) == 0)
                {
                    temp = (mark | (1 << i));
                    temp = (temp | (1 << j));
                    ret = min(ret , call(temp) + cost[i][j]);
                }
            }
        }
    }
    vis[mark] = true;
    return ret;
}



int main()
{
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    string str;
    int cc = 0;
    while(cin >> n && n)
    {
        memset(vis , false , sizeof(vis));
        for(int i = 0 ; i < (n << 1) ; ++i)  cin >> str >> x[i] >> y[i];
        for(int i = 0 ; i < (n << 1) ; ++i)
        {
            for(int j = 0 ; j < (n << 1) ; ++j)
            {
                if(i == j) continue ;
                cost[i][j] = dis(i , j);
            }
        }
        cout << "Case " << ++cc << ": " << fixed << setprecision(2) << call(0) << endl;
    }
}
