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

long long DP[305][305][305];

long long call(int valu , int taka , int coin)
{
    if(valu <= 0)
    {
        if(!valu) return 1;
        return 0;
    }
    if(taka <= 0 || coin <= 0) return 0;
    long long &ret = DP[valu][taka][coin];
    if(ret != -1) return ret;
    ret = 0;
    ret = ret + call(valu - taka , taka , coin - 1);
    ret = ret + call(valu , taka - 1 , coin);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(false);
    string str;
    int cnt  = 0 , a , b , c , len;
    mem(DP , -1);
    while(getline(cin , str))
    {
        cnt = 0;
        len = str.length();
        for(int i = 0 ; i < len ; ++i) if(str[i] == ' ') ++cnt;
        if(!cnt) {
            sscanf(str.c_str() , "%d" , &a);
            b = c = a;
        }
        else if(cnt == 1) {
            sscanf(str.c_str() , "%d %d" , &a , &b);
            c = b;
        }
        else sscanf(str.c_str() , "%d %d %d" , &a , &b , &c);
        if(!cnt) cout << call(a , a , a) << endl;
        else if(cnt == 1) cout << call(a , a , min(b , 300)) << endl;
        else
        {
            if(!a && !b && !c) cout << 1 << endl;
            else cout << call(a , a , min(c , 300)) - call(a , a, min(b - 1 , 300)) << endl;
        }
    }
    return 0;
}
