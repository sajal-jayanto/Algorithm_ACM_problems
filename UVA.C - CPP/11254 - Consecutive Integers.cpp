#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

int main()
{
   // freopen("input.txt"  , "r" , stdin);
//    freopen("input.txt"  , "r" , stdin);
    long long n;
    long long pos , pos2 , x , y ;
    while(sf("%lld" , &n) && n != -1)
    {
        n = n * 2;
        for(int i = 1 ; i * i < n ; ++i)
        {
            if(n % i) continue ;
            pos = i + n / i;
            if(pos % 2 == 0) continue;
            x = (pos - 1) / 2;
            y = x - i;
        }
        pf("%lld = %lld + ... + %lld\n" , n / 2 , y + 1 , x);
    }
    return 0;
}
