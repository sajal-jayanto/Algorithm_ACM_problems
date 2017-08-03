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

priority_queue < int > neg;
priority_queue < int > pos;

int main()
{
    int t , n , temp , cnt , sing ;
    cin >> t;
    while(t--) {
        cnt = 0;
        cin >> n;
        while(n--) {
            cin >> temp;
            if(temp < 0) neg.push(temp);
            else pos.push(-temp);
        }
        if(abs(neg.top()) > abs(pos.top()))  {
            temp = abs(pos.top());
            pos.pop() ;
            ++cnt;
            sing = 0;
        }
        else  {
            temp = abs(neg.top());
            neg.pop();
            ++cnt;
            sing = 1;
        }
        while(true)
        {
            if(pos.empty() || neg.empty()) break;
            if(sing) {
                while(!pos.empty()) {
                    if(abs(pos.top()) > temp) {
                        ++cnt;
                        temp = abs(pos.top());
                        sing = 0;
                        break;
                    }
                    else pos.pop();
                }
            }
            else {
                while(!neg.empty()) {
                    if(abs(neg.top()) > temp) {
                        ++cnt;
                        temp = abs(neg.top());
                        sing = 1;
                        break;
                    }
                    else neg.pop();
                }
            }
        }
        cout << cnt << endl;
        while(!neg.empty()) neg.pop();
        while(!pos.empty()) pos.pop();
    }
    return 0;
}
