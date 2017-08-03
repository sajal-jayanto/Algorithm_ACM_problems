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
#define MAX             10000010
#define MAXR            664580
#define MAXC            11

bool sive[MAX];
long long prime[MAXR];
long long num[MAX];
int k = 0;
void is_prime()
{
    int  n ;
    n = sqrt(MAX);
    for(int i = 3 ; i <= n ; i = i + 2)
    {
        if(!sive[i]) for(int j = i * i ; j < MAX ; j = j + (2 * i)) sive[j] = true;
    }
    for(long long i = 3 ; i < MAX ; i = i + 2)
    {
         if(!sive[i]){  prime[k++] = i , num[i] = 1; }
         num[i + 1] = (num[i] += num[i - 1]);
    }
}

long long call(long long n)
{
    long long temp , ans = 0;
    for(int i = 0 ; i < k && prime[i] < n ; ++i)
    {
        temp = n - prime[i];
        if(temp >= prime[i]) ans = ans + (num[temp] - 1);
        else ans = ans + num[temp];
    }
    return ans / 2;
}

int main()
{
    freopen("input.txt" , "r" , stdin);
    is_prime();
    long long n , m ;
    while(sf("%lld %lld" , &n , &m) && (n || m))
    {
        pf("%lld\n" , call(m) - call(n - 1));
    }
    return 0;
}
