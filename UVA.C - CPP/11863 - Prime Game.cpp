#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define MAX 1200000

bool sieve[MAX];
int ar[105] , cc = 0;
int dp[105][105];

void is_prime()
{
    int k = sqrt(MAX);
    for(int i = 4 ; i < MAX ; i = i + 2) sieve[i] = true;
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sieve[i]) for(int j = i * i ; j < MAX ; j = j + (2 * i)) sieve[j] = true;
    }
    sieve[0] = sieve[1] = true;
}

int call(int left , int right)
{
    if(left == right) return 0;
    int &ret = dp[left][right];
    if(ret != -1) return ret;
    ret = 0;
    int sum = 0;
    for(int i = left ; i < right ; ++i)
    {
        sum = sum + ar[i];
        if(sum > 0 && !sieve[sum]) { ret = ret || !call(i + 1 , right); }
    }
    sum = 0;
    for(int i = right - 1 ; i >= left ; --i)
    {
        sum = sum + ar[i];
        if(sum > 0 && !sieve[sum]) { ret = ret || !call(left , i); }
    }
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    is_prime();
    bool flag ;
    int t , n , k , ca = 0;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &n , &k);
        flag = false;
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%d" , &ar[i]);
            if(!flag && ar[i] == 42) flag = true;
        }
        if(flag) pf("Case %d: Soha\n" , ++ca);
        else
        {
            memset(dp , -1 , sizeof(dp));
            if(call(0 , n)) pf("Case %d: Soha\n" , ++ca);
            else pf("Case %d: Tara\n" , ++ca);
        }
    }
    return 0;
}
