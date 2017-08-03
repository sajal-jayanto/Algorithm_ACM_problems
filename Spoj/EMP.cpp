#include <bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    unsigned long long n , m , ans ;
    while(sf("%llu %llu" , &n , &m) == 2)
    {
        if(n <= 0 || m < 0) ans = 0;
        else ans = n + m;
        pf("%llu\n" , ans);
    }
    return 0;
}
