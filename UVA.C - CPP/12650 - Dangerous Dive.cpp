
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
#define MAX             500
#define MAXR            100
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;


///***************************************  END  **********************************************///



int main()
{
    bool ar[10000] , flag ;
    int n , m , temp ;
    while(sf("%d %d", &n , &m) == 2)
    {
        mem(ar , false);
        flag = false;
        for(int i = 0 ; i < m ; ++i)
        {
            sf("%d", &temp);
            ar[temp] = true;
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            if(!ar[i]) pf("%d ", i);
        }
        if(n == m) pf("*");
        pf("\n");
    }
    return 0;
}
