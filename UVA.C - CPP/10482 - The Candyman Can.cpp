#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

int ar[40] , sum , n , cc = 0;
int dp[32][650][650];
int vis[32][650][650];

int call(int pos , int one , int two)
{
    if(pos >= n)
    {
        int three = sum - (one + two);
        return max(abs(one - two) , max(abs(two - three) , abs(three - one)));
    }
    int &ret = dp[pos][one][two];
    if(vis[pos][one][two] == cc) return ret;
    ret = (1 << 30);
    ret = min(ret , min(call(pos + 1 , one + ar[pos] , two) , min(call(pos + 1 , one , two + ar[pos]) , call(pos + 1 , one , two))));
    vis[pos][one][two] = cc;
    return ret;
}

int main()
{
    freopen("input.txt" , "r" , stdin);
    int t ;
    sf("%d" , &t);
    while(t--)
    {
        sum = 0;
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i) sf("%d" , &ar[i]) , sum = sum + ar[i];
        ++cc;
        pf("Case %d: %d\n" , cc , call(0 , 0 , 0));
    }
    return 0;
}
