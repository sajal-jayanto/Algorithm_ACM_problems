#include <bits/stdc++.h>


using namespace std;

#define sf scanf
#define pf printf

char str[5100];
int dp[5010][5010];

int call(int s , int e)
{
    if(s >= e) return 0;
    int &ret = dp[s][e];
    if(ret != -1) return ret;
    if(str[s]  == str[e]) ret = call(s + 1 , e - 1);
    else ret = min(call(s + 1 , e) + 1 , call(s , e - 1) + 1);
    return ret;
}


int main()
{
//    freopen("input.txt" , "r" , stdin);
    int len ;
    sf("%d" , &len);
    sf("%s" , str);
    memset(dp , -1 , sizeof(dp));
    pf("%d\n" , call(0 , len - 1));

    return 0;
}
