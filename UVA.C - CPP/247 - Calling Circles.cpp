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
#define MAX             10010
#define MAXR            205
#define MAXC            5
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


void DFS( int n );
void DFS_VIS(int n);
void DFS1(int n);
void DFS_VIS1(int n);
void clear();

map < string , int > mp;
map < int , string > mp1;
vector < int > temp;
vector < int > g[30];
vector < int > rg[30];
vector < int > ans[30];
char color[30];
int cnt;

int main()
{
   // freopen("in.txt" , "r" , stdin);
    int n , m , len , cc = 0;
    string a , b;
    while(sf("%d %d" , &n , &m) && (n || m))
    {
        len = 0;
        for(int i = 0 ; i < m ; ++i)
        {
            cin >> a >> b;
            if(!mp[a])
            {
                len++;
                mp[a] = len ;
                mp1[len] = a;
            }
            if(!mp[b])
            {
                len++;
                mp[b] = len ;
                mp1[len] = b;
            }
            g[ mp[a] ].push_back(mp[b]);
            rg[ mp[b] ].push_back(mp[a]);
        }
        cnt = 0;
        DFS(n);
        DFS1(n);
        if(cc) pf("\n");
        pf("Calling circles for data set %d:\n" , ++cc);
        for(int i = 0 ; i < cnt ; ++i)
        {
            len = ans[i].size();
            if(len)
            {
                for(int j = 0 ; j < len ; ++j)
                {
                    pf("%s" , mp1[ans[i][j]].c_str());
                    if(j < len - 1) pf(", ");
                }
                pf("\n");
            }
        }
        clear();
    }
    return 0;
}

void clear()
{
    mp.clear();
    mp1.clear();
    temp.clear();
    for(int i = 0 ; i < 30 ; ++i)
    {
        g[i].clear();
        rg[i].clear();
        ans[i].clear();
    }
}

void DFS( int n )
{
    for(int i = 1 ; i <= n ; ++i) color[i] = 'w';
    for(int i = 1 ; i <= n ; ++i)
    {
        if(color[i] == 'w') DFS_VIS(i);
    }
}

void DFS_VIS(int n)
{
    color[n] = 'g';
    int len = g[n].size();
    for(int i = 0 ; i < len ; ++i)
    {
        if(color[ g[n][i] ] == 'w') DFS_VIS( g[n][i] );
    }
    color[n] = 'b';
    temp.push_back(n);
}

void DFS1(int n)
{
    for(int i = 1 ; i <= n ; ++i) color[i] = 'w';
    for(int i = temp.size() - 1 ; i >= 0 ; i--)
    {
        if(color[temp[i]] == 'w')
        {
            ans[cnt].push_back(temp[i]);
            DFS_VIS1(temp[i]);
            ++cnt;
        }
    }
}

void DFS_VIS1(int n)
{
    color[n] = 'g';
    int len = rg[n].size();
    for(int i = 0 ; i < len ; ++i)
    {
        if(color[ rg[n][i] ] == 'w')
        {
            ans[cnt].push_back(rg[n][i]);
            DFS_VIS1( rg[n][i] );
        }
    }
    color[n] = 'b';
}
