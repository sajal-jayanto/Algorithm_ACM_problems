#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define base 23

typedef vector < int > VI ;

int dis[30];
int len , p[12];
int dp[20][60000][2];
int path[20][60000][2];
long long num ;

VI to_ternary(int mask)
{
    vector < int > ve(10);
    int pos = 0;
    while(mask)
    {
        ve[pos++] = mask % 3;
        mask = mask / 3;
    }
    return ve;
}

int call(int pos , int mask , int flag)
{
    if(pos >= len) return 1;
    int &ret = dp[pos][mask][flag];
    if(ret != -1) return ret;
    ret = 0;
    VI can = to_ternary(mask);
    int lim = flag ? 9 : dis[pos];
    for(int i = lim ; i >= 0 ; i--)
    {
        if(!i && !mask)
        {
            ret = call(pos + 1 , mask , flag | (i < lim));
            if(ret) path[pos][mask][flag] = i;
            return ret;
        }
        else if(can[i] < 2)
        {
            ret = call(pos + 1 , mask + p[i] , flag | (i < lim));
            if(ret)
            {
                path[pos][mask][flag] = i;
                return ret;
            }
        }
    }
    return ret;
}

void print(int pos , int mask , int flag)
{
    if(pos >= len) return ;
    int lim = flag ? 9 : dis[pos];
    int in = path[pos][mask][flag];
    if(!in && !mask)
    {
        print(pos + 1 , mask , flag | (in < lim));
        return ;
    }
    num = (num * 10) + in;
    print(pos + 1 , mask + p[in] , flag | (in < lim));
}

int main()
{
    p[0] = 1;
    for(int i = 1 ; i < 11 ; ++i) p[i] = p[i - 1] * 3;
    char str[30];
    while(sf("%s" , str) == 1)
    {
        len = strlen(str);
        for(int i = 0 ; i < len ; ++i) dis[i] = str[i] - '0';
        memset(dp , -1 , sizeof(dp));
        call(0 , 0 , 0);
        num = 0;
        print(0 , 0 , 0);
        pf("%lld\n" , num);
    }
    return 0;
}
