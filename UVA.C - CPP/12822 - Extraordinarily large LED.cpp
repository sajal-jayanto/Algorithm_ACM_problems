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
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             100000
#define MAXR            100000
#define MAXC            100000


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

///int one[]={1,0,-1,0}; //4 Direction
///int two[]={0,1,0,-1}; //4 Direction
///int one[]={1,1,0,-1,-1,-1,0,1}; //8 direction
///int two[]={0,1,1,1,0,-1,-1,-1}; //8 direction
///int one[]={2,1,-1,-2,-2,-1,1,2}; //Knight Direction
///int two[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction

///***************************************  END  **********************************************///
map < int , int > dig;
void made_dig();
int main()
{
    #ifdef org
        //freopen("input.txt", "r" , stdin);
	//freopen("output.txt", "w" , stdout);
    #endif // org
    made_dig();
    int a , b , c, x, home , guest, home_sc, guest_sc, ans, cc = 0;
    char str[1000];
    char k[100];
    while(gets(str))
    {
        home_sc = 0; guest_sc = 0; ans = 0;
        sscanf(str , "%s %d:%d:%d",k, &a , &b, &c);
        home = guest = (((a * 60) + b) * 60) + c;
        while(gets(str))
        {
            sscanf(str , "%s" , k);
            if(!strcmp(k , "END"))
            {
                sscanf(str , "%s %d:%d:%d", k , &a , &b , &c);
                int temp = (((a * 60) + b) * 60) + c;
                ans = ans  + ((temp - home) * dig[home_sc]);
                home_sc = home_sc + x;
                ans = ans  + ((temp - guest) * dig[guest_sc]);
                guest_sc = guest_sc + x;
                break;
            }
            sscanf(str , "%s %d:%d:%d %s %d", k , &a , &b , &c, k , &x);
            if(!strcmp(k , "home"))
            {
                int temp = (((a * 60) + b) * 60) + c;
                ans = ans  + ((temp - home) * dig[home_sc]);
                home_sc = home_sc + x;
                home = temp;
            }
            else
            {
                int temp = (((a * 60) + b) * 60) + c;
                ans = ans  + ((temp - guest) * dig[guest_sc]);
                guest_sc = guest_sc + x;
                guest = temp;
            }
        }
        pf("Case %d: %d\n",++cc , ans);
    }
    return 0;

}

void made_dig()
{
    dig[0] = 6 ; dig[1] = 2 ; dig[2] = 5; dig[3] = 5;
    dig[4] = 4 ; dig[5] = 5 ; dig[6] = 6; dig[7] = 3;
    dig[8] = 7 ; dig[9] = 6 ;
    for(int i = 10 ; i < 1010 ; ++i)
    {
        int temp = i;
        while(temp)
        {
            dig[i] = dig[i] + dig[temp % 10];
            temp = temp / 10;
        }
    }
}
