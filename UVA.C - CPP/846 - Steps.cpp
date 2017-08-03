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
    int a,b;
    int d,n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        d = b - a;
        n = sqrt(d);
        if(d == 0) ans = 0;
        else if(n * n == d) ans = n * 2 - 1;
        else if(n * n + n < d) ans = n * 2 + 1;
        else ans = n * 2;
        printf("%d\n",ans);
    }
    return 0;
}
