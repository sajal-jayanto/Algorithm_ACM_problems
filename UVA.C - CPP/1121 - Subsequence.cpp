#include <bits/stdc++.h>

using namespace std;

#define pf printf
#define sf scanf

long long num[100010];
long long total[100010];

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int n , low , high , mid , ans ;
    long long sum;
    while(sf("%d %lld" , &n , &sum) == 2)
    {
        ans = n;
        num[0] = total[0] = 0;
        for(int i = 1 ; i <= n ; ++i) sf("%lld", &num[i]);
        for(int i = 1 ; i <= n ; ++i) total[i] = total[i - 1] + num[i];
        if(total[n] < sum)
        {
            pf("0\n");
            continue ;
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            low = i , high = n  , mid ;
            while(low <= high)
            {
                mid = ( low + high ) >> 1;
                if((total[mid] - total[i - 1]) >= sum)
                {
                    ans = min(ans , (mid - i) + 1);
                    high = mid - 1;
                }
                else low = mid + 1;
            }
        }
        pf("%d\n" , ans);
    }
    return 0;
}
