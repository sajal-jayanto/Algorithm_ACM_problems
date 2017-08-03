#include <bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    unsigned long long t , n , temp , sum ;
    sf("%llu" , &t);
    while(t--)
    {
        sf("%llu" , &n);
        sum = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%llu" , &temp);
            temp = temp % n;
            sum = (sum + temp) % n;
        }
        if(!sum ) pf("YES\n");
        else pf("NO\n");
    }
    return 0;
}
