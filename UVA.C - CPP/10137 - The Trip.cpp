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
#define MAX             1010
#define MAXR            21
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}

///***************************************  END  **********************************************///

int num[MAX];
bool cmp(int a , int b) {return a < b;}

int main()
{
    int t , a, b , sum , avg , avg2 ,  ans;
    while(sf("%d", &t) && t)
    {
        sum = 0;
        for(int i = 0 ; i < t ; ++i)
        {
            sf("%d.%d", &a , &b);
            a = (a * 100) + b;
            num[i] = a;
            sum = sum + a;
        }
        sort(num , num + t, cmp);
        avg = sum / t;
        avg2 = sum % t;
        ans = 0;
        for(int i = 0 ; i < t ; ++i)
        {
            if(avg >= num[i]) ans = ans + (avg - num[i]);
            else
            {
                if(t - i < avg2) ans = ans + avg2 - (t - i);
                break;
            }
        }
        pf("$%d.%02d\n", ans / 100 , ans % 100);
    }
    return 0;
}
