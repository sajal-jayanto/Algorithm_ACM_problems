#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf


bool chak(int n , int base)
{
    vector < int > ve;
    while(n)
    {
        ve.push_back(n % base);
        n = n / base;
    }
    int s = 0 , e = ve.size() - 1;
    while(s < e)
    {
        if(ve[s++] != ve[e--]) return false;
    }
    return true ;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int n , k , ans , d ;
    while(sf("%d" , &n) == 1)
    {
        if(n <= 2)
        {
            pf("%d\n" , n + 1);
            continue;
        }
        k = sqrt(n);
        ans = n - 1;
        for(int i = 2 ; i <= k ; ++i)
        {
            if(chak(n , i)) ans = min(ans , i);
            if(n % i == 0)
            {
                d = (n / i) - 1;
                if(d > k && chak(n , d)) ans = min(ans , d);
            }
        }
        pf("%d\n" , ans);
    }
    return 0;
}
