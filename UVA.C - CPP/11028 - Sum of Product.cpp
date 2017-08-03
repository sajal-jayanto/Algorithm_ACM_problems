#include <bits/stdc++.h>

using namespace std;

#define pf printf
#define sf scanf

int main()
{
    int ar[] =
    {1, 1, 1, 3, 8, 21, 43, 69, 102, 145,
    197, 261, 336, 425, 527, 645, 778, 929, 1097, 1285,
    1492, 1721, 1971, 2245, 2542, 2865, 3213, 3589};
    int n , cc = 0;
    while(sf("%d" , &n) && n)
    {
        pf("Case #%d: %d\n" , ++cc , ar[n - 1]);
    }
    return 0;
}
