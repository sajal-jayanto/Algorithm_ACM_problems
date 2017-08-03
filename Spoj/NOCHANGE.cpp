#include <bits/stdc++.h>

using namespace std;

#define sf         scanf
#define pf         printf
#define fr         first
#define se         second
#define PI         (2 *  acos(0.0))
#define eps        1e-7
#define mem(a,b)   memset(a, b, sizeof(a))
#define ios        ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false)

bool dp[100010];
int sum[10];

int main()
{
    int m , n ;
    sf("%d %d" , &m , &n);
    for(int i = 0 ; i < n ; ++i) sf("%d" , &sum[i]);
    for(int i = 1 ; i < n ; ++i) sum[i] = sum[i] + sum[i - 1];
    mem(dp , false);
    dp[0] = true;
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = sum[i] ; j <= m ; ++j)
        {
            dp[j] |= dp[j - sum[i]];
        }
    }
    puts(dp[m] ? "YES" : "NO");
    return 0;
}
