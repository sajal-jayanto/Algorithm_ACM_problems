#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

template < class T > inline T gcd(T a,T b) { return (b == 0) ? a : gcd(b ,a % b); }
template < class T > inline T lcm(T a,T b) { return a * (b / gcd(a , b)); }

long long ar[20];
long long n , k , ans ;

void call(int pos , int take , long long have)
{
    if(have > n) return ;
    if(pos >= k)
    {
        if(take & 1) ans = ans + (n / have);
        else if(take) ans = ans - (n / have);
        return ;
    }
    call(pos + 1 , take + 1 , lcm(have , ar[pos]));
    call(pos + 1 , take , have);
}

int main()
{
    sf("%lld %lld" , &n , &k);
    ans = 0;
    for(int i = 0 ; i < k ; ++i) sf("%lld" , &ar[i]);
    call(0 , 0 , 1ll);
    pf("%lld\n" , n - ans);
    return 0;
}
