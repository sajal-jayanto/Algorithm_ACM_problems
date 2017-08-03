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



string str[3];

bool win(char ch);


int main()
{
   // freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false); cin.tie(false);
    int t , x , y;
    cin >> t;
    while(t--)
    {
        x = 0 ; y = 0;
        for(int i = 0 ; i < 3 ; ++i) cin >> str[i];
        for(int i = 0 ; i < 3 ; ++i) for(int j = 0 ; j < 3 ; ++j)
        {
            if(str[i][j] == 'O') ++x;
            else if(str[i][j] == 'X') ++y;
        }
        if(x == y ||  x + 1 == y)
        {
            if(win('X') && win('O')) cout << "no" << endl;
            else if(win('X'))
            {
                if(x + 1 == y) cout << "yes" << endl;
                else cout << "no" << endl;
            }
            else if(win('O'))
            {
                if(x == y) cout << "yes" << endl;
                else cout << "no" << endl;
            }
            else cout << "yes" << endl;
        }
        else cout << "no" << endl;
    }
    return 0;
}


bool win(char ch)
{
    for(int i = 0 ; i < 3 ; ++i)
    {
        if(str[i][0] == str[i][1] && str[i][0] == str[i][2] && str[i][0] == ch) return true;
        if(str[0][i] == str[1][i] && str[0][i] == str[2][i] && str[0][i] == ch) return true;
    }
    if(str[0][0] == str[1][1] && str[0][0] == str[2][2] && str[0][0] == ch) return true;
    if(str[0][2] == str[1][1] && str[0][2] == str[2][0] && str[0][2] == ch) return true;
    return false;
}
