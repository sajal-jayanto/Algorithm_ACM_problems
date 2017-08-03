#include <bits/stdc++.h>


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


struct node {
    int x ,  y;
    node(){}
    node(int a , int b){ x = a ; y = b; }
};

int DP[16][(1 << 16)];
char bord[25][25];
node me;
vector < node > ve;
int len ;
int dis(const node &a , const node &b)
{
    int ans = max( Abs(a.x - b.x) , Abs(a.y - b.y) );
    return ans;
}

int call(int pos , int mark , node temp)
{
    if(mark == (1 << len) - 1) return dis(temp , me);
    int &ret = DP[pos][mark];
    if(ret != -1) return ret;
    ret = (1 << 10);
    for(int i = 0 ; i < len ; ++i)
    {
        if((mark & (1 << i)) == 0)
        {
            ret = min(ret , call(i , (mark | (1 << i)), ve[i]) + dis(temp , ve[i]));
        }
    }
    return ret;
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false); cin.tie(false);
    int n , m ;
    while( cin >> n >> m )
    {
        for(int i = 0 ; i < n ; ++i) for(int j = 0 ; j < m ; ++j)
        {
            cin >> bord[i][j];
            if(bord[i][j] == 'L') me = node(i , j);
            else if(bord[i][j] == '#') ve.push_back(node(i , j));
        }
        memset(DP , -1 , sizeof(DP));
        len = ve.size();
        cout << call(0 , 0 , me) << endl;
        ve.clear();
    }
    return 0;
}
