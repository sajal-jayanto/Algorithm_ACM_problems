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

int ar[10] , cnt , t;
void permutation();
bool sorted();

int main()
{
    int cc = 0;
    while(sf("%d" , &t) && t)
    {
        cnt = 0;
        for(int i = 0 ; i < t ; ++i) sf("%d" , &ar[i]);
        if(!sorted()) permutation();
        pf("There are %d swap maps for input data set %d.\n" , cnt , ++cc);
    }
    return 0;
}

bool sorted()
{
    for(int i = 0 ; i < t - 1 ; ++i)
    {
        if(ar[i] > ar[i + 1]) return false;
    }
    return true;
}

void permutation()
{
    for(int i = 0 ; i < t - 1 ; ++i)
    {
        if(ar[i] > ar[i + 1])
        {
            swap(ar[i] , ar[i + 1]);
            if(sorted()) ++cnt;
            permutation();
            swap(ar[i] , ar[i + 1]);
        }
    }
}
