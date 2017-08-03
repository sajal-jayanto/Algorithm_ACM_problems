#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MAX 5000010

#define PI (2 *  acos(0.0))
#define eps 1e-7
bool com(long long,long long);
long long num[10010];
long long n,m;
using namespace std;


int main()
{
    while(scanf("%lld %lld",&n,&m) && (n || m))
    {
        printf("%lld %lld\n",n,m);
        for(long long i = 0 ; i < n ; i++) scanf("%lld",&num[i]);
        sort(num, num + n ,com);
        for(long long i = 0 ; i < n ; i++) printf("%lld\n",num[i]);
    }
    printf("0 0\n");
    return 0;
}
bool com(long long a, long long b)
{
    if(a % m != b % m) return a % m < b % m;
    else
    {
        if(abs(a) % 2 == 0 && abs(b) % 2 == 0) return a < b;
        if(abs(a) % 2 == 1 && abs(b) % 2 == 1) return a > b;
        if(abs(a) % 2 == 0 && abs(b) % 2 == 1) return false;
        if(abs(a) % 2 == 1 && abs(b) % 2 == 0) return true;
    }
}

