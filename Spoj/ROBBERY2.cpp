#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

long long ar[106];

int main()
{
//    freopen("input.txt" , "r" , stdin);
    int t  ;
    long long total , temp , n , len , low , mid , high ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%lld %lld" , &total , &n);
        low = 1ll , high = 45000000ll;
        while(low <= high)
        {
            mid = (low + high) / 2ll;
            temp = (mid * (mid + 1ll)) / 2ll;
            if(temp <= total)
            {
                len = mid;
                low = mid + 1ll;
            }
            else high = mid - 1ll;
        }
        memset(ar , 0 , sizeof(ar));
        low = len / n; high = len % n;
        low = (low * (low - 1ll)) / 2ll;
        mid = (len / n);
        temp = (mid * n) ;
        low = (low * n);
        ar[0] = low;
        for(int i = 1 ; i <= n ; ++i) ar[i] = ar[i - 1] + mid;
        for(int i = 1 ; i <= high ; ++i) ar[i] += temp + i;
        temp = total - ((len * (len + 1)) / 2);
        high++;
        ar[high] += temp;
        pf("%lld" , ar[1]);
        for(int i = 2 ; i <= n ; ++i) pf(" %lld" , ar[i]);
        pf("\n");
    }
    return 0;
}
