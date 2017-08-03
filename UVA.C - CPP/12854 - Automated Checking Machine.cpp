
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

#define F_TO_R          freopen("input.txt", "r" , stdin)
#define _pair(x,y)      make_pair(x,y)
#define INF             (1<<30)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             500
#define MAXR            100
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
const double PI = 2.0 * acos(0.0);
const double eps = 1e-11;
const int _mod = 1000000;
const int save[10][4] = {{0},{0},{6,2,4,8},{1,3,9,7},{6,4},{0},{0},{1,7,9,3},{6,8,4,2},{1,9}};
int todigit(char c) { return ( isdigit(c) ) ?( c - 48 ) : c ; }
int toint(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }
ll tolong(string s) {  ll r = 0; istringstream sin(s); sin >> r; return r; }
double todouble(string s) { double r = 0.0 ; istringstream sin(s); sin >> r; return r; }
bool bit_check(int k , int p){ return (bool)(k&(1 << p)); }
int bit_set(int k , int p) { return k = (k|(1 << p));}
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > T Abs(T x) { return x > 0 ? x : -x;}
template < class T > T power(T N , T P) { return (P == 0) ?  1 : N * power(N , P - 1); }
template < class T > inline T max_(T a,T b) {return a > b ? a : b ;}
template < class T > inline T min_(T a,T b) {return a < b ? a : b ;}
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}
template < class T > inline T lcm(T a,T b) {if(a < 0) return lcm(-a,b); if(b < 0)return lcm(a,-b); return a * (b / gcd(a , b));}


///***************************************  END  **********************************************///



int main()
{
    int ar[12] , cnt;
    while(sf("%d %d %d %d %d" , &ar[0] , &ar[1] , &ar[2] , &ar[3] , &ar[4]) == 5)
    {
        sf("%d %d %d %d %d" , &ar[5] , &ar[6] , &ar[7] , &ar[8] , &ar[9]);
        cnt = 0;
        for(int i = 0 ; i < 5 ; ++i)
        {
            if((ar[i] == 0 && ar[i + 5] == 0 ) || (ar[i] == 1 && ar[i + 5] == 1)) ++cnt;
        }
        if(!cnt) pf("Y\n");
        else pf("N\n");
    }
    return 0;
}
