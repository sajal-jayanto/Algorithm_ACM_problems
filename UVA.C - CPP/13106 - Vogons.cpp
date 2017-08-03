#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int ar[310][310];
int temp[310];
int te[310];
int dp[310];

int call(int pos , int *arr , int len)
{
    if(pos >= len) return 0;
    int &ret = dp[pos];
    if(ret != -1) return ret;
    ret = max(arr[pos] + call(pos + 2 , arr , len) , call(pos + 1 , arr , len));
    return ret;
}

int main()
{
//    freopen("input.txt" , "r" , stdin);
    int n , m , ans ;
    while(sf("%d %d" , &n , &m) == 2)
    {
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                sf("%d" , &ar[i][j]);
            }
        }
        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                temp[j] = ar[j][i];
                dp[j] = -1;
            }
            te[i] = call(0 , temp , n);
        }
        memset(dp , -1 , sizeof(dp));
        ans = call(0 , te , m);
        pf("%d\n" , ans);
    }
    return 0;
}
