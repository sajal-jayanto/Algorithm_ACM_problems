#include <bits/stdc++.h>

using namespace std;

#define pf printf
#define sf scanf

int num[10010] , cc = 0;
int t , n , k , ans ;

int call(int x , int y , int cnt)
{
    if(x >= y) return cnt;
    if(cnt > k) return k + 2;
    int ret ;
    if(num[x] == num[y]) return ret = call(x + 1 , y - 1 , cnt);
    else ret = min(call(x + 1 , y , cnt + 1) , call(x , y - 1 , cnt + 1));
    return ret;
}

int main()
{
  //  freopen("input.txt" , "r" , stdin);
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &n , &k);
        for(int i = 0 ; i < n ; ++i) sf("%d" , &num[i]);
        ++cc;
        ans = call(0 , n - 1 , 0);
        if(ans == 0) pf("Case %d: Too easy\n" , cc) ;
        else if(ans > k) pf("Case %d: Too difficult\n" , cc);
        else pf("Case %d: %d\n" , cc , ans);
    }
    return 0;
}
