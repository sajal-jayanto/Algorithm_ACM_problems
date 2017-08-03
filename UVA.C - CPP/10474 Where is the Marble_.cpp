#include <bits/stdc++.h>

using namespace std;

#define sf              scanf
#define pf              printf
#define fs              first22.03.2015
#define se              second
#define pb              push_back
#define ins             insert
#define Lb              lower_bound
#define Up              upper_bound
#define INF             (1<<15)
#define mem(a,b)        memset(a, b, sizeof(a))
#define MAX             2010
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
//int one [] = {1 ,0,-1, 0};
//int two [] = {0 ,1, 0,-1};
///S , SE , E , NE , N , NW , W , SW
//int one [] = {1 ,1 ,0,-1,-1,-1, 0, 1};
//int two [] = {0 ,1 ,1 ,1, 0,-1,-1,-1};
///Knight Direction
//int one[]={2 ,1 ,-1,-2,-2,-1, 1, 2};
//int two[]={1 ,2 , 2, 1,-1,-2,-2,-1};

///============================================================================================////

vector < int > ve;
map < int , int > mp;

int main()
{
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false); cin.tie(false);
    int n , m , temp , cnt , cc = 0;
    while(cin >> n >> m && (n || m))
    {
        cout << "CASE# " << ++cc << ":" << endl;
        for(int i = 0 ; i < n ; ++i)
        {
            cin >> temp;
            ve.push_back(temp);
        }
        sort(ve.begin() , ve.end());
        cnt = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            if(mp.find(ve[i]) == mp.end()) mp[ve[i]] = ++cnt;
            else ++cnt;
        }
        //for(auto it = mp.begin() ; it != mp.end() ; ++it) cout << it->first << " " << it->second << endl;
        while(m--)
        {
            cin >> temp;
            if(mp.find(temp) == mp.end()) cout << temp << " not found" << endl;
            else cout << temp << " found at " << mp[temp] << endl;
        }
        ve.clear();
        mp.clear();
    }
    return 0;
}

