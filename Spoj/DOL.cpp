#include <bits/stdc++.h>


#define sf scanf
#define pf printf
#define MAX 87000000

using namespace std;


int main()
{
    int t , cc = 0;
    long long num;
    sf("%d" , &t);
    while(t--)
    {
        sf("%lld" , &num);
        while(num % 2 == 0) num = num / 2;
        pf("Case %d: %lld\n" , ++cc , num);
    }
    return 0;
}
