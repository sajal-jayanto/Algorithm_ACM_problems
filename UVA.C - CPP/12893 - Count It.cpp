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
#define INF             (1<<28)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             55
#define MAXR            1010
#define MAXC            11
typedef long long ll;

ll num[12];
ll call(ll n);

int main()
{
    num[0] = 0;
    for(ll i = 1 ; i <= 10 ; ++i) num[i] = num[i / 2] +  (i % 2);
    int t;
    ll n;
    sf("%d", &t);
    while(t--)
    {
		sf("%lld", &n);
		pf("%lld\n", call(n));
	}
	return 0;
}


ll call(ll n)
{
	if(n < 10) return num[n];
	if(n % 2) return call(n / 2) + 1;
	return call(n / 2);
}
