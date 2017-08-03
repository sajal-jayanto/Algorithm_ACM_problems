#include <bits/stdc++.h>


using namespace std;

#define sf scanf
#define pf printf


int main()
{
    long long n ;
    sf("%lld" , &n);
    while(n % 2 == 0) n = n / 2;
    if(n == 1) pf("TAK\n");
    else pf("NIE\n");
    return 0;
}
