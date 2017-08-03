#include <bits/stdc++.h>

using namespace std;


#define sf scanf
#define pf printf

int dp[1010][1010];
char one[1010] , two[1010];

bool call(int cost , int len)
{
    for(int i = 1 ; i <= len ; ++i)
    {
        for(int j = 1 ; j <= len ; ++j)
        {
            if(abs(one[i] - two[j]) <= 1) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = 0;
            if(dp[i][j] >= cost) return true;
        }
    }
    return false;
}

int main()
{
    //freopen("tem.txt" , "r" , stdin);
    int t , n , temp ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        sf("%s" , one + 1);
        sf("%s" , two + 1);
        temp = (n / 2) + n % 2;
        memset(dp , 0 , sizeof(dp));
        if(call(temp , n)) pf("POSITIVE\n");
        else pf("NEGATIVE\n");
    }
    return 0;
}