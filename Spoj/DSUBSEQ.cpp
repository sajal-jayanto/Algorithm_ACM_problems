#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;


char str[100010];
int pre[26];
long long dp[100010] , mod = 1000000007 ;

int main()
{
    int t , len ;
    sf("%d" , &t);
    getchar();
    while(t--)
    {
        gets(str + 1);
        len = strlen(str + 1);
        memset(pre , 0 , sizeof(pre));
        dp[0] = 1;
        for(int i = 1 ; i <= len ; ++i)
        {
            dp[i] = (dp[i - 1] + dp[i - 1]) % mod;
            if(dp[ pre[str[i] - 'A'] ] != 0) dp[i] = dp[i] - dp[ pre[str[i] - 'A'] - 1];
            pre[str[i] - 'A'] = i;
            dp[i] = (dp[i] + mod) % mod;
        }
        pf("%lld\n" , dp[len]);
    }
    return 0;
}
