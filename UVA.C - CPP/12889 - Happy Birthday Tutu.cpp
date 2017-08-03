#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>

using namespace std;

#define _pair(x,y) make_pair(x,y)
#define sf scanf
#define pf printf
#define INF (1<<30)
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double eps = 1e-11;
const int save[10][4] = {{0},{0},{6,2,4,8},{1,3,9,7},{6,4},{0},{0},{1,7,9,3},{6,8,4,2},{1,9}};
int todigit(char c) { return ( isdigit(c) ) ?( c - 48 ) : c ; }
int toint(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }
ll tolong(string s) {  ll r = 0; istringstream sin(s); sin >> r; return r; }
double todouble(string s) { double r = 0.0 ; istringstream sin(s); sin >> r; return r; }
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > T Abs(T x) { return x > 0 ? x : -x;}
template < class T > T power(T N , T P) { return (P == 0) ?  1 : N * power(N , P - 1); }
//template < class T > void max(T &a, T b) { if(a < b) a = b; }
//template < class T > void min(T &a, T b) { if(b < a) a = b; }
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}
template < class T > inline T lcm(T a,T b) {if(a < 0) return lcm(-a,b); if(b < 0)return lcm(a,-b); return a * (b / gcd(a , b));}
ll big_mod(ll n , ll  p , ll m)
{
	ll sum;
	if(!p) return 1;
	if(p % 2 == 0) { sum = big_mod(n  , p / 2 , m); return ((sum % m ) *(sum % m)) % m; }
	else return (( n % m) * (big_mod( n , p - 1 , m) % m ))% m;
}
int one[]={1,0,-1,0}; //4 Direction
int two[]={0,1,0,-1}; //4 Direction
///int one[]={1,1,0,-1,-1,-1,0,1}; //8 direction
///int two[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int one[]={2,1,-1,-2,-2,-1,1,2}; //Knight Direction
///int two[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

int main()
{
    int t , a , b , mx , mn;
    sf("%d" , &t);
    while(t--)
    {
        mx = -1;
        mn = INF;
        sf("%d" , &a);
        while(a--)
        {
            sf("%d" , &b);
            mx = max(mx , b);
            mn = min(mn , b);
        }
        if(mx == mn) pf("Better luck next time!\n");
        else pf("Happy Birthday Tutu!\n");
    }
    return 0;
}
