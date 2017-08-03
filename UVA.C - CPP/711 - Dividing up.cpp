#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

int num[8] , cc = 0;
int DP[8][60000 + 10];
bool call(int pos , int sum)
{
    if(!sum) return true;
    if(pos > 6) return false;
    int &ret = DP[pos][sum];
    if(ret != -1) return false;
    ret = 0;
    for(int i = 1 ; i <= num[pos] ; ++i)
    {
        if(sum - (i * pos) >= 0) ret = call(pos + 1 , sum - (i * pos));
        if(ret) return true;
    }
    ret = call(pos + 1 , sum);
    if(ret) return true;
    return false;
}

int main()
{
//    freopen("input.txt" , "r"  , stdin);
//    freopen("output.txt" , "w"  , stdout);
    int sum ,lim ;
    while(true)
    {
        sum = 0;
        for(int i = 1 ; i <= 6 ; ++i)
        {
            sf("%d" , &num[i]);
            sum = sum + (num[i] * i);
        }
        if(sum == 0) return 0;
        pf("Collection #%d:\n" , ++cc);
        if(sum & 1) pf("Can't be divided.\n");
        else
        {
            lim = sum >> 1;
            memset(DP , -1 , sizeof(DP));
            if(call(1 , lim) == 0 ) pf("Can't be divided.\n");
            else pf("Can be divided.\n");
        }
        pf("\n");
    }
    return 0;
}
