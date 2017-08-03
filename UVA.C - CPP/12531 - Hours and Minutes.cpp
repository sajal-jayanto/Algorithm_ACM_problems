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

using namespace std;

int main()
{
    int t;
    while(scanf("%d",&t) == 1)
    {
        if(t % 6 == 0) printf("Y");
        else printf("N");
        printf("\n");
    }
    return 0;
}
