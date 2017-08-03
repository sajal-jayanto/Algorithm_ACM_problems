#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define MAX 1005

using namespace std;


int main()
{
    unsigned long long n;
    int t;
    sf("%d" , &t);
    while(t--)
    {
        sf("%llu" , &n);
        pf("%llu\n" , (n * (n + 2) * (n * 2 + 1)) / 8);
    }
    return 0;
}
