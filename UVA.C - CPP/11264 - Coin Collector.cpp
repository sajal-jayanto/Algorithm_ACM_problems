#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

long long ar[1010];

int main()
{
    int t , n  , cnt ;
    long long sum ;
    sf("%d" , &t);
    while(t--)
    {
        cnt = 1 ;
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i) sf("%lld" , &ar[i]);
        sum = ar[0];
        for(int i = 1 ; i < n - 1 ; ++i)
        {
            if(sum + ar[i] < ar[i + 1])
            {
                sum = sum + ar[i];
                ++cnt;
            }
        }
        ++cnt;
        pf("%d\n" , cnt);
    }
    return 0;
}
