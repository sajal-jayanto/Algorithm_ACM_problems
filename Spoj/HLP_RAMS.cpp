#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;


int main()
{
    int n;
    long long num , even , odd , total ;
    sf("%d" , &n);
    while(n--)
    {
        sf("%lld" , &num);
        if(num == 1)
        {
            pf("0 1\n");
            continue ;
        }
        total = num + 1;
        odd = 1;
        while(num)
        {
            if(num & 1) odd = odd * 2ll;
            num = num / 2;
        }
        pf("%lld %lld\n" , total - odd , odd);
    }
    return 0;
}
