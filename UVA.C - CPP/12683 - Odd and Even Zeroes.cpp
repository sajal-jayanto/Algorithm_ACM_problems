#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

int dig[30];
long long dp[30][2][2];
bool vis[30][2][2];

int zero(long long num)
{
    int cnt = 0;
    while(num >= 5ll)
    {
        cnt = cnt + (num / 5ll);
        num = num / 5ll;
        cnt = cnt % 2;
    }
    return cnt;
}

long long big_mod(int num , int p )
{
    long long sum = 1 , temp = num;
    while(p)
    {
        if(p & 1) sum = (sum * temp);
        temp = (temp * temp) ;
        p = p >> 1;
    }
    return sum;
}

long long call(int pos , int cnt , int flag)
{
    if(pos == -1) return (cnt == 0);
    long long &ans = dp[pos][cnt][flag];
    if(vis[pos][cnt][flag] == true) return ans;
    int k = flag ? dig[pos] : 4;
    ans = 0;
    for(int i = 0 ; i <= k ; ++i)
    {
        ans = ans + call(pos - 1 , (cnt + zero(big_mod(5 , pos) * 1ll * i)) % 2 , flag && (i == k));
    }
    vis[pos][cnt][flag] = true;
    return ans;
}

long long pro(long long num)
{
    if(num <= 0) return 1;
    memset(vis , false , sizeof(vis));
    int len = 0;
    while(num)
    {
        dig[len++] = num % 5;
        num = num / 5;
    }
    return call(len - 1 , 0 , 1);
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    long long num;
    while(sf("%lld" , &num) && num != -1)
    {
        pf("%lld\n" , pro(num));
    }
    return 0;
}
