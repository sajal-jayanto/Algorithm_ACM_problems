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

#define _pair(x,y)      make_pair(x,y)
#define INF             (1<<30)
#define sf(a)           scanf("%d", &a)
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             17
#define MAXR            12
#define MAXC            102
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

//ll big_mod(ll n , ll  p , ll m)
//{
//	ll sum;
//	if(!p) return 1;
//	if(p % 2 == 0) { sum = big_mod(n  , p / 2 , m); return ((sum % m ) *(sum % m)) % m; }
//	else return (( n % m) * (big_mod( n , p - 1 , m) % m ))% m;
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

//int one[]={1,0,-1,0}; //4 Direction
//int two[]={0,1,0,-1}; //4 Direction
//int two[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int one[]={2,1,-1,-2,-2,-1,1,2}; //Knight Direction
//int two[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

///***************************************  END  **********************************************///

int grid[MAXR][MAXC];
int DP[MAXR][MAXC];
int r , c;
int call(int n , int m);
void print_path(int n);
int now(int n);

int main()
{
    #ifdef non
        freopen("input.txt", "r" , stdin);
    #endif // non
    int ans, pos;
    while(scanf("%d %d", &r , &c) == 2)
    {
        ans = INF;
        for(int i = 0 ; i < r ; ++i) for(int j = 0 ; j < c ; ++j) { sf(grid[i][j]);  DP[i][j] = -1; }

        for(int i = 0 ; i < r ; ++i)
        {
            int temp = call(i , 0);
            if(ans > temp)
            {
                ans = temp;
                pos = i;
            }
        }
        //for(int i = 0 ; i < r ; ++i) { for(int j = 0 ; j < c ; ++j) printf("%d ", DP[i][j]); printf("\n"); }
        print_path(pos);
        printf("%d\n", ans);
    }
    return 0;
}
void print_path(int n)
{
    printf("%d",n + 1);
    for(int i = 1 ; i < c ; ++i)
    {
        int one = DP[now(n - 1)][i];
        int two = DP[n][i];
        int three = DP[now(n + 1)][i];
        if(one < two && one < three) n = now(n - 1);
        else if(three < one && three < two) n = now(n + 1);
        else if(two < one && two < three) n = n;
        else if(one == two && one < three) n = min_(now(n - 1) , n);
        else if(one == three && one < two) n = min_(now(n - 1) , now(n + 1));
        else if(two == one && two < three) n = min_(n , now(n - 1));
        else if(two == three && two < one) n = min_(n , now(n + 1));
        else if(three == one && three < two) n = min_(now(n + 1) , now(n - 1));
        else if(three == two && three < one) n = min_(now(n + 1) , n);
        else n = min_(now(n - 1) , min_ ( n , now(n + 1)));
        printf(" %d", n + 1);
    }
    printf("\n");
}
int now(int n)
{
    if(n == -1) n = r - 1;
    else if(n == r) n = 0;
    return n;
}
int call(int n , int m)
{
    if(m == c) return 0;
    if(n == r) n = 0;
    if(n == -1) n = r - 1;
    int &ret = DP[n][m];
    if(ret != -1) return ret;
    ret = INF;
    ret = min_(ret , grid[n][m] + call(n - 1 , m + 1));
    ret = min_(ret , grid[n][m] + call(n , m + 1));
    ret = min_(ret , grid[n][m] + call(n + 1 , m + 1));
    return ret;
}
