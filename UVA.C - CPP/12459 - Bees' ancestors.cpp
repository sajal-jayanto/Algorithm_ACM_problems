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

#define PI (2 *  acos(0.0))
#define eps 1e-7

#define MAX 85

using namespace std;

unsigned long long ar[MAX];


int main()
{
    int n;
    ar[0] = 1;
    ar[1] = 1;

    for(int i = 2 ; i < MAX ; i++)  ar[i] = ar[i - 1] + ar[i - 2];

    while(scanf("%d",&n) && n) printf("%llu\n",ar[n]);

    return 0;
}
