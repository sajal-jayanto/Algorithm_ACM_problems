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
#define MAX             1000000
#define MAXR            32000
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;


///***************************************  END  **********************************************///

int ar[MAX + 2];
int main()
{
    int one , two , three;
    ar[0] = 1;
    for(int i = 1 ; i <= MAX ; ++i)
    {
        one = i - sqrt(i);
        two = log(i);
        three = i * sin(i) * sin(i);
        ar[i] = ((ar[one] % MAX) + (ar[two] % MAX) + (ar[three] % MAX)) % MAX;
    }
    while(sf("%d" , &one) && one != -1) pf("%d\n", ar[one]);
    return 0;
}
