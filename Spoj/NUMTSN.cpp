#include <bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

int num[60];
long long dp[52][52][52][52];
bool vis[52][52][52][52];
long long mod = 1000000007ll;

long long call(int pos , int three , int six , int nine , int flag)
{
    if(pos == 0)
    {
        if(three && three == six && three == nine) return 1;
        return 0;
    }
    if(!flag && vis[pos][three][six][nine]) return dp[pos][three][six][nine];
    int n = flag ? num[pos] : 9;
    long long ans = 0;
    for(int i = 0 ; i <= n ; ++i)
    {
        ans = ans + call(pos - 1 , three + (i == 3) , six + (i == 6) , nine + (i == 9) , flag && (i == n));
        ans = ans % mod;
    }
    if(!flag)
    {
        vis[pos][three][six][nine] = true;
        dp[pos][three][six][nine] = ans;
    }
    return ans;
}


long long pro(char *str)
{
    int len = 0;
    for(int i = strlen(str) - 1 ; i >= 0 ; --i)
    {
        num[++len] = (str[i] - '0');
    }
    return call(len , 0 , 0 , 0 , 1);
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , len , sum ,x , y , carry ;
    char str[60] , temp[60];
    long long a , b ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%s" , str);
        len = strlen(str);
        temp[len - 1] = '1';
        for(int i = len - 2 ; i >= 0 ; i--) temp[i] = '0';
        carry = 0;
        for(int i = len - 1 ; i >= 0 ; i--)
        {
            x = ( str[i] - '0');
            y = (temp[i] - '0') + carry;
            if(x < y)
            {
                sum = (x + 10) - y;
                carry = 1;
                str[i] = sum + '0';
            }
            else
            {
                carry = 0;
                sum = x - y;
                str[i] = sum + '0';
            }
        }
        a = pro(str);
        sf("%s" , str);
        b = pro(str);
        a = b - a;
        if(a < 0) a = a + mod;
        pf("%lld\n\n" , a);
    }
    return 0;
}
