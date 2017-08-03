#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

int num[10010];
int cnt[10010];

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int  b , c, m , n , sum , ans , cc = 0;
    int t;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d %d %d %d" , &num[0] , &b , &c  , &m , &n);
        for(int i = 1 ; i < n  ; ++i)
        {
            num[i] = ((num[i - 1] * b + c) % m) + 1;
        }
        memset(cnt , 0 , sizeof(cnt));
        sum = 0 , ans = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            sum = (sum + num[i]) % m ;
            ans = ans + cnt[sum];
            if(sum == 0) ans++;
            cnt[sum]++;
        }
        pf("Case %d: %d\n" , ++cc , ans);
    }
    return 0;
}
