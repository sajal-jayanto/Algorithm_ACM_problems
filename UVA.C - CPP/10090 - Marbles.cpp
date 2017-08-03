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


struct node {
    long long a , b, g;
    node(){}
    node(long long x , long long y) {a = x; b = y;}
};
template < class T > inline T gcd(T a,T b) { if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b); }


node extendedEuclid(long long a, long long b)
{
    long long x = 1, y = 0;
    node temp = node(0 , 1);
    long long q, r, m, n;
    while(a)
    {
        q = b / a;
        r = b % a;
        m = temp.a - q * x;
        n = temp.b - q * y;
        temp = node(x , y);
        x = m, y = n;
        b = a, a = r;
    }
    return temp;
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    long long n , x , y , a, b , temp , temp1 , upx , upy , lowx , lowy;
    node ans;
    bool flag;
    while( sf("%lld" , &n) && n)
    {
        flag = false;
        sf("%lld %lld" , &x , &a);
        sf("%lld %lld" , &y , &b);
        ans.g = gcd(a , b);
        if(n % ans.g)
        {
            pf("failed\n");
            continue;
        }
        n = n / ans.g;
        ans = extendedEuclid(a / ans.g , b / ans.g);
        ans.a = (ans.a * n);
        ans.b = (ans.b * n);
        upy = (ans.b % a + a) % a;
        upx = (n - upy * b) / a;
        lowx = (ans.a % b + b) % b;
        lowy = (n - lowx * a) / b;
        temp = INF;
        if(lowy >= 0) temp = ((lowx * x) + (lowy * y)) , ans.a = lowx  , ans.b = lowy;
        if((temp > ((upx * x) + (upy * y)) || temp == INF) && upx >= 0) ans.a = upx  , ans.b = upy;
        if(temp == INF) pf("failed\n");
        else pf("%lld %lld\n" , ans.a , ans.b);
    }
    return 0;
}
