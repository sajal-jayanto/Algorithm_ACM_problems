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
    int a , b , g;
    node(){}
    node(int x , int y) {a = x; b = y;}
};

node extendedEuclid(int a, int b)
{
    int x = 1, y = 0;
    node temp = node(0, 1);
    temp.g = b ;
    int q, r, m, n;
    while(a != 0)
    {
        q = b / a;
        r = b % a;
        m = temp.a - q * x;
        n = temp.b - q * y;
        temp = node(x , y);
        x = m, y = n;
        b = a, a = r;
        temp.g = b;
    }
    return temp;
}

int main()
{
    int a , b;
    while(sf("%d %d" , &a , &b) != EOF)
    {
        node ans = extendedEuclid(a , b);
        if(a == b) pf("%d %d %d\n" ,ans.b , ans.a , ans.g);
        else pf("%d %d %d\n" ,ans.a , ans.b , ans.g);
    }
    return 0;
}
