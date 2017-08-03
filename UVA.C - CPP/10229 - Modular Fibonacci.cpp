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
#define MAX             12
#define MAXR            1000005
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
const double PI = 2.0 * acos(0.0);
const double eps = 1e-11;
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

//ll big_mod(ll n , ll  p , ll m)
//{
//  ll sum;
//  if(!p) return 1;
//  if(p % 2 == 0) { sum = big_mod(n  , p / 2 , m); return ((sum % m ) *(sum % m)) % m; }
//  else return (( n % m) * (big_mod( n , p - 1 , m) % m ))% m;
//}

// bool siv[MAX];
// int prime[MAX];
//void is_prime()
//{
//    int k = 0;
//    int n = sqrt(MAX);
//    prime[k++] = 2;
//    for(int i = 3 ; i < n ; i += 2) if(!siv[i]) for(int j = i * i ; j < MAX ; j += (2 * i)) siv[j] = true;
//    for(int i = 3 ; i < MAX ; i += 2) if(!siv[i]) prime[k++] = i;
//}
//
//int one[]={1,0,-1,0}; //4 Direction
//int two[]={0,1,0,-1}; //4 Direction
//int two[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int one[]={2,1,-1,-2,-2,-1,1,2}; //Knight Direction
//int two[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

///***************************************  END  **********************************************///

struct matrix{

    ll mat[2][2];
};
ll mod;

matrix matrix_expo(matrix temp , long long p);
matrix matrix_mult(matrix a , matrix b);

int main()
{
    ll n , p , ans;
    matrix temp;
    while(sf("%lld %lld" , &n , &p) == 2)
    {
        mod = power(2ll , p);
        if(n <= 5)
        {
            ll ar[10];
            ar[0] = 0 ;ar[1] = 1; ar[2] = 1;
            for(int i = 3 ; i <= 6 ; ++i) ar[i] = ar[i - 1] + ar[i - 2];
            pf("%lld\n" , ar[n] % mod);
            continue;
        }
        temp.mat[0][0] = 1;
        temp.mat[0][1] = 1;
        temp.mat[1][0] = 1;
        temp.mat[1][1] = 0;
        temp = matrix_expo(temp , n - 2);
        ans = ((temp.mat[0][0] % mod) + (temp.mat[0][1] % mod)) % mod;
        pf("%lld\n" , ans);
    }
    return 0;
}


matrix matrix_expo(matrix temp , long long p)
{
    if(p == 1) return temp;
    if(p % 2) return matrix_mult(temp , matrix_expo(temp , p - 1));
    else
    {
        matrix ret = matrix_expo(temp , p >> 1);
        return matrix_mult(ret , ret);
    }
}

matrix matrix_mult(matrix a , matrix b)
{
    matrix ret;
    for(int i = 0 ; i < 2 ; ++i)
    {
        for(int j = 0 ; j < 2 ; ++j)
        {
            ll sum = 0;
            for(int k = 0 ; k < 2 ; ++k) sum = sum + ((a.mat[i][k] % mod) * (b.mat[k][j] % mod)) % mod;
            ret.mat[i][j] = (sum % mod);
        }
    }
    return ret;
}
