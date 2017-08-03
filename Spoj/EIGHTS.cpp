#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

int ar[] = { 942 , 192 , 442 , 692 };

int main()
{
    long long k , mod ;
    int t;
    sf("%d" , &t);
    while(t--)
    {
        sf("%lld" , &k);
        if(k <= 4)
        {
            pf("%d\n" , ar[k % 4]);
            continue ;
        }
        mod = k % 4ll;
        if(!mod) pf("%lld%d\n" , (k / 4) - 1 , ar[0]);
		else pf("%lld%d\n" , (k / 4)  , ar[mod]);
    }
    return 0;
}
