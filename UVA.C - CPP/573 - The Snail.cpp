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

int main()
{

    double h,u,d,f;
    while(scanf("%lf %lf %lf %lf",&h,&u,&d,&f) && h)
    {
        int i = 0;
        double n = 0.0;
        double m = (f * u) / 100.00;
        while(true)
        {
            i++;
            if(u >= 0) n = n + u;
            u = u - m;
            if(n > h) break;
            n = n - d;
            if(n < 0.00) break;
        }
        if(n > h) printf("success on day %d\n",i);
        else printf("failure on day %d\n", i);
    }

    return 0;
}
