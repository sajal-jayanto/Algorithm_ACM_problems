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

map < char , vector < char > > mp;
map < char , vector < char > > ::iterator x;
map < char , int > cnt;
map < char , int > ::iterator y;
map < char , bool > vis;


void dfs( char ch)
{
    vis[ch] = true;
    int len = mp[ch].size();
    for(int i = 0 ; i < len ; ++i)
    {
        cnt[mp[ch][i]]++;
        if(!vis[mp[ch][i]]) dfs(mp[ch][i]);
    }
}


int main()
{
   // freopen("input.txt" , "r"  , stdin);
   ios_base::sync_with_stdio(false); cin.tie(false);
    string str;
    stack < char > Q;
    int t , len , cc = 0;
    cin >> t;
    while(t--)
    {
        cin >> str;
        len = str.length();
        for(int i = 0 ; i < len ; ++i)
        {
            if(!Q.empty())
            {
                char temp = Q.top();
                if(temp == str[i])
                {
                    Q.pop();
                    continue;
                }
                mp[temp].push_back(str[i]);
                mp[str[i]].push_back(temp);
                Q.push(str[i]);
            }
            else Q.push(str[i]);
            vis[str[i]] = false;
            cnt[str[i]] = 0;
        }
        dfs(str[0]);
        cout << "Case " << ++cc << endl;
        for(y = cnt.begin() ; y != cnt.end() ; ++y)
        cout << y->first << " = " << y->second << endl;
        mp.clear();
        cnt.clear();
        vis.clear();
    }
    return 0;
}
