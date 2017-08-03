#include <bits/stdc++.h>


#define sf scanf
#define pf printf
#define MAX 10000

using namespace std;


int t , cc = 0 , num[35];
int DP[30][30][30010];
int vis[30][30][30010];
set < int > se;

int call(int take , int pos , int sum)
{
    if(pos >= t)
    {
        if(take >= 2 && se.find(sum) != se.end()) return 1;
        return 0;
    }
    int &ret = DP[take][pos][sum];
    if(vis[take][pos][sum] == cc) return ret;
    ret = 0;
    ret = ret | call(take + 1 , pos + 1 , sum + num[pos]);
    ret = ret | call(take , pos + 1 , sum);
    vis[take][pos][sum] = cc;
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    int ans ;
    while(sf("%d" , &t) == 1)
    {
        pf("Case #%d:", ++cc);
        ans = 0;
        sf("%d" , &num[0]);
        pf(" %d", num[0]);
        for(int i = 1 ; i < t ; ++i)
        {
            sf("%d" , &num[i]);
            pf(" %d" , num[i]);
            if(num[i] <= num[i - 1]) ans = 1;
            if(se.find(num[i]) == se.end()) se.insert(num[i]);
            else ans = 1;
        }
        pf("\n");
        if(ans) pf("This is not an A-sequence.\n");
        else
        {
            ans = call(0 , 0 , 0);
            if(ans) pf("This is not an A-sequence.\n");
            else pf("This is an A-sequence.\n");
        }
        se.clear();
    }
    return 0;
}
