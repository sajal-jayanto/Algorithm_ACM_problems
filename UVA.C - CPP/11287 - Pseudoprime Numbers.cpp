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
#define MAX             100100
#define MAXR            9598
#define MAXC            10000LL
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

ll bigmod (ll a, ll p, ll m )
{
    ll res = 1, x = a % m;
    while(p)
    {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

bool siv[MAX];
ll prime[MAXR];
void is_prime()
{
    int k = 0;
    int n = sqrt(MAX);
    prime[k++] = 2LL;
    for(int i = 3LL ; i < n ; i += 2LL) if(!siv[i]) for(int j = i * i ; j < MAX ; j += (2LL * i)) siv[j] = true;
    for(int i = 3LL ; i < MAX ; i += 2LL) if(!siv[i]) prime[k++] = i;
}

bool prime_or_not(int n)
{
    ll k = sqrt(n);
    for(int i = 0 ; prime[i] <= k; ++i) if(n % prime[i] == 0) return false;
    return true;
}

//int one[]={1,0,-1,0}; //4 Direction
//int two[]={0,1,0,-1}; //4 Direction
//int two[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int one[]={2,1,-1,-2,-2,-1,1,2}; //Knight Direction
//int two[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

///***************************************  END  **********************************************///


int main()
{
    is_prime();
    long long n , t;
    while(sf("%lld %lld" , &n , &t) && (n || t))
    {
        if(prime_or_not(n) || bigmod(t , n , n) != t) pf("no\n");
        else pf("yes\n");
    }
    return 0;
}
