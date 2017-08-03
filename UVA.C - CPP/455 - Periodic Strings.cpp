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
#define MAXR            1000005
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;


///***************************************  END  **********************************************///

bool fin(string str , int i , int len);

int main()
{
    int t , len;
    string str;
    sf("%d", &t);
    while(t--)
    {
        cin >> str;
        len = str.length();
        for(int i = 1 ; i <= len ; ++i)
        {
            if(fin(str , i , len)){ pf("%d\n", i);  break; }
        }
        if(t) pf("\n");
    }
    return 0;
}

bool fin(string str , int i , int len)
{
    if(len % i != 0) return false;
    for(int j = 0 ; j < i ; ++j) for(int k = j + i ; k < len  ; k = k + i) if(str[j] != str[k]) return false ;
    return true;
}
