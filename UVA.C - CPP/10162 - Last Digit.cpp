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
#define MAX             105
#define MAXR            1000005
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

int  big_mod(int n , int  p , int m)
{
    int sum;
    if(!p) return 1;
    if(p % 2 == 0) { sum = big_mod(n  , p / 2 , m); return ((sum % m ) *(sum % m)) % m; }
    else return (( n % m) * (big_mod( n , p - 1 , m) % m ))% m;
}

///***************************************  END  **********************************************///

int save[MAX];

int main()
{
    char str[100000];
    int sum = 0 , mod = 1000 , len ;
    for(int i = 1 ; i <= 101 ; ++i)
    {
        sum = (sum % mod + big_mod(i , i , mod)) % mod;
        save[i] = sum % 10;
    }
    mod = 100;
    while(sf("%s", str) == 1)
    {
        if(!strcmp(str , "0")) break;
        len = strlen(str);
        if(len <= 3)
        {
            sum = atoi(str);
            sum = sum % mod;
        }
        else
        {
            sum = 0;
            for(int i = 0 ; i < len ; ++i)
            {
                sum = sum * 10 + (str[i] - '0');
                sum = sum % mod;
            }
        }
        pf("%d\n", save[sum]);
    }
    return 0;
}





