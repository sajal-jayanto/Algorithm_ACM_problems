#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf


int amount , can;

vector < int > ve[25];
int DP[25][250];

int call(int take , int sum)
{
    if(take >= can)
    {
        if(sum <= amount) return sum;
        return -(1 << 30);
    }
    int &ret = DP[take][sum];
    if(ret != -1) return ret;
    ret = -(1 << 30);
    for(int i = 0 ; i < ve[take].size() ; ++i) ret = max(ret , call(take + 1 , sum + ve[take][i]) );
    return ret;
}


int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , n , temp ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &amount , &can);
        for(int i = 0 ; i < can ; ++i)
        {
            ve[i].clear();
            sf("%d" , &n);
            while(n--)
            {
                sf("%d" , &temp);
                ve[i].push_back(temp);
            }
        }
        memset(DP , -1 , sizeof(DP));
        temp = call(0 , 0);
        if(temp == -(1 << 30)) pf("no solution\n");
        else pf("%d\n" , temp );
    }
    return 0;
}
