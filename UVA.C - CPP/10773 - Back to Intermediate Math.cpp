#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

int main()
{

    int t,count = 0;
    double d,u,v,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf",&d,&v,&u);
        if(u == 0.00 || v == 0.00 || u <= v)
        {
            printf("Case %d: can't determine\n",++count);
            continue;
        }
        a = d / u;
        b = d / sqrt((u * u) - (v * v));
        a = b - a;
        printf("Case %d: %.3lf\n",++count,a);
    }
    return 0;
}
